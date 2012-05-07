#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"

unsigned char height = 64;
unsigned char width = 96;

// Current cursor position...
unsigned char column;
unsigned char line; 

#define CSB_PIN BIT4
//#define RESB_PIN BIT1
#define MOSI_PIN BIT7
#define SCLK_PIN BIT5

#define CSB_LOW P1OUT &= ~CSB_PIN
#define CSB_HIGH P1OUT |= CSB_PIN
#define SCLK_LOW P1OUT &= ~SCLK_PIN
#define SCLK_HIGH P1OUT |= SCLK_PIN
#define RESB_LOW P1OUT &= ~RESB_PIN
#define RESB_HIGH P1OUT |= RESB_PIN
#define MOSI_LOW P1OUT &= ~MOSI_PIN
#define MOSI_HIGH P1OUT |= MOSI_PIN
#define DELAY __delay_cycles(10)


//******************************************************************************
// Support for  USCI_B0
//******************************************************************************

// Remove this to use bitbanging (if the chip doesn't have USCI or other reason)
#define USCI

#ifdef UCB0CTL0_

void SPISetup(void)
{
  // Reset (not necessary when hw reset implemented on board)
  //P1DIR |= RESB_PIN;
  //P1OUT &= ~(RESB_PIN);
  __delay_cycles(10000);
  //P1OUT |= RESB_PIN;
  __delay_cycles(10000);
  
  P1OUT |= CSB_PIN;
  P1DIR |= CSB_PIN;         // /CS disable
  
  UCB0CTL1 |= UCSWRST;                      // **Disable USCI state machine**
  UCB0CTL0 |= UCMST+UCCKPH+UCMSB+UCSYNC;    // 3-pin, 8-bit SPI master
  UCB0CTL1 |= UCSSEL_2;                     // SMCLK
  UCB0BR0 = 0x02;                           // UCLK/2
  UCB0BR1 = 0;

  
  P1SEL |= MOSI_PIN
                         | BIT6
                         | SCLK_PIN;
  
  P1SEL2 |= MOSI_PIN
                         | BIT6
                         | SCLK_PIN;
    
                                            // SPI option select
  P1DIR |= MOSI_PIN | SCLK_PIN;
                                            // SPI TXD out direction
  UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  
  SPIWrite(CMD, 0x21);  //Function set PD=0,H1=0,H0=1
  SPIWrite(CMD, 0x10+0x03);  //SET Bias system
  //SPIWrite(CMD, 0X80+0x29);  //SET V0
  SPIWrite(CMD, 0X80+0x20);  //SET V0
  SPIWrite(CMD, 0x20);  //Function set PD=0 ,H1=0, H0=0
  SPIWrite(CMD, 0x05);  //Set VLCD Range(PRS) 0x04 = VLo-low, 0x05 VO-high
  SPIWrite(CMD, 0x0C);  //Display control D=1 E=0 (Normal) 0x0C = normal display
  SPIWrite(CMD, 0x40);  //Set X , Y address 0x4Y EG 0x40
  SPIWrite(CMD, 0x80);  //Set X -> 0x80 + x = 0b1xxx xxxx
  SPIWrite(CMD, 0x28);  //Function set PD=0,H1=0,H0=0 reverse directions
  
}

void partial()
{
  // Doesn't work. 
  SPIWrite(CMD, 0x21);  //Function set PD=0,H1=0,H0=1
  SPIWrite(CMD, 0x10+0x00);  //SET Bias system
  SPIWrite(CMD, 0X80+0x30);  //SET V0
  
  SPIWrite(CMD, 0x20);  //Function set PD=0,H1=0,H0=0
  SPIWrite(CMD, 0x05);  // 101 Partial display enable  
  SPIWrite(CMD, 0x09);  // 1001 Partial display size
  //SPIWrite(CMD, 0x08);  // 1000 Partial display size
  SPIWrite(CMD, 0x10 + 0x00);  // Where to start
  SPIWrite(CMD, 0x80 + 0x00);  // Vop
  //SPIWrite(CMD, 0x28);  //Function set PD=0,H1=0,H0=0 reverse directions
}

