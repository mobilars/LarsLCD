/* 
* Copyright Lars Kristian Roland
*/

#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"

void clearlast(int last);

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  __delay_cycles(5000);
 
  SPISetup();                         // Initialize SPI Display
    
  clear();
  
  //drawBitmap(blackbird_96_64, 96, 8, 0,0);
  
  // Set button input for DIP board
  P1DIR &= ~(BIT0 | BIT1);
  P2DIR &= ~(BIT1 | BIT2);
  P1REN |= BIT0 | BIT1 | BIT2;
  P2REN |= BIT1 | BIT2;
  P1OUT |= BIT0 | BIT1 | BIT2;
  P2OUT |= BIT1 | BIT2;
  
  int last = 99;
  
  while (1) {
    if ((P1IN & BIT0) == 0x00) {
        clearlast(last);
        last = 1;
        writeString(0,0,"   Pressed 1    ");
        drawBitmap(big_1, 32, 6, 32, 1);
    }
    else if ((P1IN & BIT1) == 0x00) {
        clearlast(last);
        last = 2;
        writeString(0,0,"   Pressed 2    ");
        drawBitmap(big_2, 32, 6, 32, 1);
    }
    else if ((P2IN & BIT1) == 0x00) {
        clearlast(last);
        last = 3;
        writeString(0,0,"   Pressed 3    ");
        drawBitmap(big_3, 32, 6, 32, 1);
    }
    else if ((P2IN & BIT2) == 0x00) {
        clearlast(last);
        last = 4;
        writeString(0,0,"   Pressed 4    ");
        drawBitmap(big_4, 32, 6, 32, 1);
    }
    else {
        if (last != 0) {
          clear();
          //drawBitmap(logo43oh, 96, 4, 0, 2);
          drawBitmap(blackbird_96_64, 96, 8, 0,0);
        }
        last = 0;
        writeString(0,0," Press a button ");
    }
  }
  
  //__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled
  
}

void clearlast(int last)
{
  if (last == 0) {
    clear();
  }
}