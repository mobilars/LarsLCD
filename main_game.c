/* 
* Copyright Lars Kristian Roland
*/

#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"

void drawFigure(int x, int y);
void clearFigure(int x, int y);

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  __delay_cycles(5000);
 
  SPISetup();                         // Initialize SPI Display
    
  clear();
  
  int x = 0;
  int y = 0;
  int dirx = 3;
  int diry = 1;
  
  while (1) {
      x += dirx;
      y += diry;
      drawFigure(x,y);
      __delay_cycles(200000);
      clearFigure(x,y);
      if (x >= 92 && dirx > 0) {
          dirx = -3;
      } 
      else if (x <= 0 && dirx < 0) {
          dirx = 3;
      } 
      if (y >= 7 && diry > 0) {
          diry = -1;
      } 
      else if (y <= 0 && diry < 0) {
          diry = 1;
      } 
  }
  
}

void drawFigure(int x, int y)
{
  if (x < 96 && y < 9) {
      setCursor(x, y);
      writeChar('#');
  }
}

void clearFigure(int x, int y)
{
  if (x < 96 && y < 9) {
      setCursor(x, y);
      writeChar(' ');
  }
}

