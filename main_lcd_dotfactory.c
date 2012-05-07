/* 
* Copyright Lars Kristian Roland
* Fonts created using http://www.pavius.net/2009/07/the-dot-factory-an-lcd-font-and-image-generator/
* Thanks to CorB for finding the link. 
*/

#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"
#include "dotfactory.h"

void clearlast(int last);

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  __delay_cycles(5000);
 
  SPISetup();                         // Initialize SPI Display
    
  clear();
  

  //writeSansSerif(0,0,'1');
  writeSansSerifString(0,0,"01234");
  writeSansSerifString(0,1,"56789");
  writeJingJingString(0,2,"123456789");
  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled
  
}

void clearlast(int last)
{
  if (last == 0) {
    clear();
  }
}