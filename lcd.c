/*
* License: BSD
* Contributors: Lars Roland (first version), 
*               Cor Berrevoets (font sizes and screen orientation)
*/

#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"

#define uselargechar 0
#define usescreenrotate 1

unsigned char pixelmode=1; // 1= setpixels; 0 =clrpixels;
unsigned char normalchar=1; // 1=normalchar 0=largechar;
unsigned char rotatedscreen=1 ; //1= rotation 0=not rotated;

unsigned char height = 64; //screen dimensions
unsigned char width = 96;

// Current cursor position...
unsigned char column;
unsigned char line;

//Port 1 p1.4 p1.5, p1.6 (unnamed), p1.7 used for LCD
#define CSB_PIN BIT4  //bit4=chipselect
#define MOSI_PIN BIT7

#define SCLK_PIN BIT5

#define CSB_LOW P1OUT &= ~CSB_PIN
#define CSB_HIGH P1OUT |= CSB_PIN
#define SCLK_LOW P1OUT &= ~SCLK_PIN
#define SCLK_HIGH P1OUT |= SCLK_PIN
//#define RESB_LOW P1OUT &= ~RESB_PIN
//#define RESB_HIGH P1OUT |= RESB_PIN
#define MOSI_LOW P1OUT &= ~MOSI_PIN
#define MOSI_HIGH P1OUT |= MOSI_PIN
#define DELAY __delay_cycles(10)

// Uses bitbanging if no USCI
#ifdef UCB0CTL0_


//******************************************************************************
// Support for  USCI_B0
//******************************************************************************

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
    
    P1SEL  |= MOSI_PIN     | BIT6            | SCLK_PIN;    
    P1SEL2 |= MOSI_PIN     | BIT6            | SCLK_PIN;
    
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
    SPIWrite(CMD, 0x0C);  //Display control D=1 E=0 (Normal) 0x0C = normal display 0x0D = reversed
    
    SPIWrite(CMD, 0x40);  //Set Y startingline BIT6    line0=0x40
    SPIWrite(CMD, 0x80);  //Set y startingline BIT5-0  line0=0x80
    
    SPIWrite(CMD, 0x28);  //Function set PD=0,H1=0,H0=0 reverse directions
    
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

void setcharmode(char mode) //0=normal; 1= large;
{
    normalchar=mode;
}

void setscreenmode(char mode) //0= normal; 1=rotated;
{
    rotatedscreen=mode;
}


void setpixelmode(char mode) //1= ON
{
    pixelmode=mode;
}

void setpixel(char x, char y)
{
    if (rotatedscreen)  //swap X-Y
    { char temp;
    temp=x;
    x=y;
    y=temp;
    }
    
    setCursor(x,y/8);
    SPIWrite(DATA,1<< y%8);
    
}


void writeChar(char x, char y, unsigned char chr)
{
    if (chr >= 0x80) {
        return;
    }
    
    //position bytepointer
    setCursor(x,y);
    int i;
    
#if usescreenrotate==0
    if (normalchar)
    {
        chr=chr-' ';  // full characterset
        for (i = 0; i < 5; i++) {
            SPIWrite(DATA, charset[chr][i]);
        }
        SPIWrite(DATA, 0x00);
        
    }
    
#if uselargechar==1
    else
    {
        chr=chr-'0'; // charactersetbased on '0'
        for (i = 0; i < 11; i++) { //write tophalf
            SPIWrite(DATA, numchar[chr][i]);
        }
        
        setCursor(x,y+1);
        for (i = 0; i < 11; i++) { //write bottomhalf
            SPIWrite(DATA, numchar[chr][i+11]);
        }
        
        SPIWrite(DATA, 0x00);
        
    }
#endif
#endif
    
    
#if usescreenrotate==1
    if (normalchar)
    {
        chr=chr-' ';  // full characterset from spacecharacter
        setCursor(80-y*8,x); //section leftdown
        for (i = 0; i < 8; i++) {
            SPIWrite(DATA, charsetR[chr][7-i]);
        }
    }
    
#if uselargechar==1
    else //largechar
    {
        chr = chr-'0'; // only numbers
        setCursor(80-y*8,x); //section leftdown
        for (i = 0; i < 8; i++) {
            SPIWrite(DATA, numcharR[chr][i*2]);
        }
        
        setCursor(88-y*8,x); //section leftup
        for (i = 1; i < 8; i++) {
            SPIWrite(DATA, numcharR[chr][i*2+14]);
        }
        
        setCursor(80-y*8,x+1); // section rightdown
        for (i = 0; i < 8; i++) {
            SPIWrite(DATA, numcharR[chr][i*2+1]);
        }
        setCursor(88-y*8,x+1); // section rightup
        for (i = 1; i < 8; i++) {
            SPIWrite(DATA, numcharR[chr][i*2+15]);
        }
    }
#endif
    
    
#endif
    
}

