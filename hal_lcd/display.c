
#include <msp430.h>
#include "display.h"
#include "i2c_lib.h"
#include "charset.h"

char DATA = 0x40;
char CMD = 0x00;

unsigned char height = 64;
unsigned char width = 96;

// Current cursor position...
unsigned char column;
unsigned char line; 


void init_display()
{
  init_i2c(0x78);
  
  P1DIR |= BIT4;
  
  // Reset the display
  P1OUT &= ~BIT4;
  delay();
  P1OUT |= BIT4;  
  
  send(CMD, 0x21); // extended instruction set control (H=1)
  send(CMD, 0x13); // bias system (1:48)
  //send(CMD, 0xE0); 
  send(CMD, 0xB0); // VOP level 
  //send(CMD, 0x29); // partial display mode
  send(CMD, 0x28); // full display mode
  //send(CMD, 0x39); // part 1
  send(CMD, 0x20);
  send(CMD, 0x09); // all display segments on
  send(CMD,0x0c);  // normal mode (0x0d = inverse mode)
  //send(CMD, 0x0d); // reverse mode
  send(CMD, 0x11); // VOP range high
  send(CMD, 0x80);
  send(CMD, 0x40);
}




void send(char config, char data)
{
  char d[2];
  d[0] = config;
  d[1] = data;
  Master_Transmit(d, 2);
}

void clear()
{
  setCursor(0, 0);
  char d[21];
  d[0] = DATA;
  
  for (int x = 1; x < 21; x++) {
    d[x] = 0;
  }
  
  for (int i = 0; i < 40; i++) {
    Master_Transmit(d, 21);
  }
  setCursor(0, 0);
}

void clearLine()
{
  setCursor(0, line);
  for (unsigned char i = 0; i < width; i++) {
    send(DATA, 0x00);
  }
  setCursor(0, line);
}

void setInverse(char inverse)
{
  send(CMD, inverse ? 0x0d : 0x0c);
}


void home()
{
  setCursor(0, line);
}


void setCursor(unsigned char column, unsigned char line)
{
  column = (column % width);
  //line = (line % (height/9 + 1));
  line = (line % 8);
  
  send(CMD, 0x80 | column);
  send(CMD, 0x40 | line); 
}

void write(unsigned char chr)
{
  // ASCII 7-bit only...
  if (chr >= 0x80) {
    return;
  }
  
  // Output one column at a time...
  char d[6];
  d[0] = DATA;
  d[1] = charset[chr - ' '][0];
  d[2] = charset[chr - ' '][1];
  d[3] = charset[chr - ' '][2];
  d[4] = charset[chr - ' '][3];
  d[5] = charset[chr - ' '][4];
  Master_Transmit(d, 6);
  
  // One column between characters...
  send(DATA, 0x00);
  
  // Update the cursor position...
  column = (column + 6) % width;
  
  if (column == 0) {
    line = (line + 1) % (height/9 + 1);
  }
}

//

void drawBitmap(const unsigned char *data, unsigned char mx, unsigned char my, char xpos, char ypos)
{
  //unsigned char scolumn = column;

  
  // Todo: This could be made more efficient by sending > 1 byte per send
  // The overhead in send is 2 extra bytes, so better to send many in one
  for (unsigned char y = 0; y < my; y++) {
    setCursor(xpos, y + ypos);
    
    for (unsigned char x = 0; x < mx; x++) {
      send(DATA, data[y * mx + x]);
    }
  }
  
  // Leave the cursor in a consistent position...
  setCursor(0, 0);
}


void writeMegaFont(char xpos, char ypos, char ch)
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
  
  char d[17];
  d[0] = DATA;
  
  for(i=0;i<3;i++)
  {	
    setCursor(xpos*12+6, i + ypos*3+1);   
    for(j=0; j<16; j++) {
      //send(DATA,number[ch][i][j]);
      d[j+1] = number[ch][i][j];
    }
    Master_Transmit(d, 17);
  } 
  
  //	if(ch == '.') 
  //		char_start += 5;
  //	else
  //		char_start += 12;
}
