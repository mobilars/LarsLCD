// Within the application layer source code file: main.c
#include "../../hal_sense/CTS_Layer.h"
// Delta Counts returned from the API function for the sensor during characterization
unsigned int dCnt;
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
BCSCTL3 |= LFXT1S_2; // LFXT1 = VLO Clock Source
P1OUT = 0x00; // Drive all Port 1 pins low
P2DIR = 0xFF; // Configure all Port 2 pins outputs
// Initialize Baseline measurement
TI_CAPT_Init_Baseline (&up_element,5);
while (1)
{
// Get the raw delta counts for element characterization
TI_CAPT_Custom(&one_button,&dCnt);
__no_operation(); // Set breakpoint here
}
}