void writeHex (char x,char y,const unsigned char out) {
    unsigned char temp;
    temp = out >> 4;
    temp += (temp > 9) ? 'A' - 10 : '0';
    writeChar (x,y,temp);
    temp = out & 0x0f;
    temp += (temp > 9) ? 'A' - 10 : '0';
    writeChar (x,y,temp);
}

void writeInt (char x, char y, const unsigned int out, unsigned int precision)
{
    unsigned int temp1;
    unsigned char temp2, i;
    char decBuffer[] = {0,0,0,0,0,0,0};
    char decFill = '0';
    
    if (precision > 6) {           // sanity check
        writeChar(x,y,'X');
        return;
    }
    temp1 = out;
    i = 5;
    do {                                // at least once
        temp2 = temp1 % 10;               // bust a digit off the low order end
        decBuffer[i--] = temp2 + '0';     // stick it in the buffer
        temp1 /= 10;                      // shift the whole mess to the right
    } while (temp1);                    // just so long as there's some left
    while (i >= (6 - precision)) decBuffer[i--] = decFill;
    i++;                                // went too far
    writeString (x,y, &decBuffer[i]);
    
}


void clear()
{
    // Todo implement burst mode for SW I2C
    setCursor(0, 0);
    int i,j;
    for (i = 0; i < 9; i++) {
        setCursor(0, i);
        for ( j = 0; j < width; j++)
        {
            SPIWrite(DATA, 0x00);
        }
    }
    setCursor(0, 0);
}

void setCursor(unsigned char column, unsigned char line) // position in pixels to the LCD-writeposition at a byte
{
    column = (column % width);
    //line = (line % (height/9 + 1));
    line = (line %8);
    SPIWrite(CMD, 0x80 | column);
    SPIWrite(CMD, 0x40 | line);
    
}

void writeString(char x, char y, char * str)
{ 
    int i;
    
    for ( i = 0; i < 100; i++) {
        if (str[i] == '\0') break;
        writeChar(x,y, str[i]);
#if  usescreenrotate==0
        {if (normalchar)
        {x=x+6;}
        else
        { x=x+16;
        }
        }
#endif
#if usescreenrotate==1
        if (rotatedscreen==1)
        { if (normalchar)
        { x=x+1;
        }
        else
        {
            x=x+2;
        }
        }
#endif
        
    }
}



void drawBitmap(const unsigned char *data, unsigned char mx, unsigned char my, char xpos, char ypos)
{
    //unsigned char scolumn = column;
    
    
    // Todo: This could be made more efficient by sending > 1 byte per send
    // The overhead in send is 2 extra bytes, so better to send many in one
    
    int x,y;
    for ( y = 0; y < my; y++) {
        setCursor(xpos, y + ypos);
        
        for ( x = 0; x < mx; x++) {
            SPIWrite(DATA, data[y * mx + x]);
        }
    }
    
    // Leave the cursor in a consistent position...
    setCursor(0, 0);
}
