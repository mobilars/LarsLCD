/* 
* Copyright Lars Kristian Roland
*/

#include <msp430.h>
#include "lcd.h"
#include "lcd_charset.h"
#include "CTS_Layer.h"

#define TOUCH

int runGame();
void gameOver();
void delay(int x);
void drawFigure(int x, int y);
void clearFigure(int x, int y);
void setupButtons();
int getButton();
void drawBar(int bar);

int x;
int y;
int dirx;
int diry;
      
void main (void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  
    __delay_cycles(5000);
   
    setupButtons();
    SPISetup();                         // Initialize SPI Display
    
    while (1) {
        clear();
        x = 0;
        y = 0;
        dirx = 3;
        diry = 1;
        while (runGame() == 1);
        gameOver();
        delay(100);
    }
}

int runGame()
{
    
    x += dirx;
    y += diry;
    
    int button = getButton();
    
    drawFigure(x,y);
    drawBar(button);
    delay(10);
    clearFigure(x,y);
    
    if (x >= 88 && dirx > 0) {
        dirx = -3;
    } 
    else if (x <= 0 && dirx < 0) {
        dirx = 3;
    } 
    if (y >= 7 && diry > 0) {
        diry = -1;
        // Game over
        if (x > button*24 || (x < button-1*24)) return 0;
    } 
    else if (y <= 0 && diry < 0) {
        diry = 1;
    } 
    
    return 1;
}

void gameOver()
{
    clear();
    setCursor(0, 3);
    writeString("   GAME OVER    ");
}

void delay(int x)
{
  while (x-- > 0) { 
      __delay_cycles(300000);  
  }
}

void drawBar(int bar)
{
  if (bar == 0) {
      setCursor(0, 7);
      writeString("                ");
  }
  else {
      setCursor(0, 7);
      writeString("                ");
      setCursor((bar-1)*24, 7);
      for (int i = 0; i < 24; i++) {
          SPIWrite(DATA, 0xFF); 
      }
  }
}

void drawFigure(int x, int y)
{
  if (x < 90 && y < 9) {
      setCursor(x, y);
      for (int i = 0; i < 5; i++) {
          //SPIWrite(DATA, 0xFF); 
          SPIWrite(DATA, ball[i]); 
      }
      for (int i = 0; i < 5; i++) {
          SPIWrite(DATA, ball[4-i]); 
      }
  }
}

void clearFigure(int x, int y)
{
  if (x < 96 && y < 9) {
      setCursor(x, y);
      //writeChar('  ');
      for (int i = 0; i < 10; i++) {
          SPIWrite(DATA, 0x00); 
      }
  }
}

#ifdef TOUCH

void setupButtons()
{
    WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  BCSCTL1 = CALBC1_16MHZ;               // Set DCO to 1, 8, 12 or 16MHz
  DCOCTL = CALDCO_16MHZ;
  BCSCTL1 |= DIVA_0;                    // ACLK/1 [ACLK/(0:1,1:2,2:4,3:8)]
  //BCSCTL2 |= DIVS_3;                  // SMCLK/8 [SMCLK/(0:1,1:2,2:4,3:8)]
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO Clock Source
  
  P1OUT |= BIT0;				// P1.0 out
  P1DIR |= BIT0;				// P1.0 high
  
  P2DIR |= BIT0 | BIT1 | BIT4 | BIT5;			// Configure  Port 2 pins outputs

  // Initialize Baseline measurement
  TI_CAPT_Init_Baseline(&button_bar);
  
  // Update baseline measurement (Average 5 measurements)
  TI_CAPT_Update_Baseline(&button_bar,5);  
}

struct Element * keyPressed;	
int getButton()
{

  keyPressed = (struct Element *)TI_CAPT_Buttons(&button_bar);
  if(keyPressed) {
      if(keyPressed == &a_element) {
          return 1;
      }
      else if(keyPressed == &b_element) {
          return 2;
      }
      else if(keyPressed == &c_element) {
          return 3;
      }
      else if(keyPressed == &d_element) {
          return 4;
      }
  }
  return 0;

}
#endif
