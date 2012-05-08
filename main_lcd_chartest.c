/*
* Author: Cor Berrevoets
*/

#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL  = CALDCO_1MHZ;

  __delay_cycles(50000);

  SPISetup();                         // Initialize SPI Display

  clear();

  // Set button input for DIP board
  P1DIR &= ~(BIT0 | BIT1);
  P2DIR &= ~(BIT1 | BIT2);
  P1REN |= BIT0 | BIT1 | BIT2;
  P2REN |= BIT1 | BIT2;
  P1OUT |= BIT0 | BIT1 | BIT2;
  P2OUT |= BIT1 | BIT2;

  while (1) {

          setcharmode(1); //normal chars

          setCursor(0, 0);
          writeString(0,0,"abcdefgh");
          writeString(0,1,"ijklmnop");
          writeString(0,2,"qrstuvwx");
          writeString(0,3,"yz");

          setcharmode(0); //largechars
          writeString(0,4,"0123");
          writeString(0,6,"4567");

      }
 }



