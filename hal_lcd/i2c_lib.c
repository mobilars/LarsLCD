

#include <msp430.h>
#include "i2c_lib.h"

#define number_of_TX_bytes 1                // How many bytes do you want to TX?   
#define number_of_RX_bytes 3                // How many bytes do you want to RX?


int reading[5];
int reading_count = 0;

char MST_Data[21];                       // Variable for transmitted data
int sent_index = 0;
char SLV_Addr = 0x42;                       
int I2C_State, Bytecount, Transmit, number_of_bytes, repeated_start = 0;     
void Data_TX (void);
void Data_RX (void);

void init_i2c(int slave_address)
{
  volatile unsigned int i;                  // Use volatile to prevent removal
  
  P1OUT = BIT6 | BIT7; //0xC0;                             // P1.6 & P1.7 Pullups, others to 0
  P1REN |= BIT6 | BIT7; //0xC0;                            // P1.6 & P1.7 Pullups
  
  SLV_Addr = slave_address;
    
}


/******************************************************
// USI interrupt service routine
// Data Transmit : state 0 -> 2 -> 4 -> 10 -> 12 -> 14
// Data Recieve  : state 0 -> 2 -> 4 -> 6 -> 8 -> 14
******************************************************/
#pragma vector = USI_VECTOR
__interrupt void USI_TXRX (void)
{
  switch(__even_in_range(I2C_State,14))
    {
      case 0: // Generate Start Condition & send address to slave
              //P1OUT |= 0x01;                // LED on: sequence start
              Bytecount = 0;
              USISRL = 0x00;                // Generate Start Condition...
              USICTL0 |= USIGE+USIOE;
              USICTL0 &= ~USIGE;
              if (Transmit == 1){
                //USISRL = 0x90;              // Address is 0x48 << 1 bit + 0 (rw)
                USISRL = SLV_Addr;
              }
               if (Transmit == 0){
               //USISRL = 0x91;               // 0x91 Address is 0x48 << 1 bit 
               USISRL = SLV_Addr;
               //USISRL = 0x43 << 1;                             // + 1 for Read
               }
              USICNT = (USICNT & 0xE0) + 0x08; // Bit counter = 8, TX Address
              I2C_State = 2;                // next state: rcv address (N)Ack
              break;

      case 2: // Receive Address Ack/Nack bit
              USICTL0 &= ~USIOE;            // SDA = input
              USICNT |= 0x01;               // Bit counter=1, receive (N)Ack bit
              I2C_State = 4;                // Go to next state: check (N)Ack
              break;

      case 4: // Process Address Ack/Nack & handle data TX
             
 if(Transmit == 1){
              USICTL0 |= USIOE;             // SDA = output
              if (USISRL & 0x01)            // If Nack received...
              { // Send stop...
                USISRL = 0x00;
                USICNT |=  0x01;            // Bit counter=1, SCL high, SDA low
                I2C_State = 14;             // Go to next state: generate Stop
                //P1OUT |= 0x01;              // Turn on LED: error
              }
              else
              { // Ack received, TX data to slave... 
              //USISRL = 0x41;//MST_Data++;            // Load data byte
              USISRL = MST_Data[sent_index++];
              USICNT |=  0x08;              // Bit counter = 8, start TX
              I2C_State = 10;               // next state: receive data (N)Ack
              Bytecount++;
              //P1OUT &= ~0x01;               // Turn off LED
              break;
              }
 } if(Transmit == 0){

               if (USISRL & 0x01)            // If Nack received
              { // Prep Stop Condition
                USICTL0 |= USIOE;
                USISRL = 0x00;
                USICNT |=  0x01;            // Bit counter= 1, SCL high, SDA low
                I2C_State = 8;              // Go to next state: generate Stop
                //P1OUT |= 0x01;              // Turn on LED: error
              }
              else{ Data_RX();}             // Ack received
              

}
              break;

case 6: // Send Data Ack/Nack bit      
              reading[reading_count++] = USISRL;
  
              USICTL0 |= USIOE;             // SDA = output
              if (Bytecount <= number_of_bytes-2)
              {                             // If this is not the last byte
                USISRL = 0x00;              // Send Ack
                //P1OUT &= ~0x01;             // LED off
                I2C_State = 4;              // Go to next state: data/rcv again
                Bytecount++;
                }
                
              else //last byte: send NACK
              {
                USISRL = 0xFF;              // Send NAck
                //P1OUT |= 0x01;              // LED on: end of comm
                I2C_State = 8;              // stop condition
              }
              USICNT |= 0x01;               // Bit counter = 1, send (N)Ack bit
              break;

      case 8: // Prep Stop Condition
              USICTL0 |= USIOE;             // SDA = output
              USISRL = 0x00;
              USICNT |=  0x01;              // Bit counter= 1, SCL high, SDA low
              I2C_State = 14;               // Go to next state: generate Stop
              break;

      case 10: // Receive Data Ack/Nack bit
              USICTL0 &= ~USIOE;            // SDA = input
              USICNT |= 0x01;               // Bit counter = 1, receive (N)Ack bit
              I2C_State = 12;               // Go to next state: check (N)Ack
              break;

      case 12: // Process Data Ack/Nack & send Stop
                    
              USICTL0 |= USIOE;
              if (Bytecount == number_of_bytes){// If last byte
                
                if(repeated_start == 1){
                
                USISRL = 0xFF;                // this will prevent a stop cond
                USICTL0 |= USIOE;             // SDA = output
                I2C_State = 14;               // Go to next state: generate Stop
                USICNT |=  0x01;     }        // set count=1 to trigger next state
                
              else{
              USISRL = 0x00;
              
              I2C_State = 14;               // Go to next state: generate Stop
              //P1OUT |= 0x01;
              USICNT |=  0x01;     }        // set count=1 to trigger next state
              }else{
                //P1OUT &= ~0x01;             // Turn off LED
                Data_TX();                  // TX byte
              }
              break;

      case 14:// Generate Stop Condition
              USISRL = 0x0FF;               // USISRL = 1 to release SDA
              USICTL0 |= USIGE;             // Transparent latch enabled
              USICTL0 &= ~(USIGE+USIOE);    // Latch/SDA output disabled
              I2C_State = 0;                // Reset state machine for next xmt
              LPM0_EXIT;                    // Exit active for next transfer
              break;
    }

  USICTL1 &= ~USIIFG;                       // Clear pending flag
}