// HW SPI write
void SPIWrite(char addr, char value)
{   
  char first = (addr << 7) | (value >> 1);
  char second = (value << 7);
  
  P1OUT &= ~CSB_PIN;        // /CS enable
  while (!(IFG2&UCB0TXIFG));                // Wait for TXBUF ready
  UCB0TXBUF = first;                         // Send address
  while (!(IFG2&UCB0TXIFG));                // Wait for TXBUF ready
  UCB0TXBUF = second;                        // Send data
  while (UCB0STAT & UCBUSY);                // Wait for TX to complete
  P1OUT |= CSB_PIN;         // /CS disable
}


#else 
// Bit banging setup code
#warning Bitbanging SPI used

void SPISetup(void)
{
  P1OUT |= CSB_PIN |  MOSI_PIN | SCLK_PIN;  
  P1DIR |= CSB_PIN |  MOSI_PIN | SCLK_PIN;         // /CS disable

  P1OUT &= ~( CSB_PIN | SCLK_PIN);
  __delay_cycles(10000);
  
  __delay_cycles(10000);
  
  
  SPIWrite(CMD, 0x21);  //Function set PD=0,H1=0,H0=1
  SPIWrite(CMD, 0x10+0x03);  //SET Bias system
  SPIWrite(CMD, 0X80+0x29);  //SET V0
  SPIWrite(CMD, 0x20);  //Function set PD=0 ,H1=0, H0=0
  SPIWrite(CMD, 0x05);  //Set VLCD Range(PRS) 0x04 = VLo-low, 0x05 VO-high
  SPIWrite(CMD, 0x0C);  //Display control D=1 E=0 (Normal) 0x0C = normal display
  SPIWrite(CMD, 0x40);  //Set X , Y address 0x4Y EG 0x40
  SPIWrite(CMD, 0x80);  //Set X -> 0x80 + x = 0b1xxx xxxx
  SPIWrite(CMD, 0x28);  //Function set PD=0,H1=0,H0=0 reverse directions
  //SPIWrite(CMD, 0x38);  //Function set PD=0,H1=0,H0=0 reverse directions

}

// Bitbanging code
void SPIWrite(char conf, char value)
{
  CSB_LOW;        // /CS enable
  
  if (conf) {
      P1OUT &= ~SCLK_PIN;
      P1OUT |= MOSI_PIN;
  }
  else {
      P1OUT &= ~(SCLK_PIN | MOSI_PIN);
  }
  P1OUT |= SCLK_PIN;
  
  int mask = 0x0080;
  while((mask & 0xFF)) {
      if(value & mask) {
          P1OUT &= ~SCLK_PIN;
          P1OUT |= MOSI_PIN;
      } else {
          P1OUT &= ~(SCLK_PIN | MOSI_PIN);
      }
      P1OUT |= SCLK_PIN;
      mask >>= 1;
  }
  
  CSB_HIGH;         // /CS disable
  
}

#endif

/*
void writeCharFullCharset(unsigned char c)
{

  for (int i = 0; i < 5; i++) {
      SPIWrite(DATA, font_5_8[c][i]);
  }
  
  // One column between characters...
  SPIWrite(DATA, 0x00);
    
}
*/

void writeChar(unsigned char chr)
{
  // ASCII 7-bit only...
  if (chr >= 0x80) {
    return;
  }
  
  // Output one column at a time...
  char d[6];
  d[0] = charset[chr - ' '][0];
  d[1] = charset[chr - ' '][1];
  d[2] = charset[chr - ' '][2];
  d[3] = charset[chr - ' '][3];
  d[4] = charset[chr - ' '][4];
  
  for (int i = 0; i < 5; i++) {
      SPIWrite(DATA, d[i]);
  }
  
  // One column between characters...
  SPIWrite(DATA, 0x00);
  
}

