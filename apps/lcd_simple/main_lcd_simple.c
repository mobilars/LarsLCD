
#include <msp430.h>

#include "../../hal_lcd/charset.h"
#include "../../hal_lcd/display.h"
#include "../../hal_lcd/i2c_lib.h"


int main()
{
  
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog
  if (CALBC1_1MHZ == 0xFF || CALDCO_1MHZ == 0xFF)                                     
  {  
    while(1);                               // If calibration constants erased
                                            // do not load, trap CPU!!
  } 
  BCSCTL1 = CALBC1_16MHZ;                    // Set DCO
  DCOCTL = CALDCO_16MHZ;
    
  init_display();
  while (1) {
    drawBitmap(blackbird_96_64, 96, 8, 0,0);
    long_delay();
    clear();
    long_delay();
    drawBitmap(big_9, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_8, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_7, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_6, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_5, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_4, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_3, 32, 6, 32, 1);
    long_delay();
    drawBitmap(big_2, 32, 6, 32, 1);
    long_delay();
    //drawBitmap(big_1, 32, 6, 32, 1);
    long_delay();
    clear();
    drawBitmap(change, 32, 4, 32, 2);
    long_delay();
  }
}


//int main_x() {
//  
//  init_display();
//  
//  while (1) {
//    clear();
//    
//    drawBitmap(blackbird_96_64, 96, 64, 0,0);
//    long_delay();
//    clear();
//
//    drawBitmap(big_1, 50, 50, 0, 0);
//    long_delay();
//    clear();
//    
//    for (int y = 0; y < 2; y++) {
//      for (int x = 0; x < 7; x++) {
//        writeMegaFont(x, y,'0'+x);
//      }
//    }
//    long_delay();
//    long_delay();
//    
//    clear();
//    for (int i = 0; i < 8; i++) {
//      //clearLine();
//      write('0'+i);
//      write(' ');
//      write('0');
//      write('1');
//      write('2');
//      write('3');
//      write('4');
//      write('5');
//      write('6');
//      write('7');
//      write('8');
//      write('9');
//      //delay();
//      setCursor(0, i+1);
//      //delay();
//    }
//    
//    long_delay();
//    
//  }
//  //    long_delay();
//  //    setInverse(1);
//  //    long_delay();
//  //    setInverse(0);
//  
//  
//  //_BIS_SR(LPM4_bits); // Nothing else to do, enter Low Power Mode 4
//}