void Data_TX (void){

              USISRL =  MST_Data[sent_index++];//0x41; //MST_Data++;          // Load data byte
              USICNT |=  0x08;              // Bit counter = 8, start TX
              I2C_State = 10;               // next state: receive data (N)Ack
              Bytecount++;
}

void Data_RX (void){
        //reading[reading_count++] = USISRL;
    
	USICTL0 &= ~USIOE;                  // SDA = input --> redundant
        USICNT |=  0x08;                    // Bit counter = 8, RX data
        I2C_State = 6;                      // Next state: Test data and (N)Ack
        //P1OUT &= ~0x01;                     // LED off
        }


void Setup_USI_Master_TX (void)
{ 
  _DINT();
  Transmit = 1;
  USICTL0 = USIPE6+USIPE7+USIMST+USISWRST;  // Port & USI mode setup
  USICTL1 = USII2C+USIIE;                   // Enable I2C mode & USI interrupt
  USICKCTL = USIDIV_7+USISSEL_2+USICKPL;    // USI clk: SCL = SMCLK/128
  USICNT |= USIIFGCC;                       // Disable automatic clear control
  USICTL0 &= ~USISWRST;                     // Enable USI
  USICTL1 &= ~USIIFG;                       // Clear pending flag
  _EINT();
}


void Setup_USI_Master_RX (void)
{ 
  _DINT();
  Transmit = 0;
  USICTL0 = USIPE6+USIPE7+USIMST+USISWRST;  // Port & USI mode setup
  USICTL1 = USII2C+USIIE;                   // Enable I2C mode & USI interrupt
  USICKCTL = USIDIV_7+USISSEL_2+USICKPL;    // USI clks: SCL = SMCLK/128
  USICNT |= USIIFGCC;                       // Disable automatic clear control
  USICTL0 &= ~USISWRST;                     // Enable USI
  USICTL1 &= ~USIIFG;                       // Clear pending flag
  _EINT();

}

void Master_Transmit(char data[], int length){
  for (int i = 0; i < length; i++) {
      MST_Data[i] = data[i];
  }
  sent_index = 0;
  number_of_bytes = length;
  Setup_USI_Master_TX();
    USICTL1 |= USIIFG;                      // Set flag and start communication
    LPM0;                                   // CPU off, await USI interrupt
}
void Master_Receive(void){
  number_of_bytes = number_of_RX_bytes;
  Setup_USI_Master_RX();
  USICTL1 |= USIIFG;                        // Set flag and start communication
  LPM0;                                     // CPU off, await USI interrupt
}

void long_delay()
{
  for (long i = 0; i < 300000; i++) {
    delay();
  }
}

void delay()
{
  for (int i = 0; i < 10; i++) {
    _NOP();
  }
}