void clear()
{
  int i;
  
  setCursor(0, 0);

  for (i = 0; i < 9; i++) {
      setCursor(0, i);
      for (unsigned char j = 0; j < width; j++) 
      {
          SPIWrite(DATA, 0x00);
      }
  }
  setCursor(0, 0);
}

void setCursor(unsigned char column, unsigned char line)
{
  column = (column % width);
  line = (line % 8);
  
  SPIWrite(CMD, 0x80 | column);
  SPIWrite(CMD, 0x40 | line); 
}

void writeString(char * str)
{
  int i;
  
  for (i = 0; i < 100; i++) {
    if (str[i] == '\0') break;
    writeChar(str[i]);
  }

}

void writeMegaNumber(char xpos, char ypos, char ch)
{
  unsigned char i, j;
  
  if(ch == '.')
    ch = 10;
  else if (ch == '+')
    ch = 11;
  else if (ch == '-')
    ch = 12;
  else
    ch = ch & 0x0f;
  
  for(i=0;i<3;i++)
  {	
    setCursor(xpos, i + ypos);   
    for(j=0; j<16; j++) {
      SPIWrite(DATA,number[ch][i][j]);
    }
  } 
}

void drawBitmap(const unsigned char *data, unsigned char mx, unsigned char my, char xpos, char ypos)
{
  //unsigned char scolumn = column;

  
  // Todo: This could be made more efficient by sending > 1 byte per send
  // The overhead in send is 2 extra bytes, so better to send many in one
  for (unsigned char y = 0; y < my; y++) {
    setCursor(xpos, y + ypos);
    
    for (unsigned char x = 0; x < mx; x++) {
      SPIWrite(DATA, data[y * mx + x]);
    }
  }
  
  // Leave the cursor in a consistent position...
  setCursor(0, 0);
}

/*
void SPISetup(void)
{
  P1OUT |= CSB_PIN | RESB_PIN | SIMO_PIN | SCLK_PIN;
  P1DIR |= CSB_PIN | RESB_PIN | SIMO_PIN | SCLK_PIN;         // /CS disable

  P1OUT &= ~(RESB_PIN | CSB_PIN);
  delay_cycles(10000);
  P1OUT |= RESB_PIN;
  
  UCB0CTL1 |= UCSWRST;                      // **Disable USCI state machine**
  UCB0CTL0 |= UCMST+UCCKPH+UCMSB+UCSYNC;    // 3-pin, 8-bit SPI master
  UCB0CTL1 |= UCSSEL_2;                     // SMCLK
  UCB0BR0 = 0x02;                           // UCLK/2
  UCB0BR1 = 0;
  
  P1SEL |= SIMO_PIN | SCLK_PIN;
  
  P1SEL2 |= SIMO_PIN | SCLK_PIN;
                                            // SPI TXD out direction
  UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
}

void SPIWrite(char char value)
{
  P1OUT &= ~CSB_PIN;        // /CS enable
  while (!(IFG2&UCB0TXIFG));                // Wait for TXBUF ready
  UCB0TXBUF = value;                         // Send value
  while (!(IFG2&UCB0TXIFG));                // Wait for TXBUF ready
  while (UCB0STAT & UCBUSY);                // Wait for TX to complete
  P1OUT |= CSB_PIN;         // /CS disable
}
*/
/*
void WriteBurst(char *buffer, char count)
{
  unsigned int i;

  TI_CC_CSn_PxOUT &= ~TI_CC_CSn_PIN;        // /CS enable
  while (!(IFG2&UCB0TXIFG));                // Wait for TXBUF ready
  UCB0TXBUF = addr | TI_CCxxx0_WRITE_BURST; // Send address
  for (i = 0; i < count; i++)
  {
    while (!(IFG2&UCB0TXIFG));              // Wait for TXBUF ready
    UCB0TXBUF = buffer[i];                  // Send data
  }
  while (UCB0STAT & UCBUSY);                // Wait for TX to complete
  TI_CC_CSn_PxOUT |= TI_CC_CSn_PIN;         // /CS disable
}
*/