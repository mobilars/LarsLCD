
#include "../../hal_sense/CTS_Layer.h"
#include "../../hal_lcd/i2c_lib.h"
#include "../../hal_lcd/display.h"
#include "../../hal_lcd/charset.h"

// Uncomment to have this compiler directive run characterization functions only
// Comment to have this compiler directive run example application
//#define ELEMENT_CHARACTERIZATION_MODE	

#define DELAY 1000 		// Timer delay timeout count, 5000*0.1msec = 500 msec
// was 5000

struct Element * keyPressed;			// Pointer to the Element structure

#ifdef ELEMENT_CHARACTERIZATION_MODE
// Delta Counts returned from the API function for the sensor during characterization
unsigned int wheelCnt[5];				// Becuase the Wheel is composed of five elements
#endif

// Sleep Function
// Configures Timer A to run off ACLK, count in UP mode, places the CPU in LPM3 
// and enables the interrupt vector to jump to ISR upon timeout 
void sleep(unsigned int time)
{
    TA0CCR0 = time;
    TA0CTL = TASSEL_1+MC_1+TACLR;
    TA0CCTL0 &= ~CCIFG;
    TA0CCTL0 |= CCIE; 
    __bis_SR_register(LPM3_bits+GIE);
    __no_operation();
}

// Main Function
void main(void)
{ 
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  BCSCTL1 = CALBC1_16MHZ;                // Set DCO to 1, 8, 12 or 16MHz
  DCOCTL = CALDCO_16MHZ;
  BCSCTL1 |= DIVA_0;                    // ACLK/1 [ACLK/(0:1,1:2,2:4,3:8)]
  //BCSCTL2 |= DIVS_3;                    // SMCLK/8 [SMCLK/(0:1,1:2,2:4,3:8)]
  BCSCTL3 |= LFXT1S_2;                  // LFXT1 = VLO Clock Source
  
  P1OUT = BIT0;							// Drive all Port 1 pins low
  P1DIR = BIT0;							// Configure all Port 1 pins outputs
  
  //P2SEL &= ~(BIT6 + BIT7);				// Configure XIN (P2.6) and XOUT (P2.7) to GPIO
  //P2OUT = 0x00;						// Drive all Port 2 pins low
  P2DIR |= BIT0 | BIT1 | BIT4 | BIT5;			// Configure  Port 2 pins outputs

  // Initialize Baseline measurement
  //TI_CAPT_Init_Baseline(&wheel_buttons);
  TI_CAPT_Init_Baseline(&button_bar);
  
  // Update baseline measurement (Average 5 measurements)
  TI_CAPT_Update_Baseline(&button_bar,5);  
  
  init_display();
  drawBitmap(blackbird_96_64, 96, 8, 0, 0);    
  
  // Main loop starts here
  while (1)
  {
  	
  	#ifdef ELEMENT_CHARACTERIZATION_MODE
	// Get the raw delta counts for element characterization 
	TI_CAPT_Custom(&button_bar,wheelCnt);
	__no_operation(); 					// Set breakpoint here	
	#endif
	
	
	#ifndef ELEMENT_CHARACTERIZATION_MODE
	// Return the pointer to the element which has been touched
	keyPressed = (struct Element *)TI_CAPT_Buttons(&button_bar);
        //uint16_t e = TI_CAPT_Slider(&button_bar);
	
	// If a button has been touched, then take some action
	if(keyPressed)
	{
		// Up Element
		if(keyPressed == &up_element)
		{
			P1OUT |= BIT0;				// Turn on center LED
                        clear();
                        drawBitmap(big_2, 32, 6, 32, 1);
                        //write('2');
		}
		// Down Element
		if(keyPressed == &down_element)
		{
			P1OUT |= BIT0;				// Turn on center LED
                        clear();
                        drawBitmap(big_3, 32, 6, 32, 1);
                        //write('3');
		}
		// Left Element
		if(keyPressed == &left_element)
		{
			P1OUT |= BIT0;				// Turn on center LED
                        clear();
                        drawBitmap(big_1, 32, 6, 32, 1);
                        //write('1');
		}
		// Right Element
		if(keyPressed == &right_element)
		{
			P1OUT |= BIT0;				// Turn on center LED
                        clear();
                        drawBitmap(big_4, 32, 6, 32, 1);
                        //write('4');
		}		
	  }
	  else
	  {
	      P1OUT &= ~(BIT0);				// Turn off center LED
              drawBitmap(blackbird_96_64, 96, 8, 0, 0);  
	  }      
        
    // Put the MSP430 into LPM3 for a certain DELAY period
    sleep(DELAY);
    #endif

  }
} // End Main

/******************************************************************************/
// Timer0_A0 Interrupt Service Routine: Disables the timer and exists LPM3  
/******************************************************************************/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void ISR_Timer0_A0(void)
{
  TA0CTL &= ~(MC_1);
  TA0CCTL0 &= ~(CCIE);
  __bic_SR_register_on_exit(LPM3_bits+GIE);
}