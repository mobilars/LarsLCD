//******************************************************************************
// structure.c
//
// RO_PINOSC_TA0_WDTp_Wheel_Buttons example
// Touch the five wheel buttons to turn on/off the center button LED
// RO method capactiance measurement using PinOsc IO, TimerA0, and WDT+
//
//  threshold and maxResponse values must be updated for electrode design,
//  system clock settings, selection of gate measurement source, and 
//  accumulation cycles
//******************************************************************************

#include "structure.h"

// Up Element (P2.4)
const struct Element up_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT0,
              // When using an abstracted function to measure the element
              // the 100*(maxResponse - threshold) < 0xFFFF
              // ie maxResponse - threshold < 655
              .maxResponse = 3000, //was 100+655,	
              .threshold = 1000
};

// Left Element (P2.1)
const struct Element left_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT1,
              // When using an abstracted function to measure the element
              // the 100*(maxResponse - threshold) < 0xFFFF
              // ie maxResponse - threshold < 655
              .maxResponse = 3000, //was 100+655,	
              .threshold = 1000 // was 100
};

// Right Element (P2.3)
const struct Element right_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT4,
              // When using an abstracted function to measure the element
              // the 100*(maxResponse - threshold) < 0xFFFF
              // ie maxResponse - threshold < 655
              .maxResponse = 3000, //was 100+655,
              .threshold = 1000 // was 100
};

// Down Element (P2.2)
const struct Element down_element = {

              .inputPxselRegister = (unsigned char *)&P2SEL,  
              .inputPxsel2Register = (unsigned char *)&P2SEL2,  
              .inputBits = BIT5,
              // When using an abstracted function to measure the element
              // the 100*(maxResponse - threshold) < 0xFFFF
              // ie maxResponse - threshold < 655
              .maxResponse = 3000, //was 100+655,		
              .threshold = 1000 // was 100
};

//*** CAP TOUCH HANDLER *******************************************************/
// This defines the grouping of sensors, the method to measure change in
// capacitance, and the function of the group

//PinOsc Wheel
//const struct Sensor wheel_buttons =
const struct Sensor button_bar =
               { 
                  .halDefinition = RO_PINOSC_TA0_WDTp,
                  .numElements = 4,
                  .baseOffset = 0,
                  // Pointer to elements
                  .arrayPtr[0] = &left_element,  			// point to up element
                  .arrayPtr[1] = &up_element,  		// point to down element
                  .arrayPtr[2] = &down_element,  		// point to left element
                  .arrayPtr[3] = &right_element,  		// point to right element
                  // Timer Information
                  .measGateSource= GATE_WDT_ACLK,     //  0->SMCLK, 1-> ACLK
                  .accumulationCycles= WDTp_GATE_64   //64 - Default                                  
               };                          
