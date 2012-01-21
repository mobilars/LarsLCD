

#include <msp430.h>
#include "i2c_lib.h"
#include "I2C_master.h"

#define number_of_TX_bytes 1                // How many bytes do you want to TX?   
#define number_of_RX_bytes 3                // How many bytes do you want to RX?


int reading[5];
int reading_count = 0;

char MST_Data[21];                       // Variable for transmitted data
int sent_index = 0;
char SLV_Addr = 0x42;                       
int I2C_State, Bytecount, Transmit, number_of_bytes, repeated_start = 0;     

void init_i2c(int slave_address)
{
  P1OUT |= BIT6 | BIT7;                              // P1.6 & P1.7 Pullups, others to 0
  //P1REN |= BIT6 | BIT7;                             // P1.6 & P1.7 Pullups
  
  SLV_Addr = slave_address;
    
}

void Master_Transmit(char data[], int length)
{
    i2cm_start( );
    i2cm_out( SLV_Addr );
    i2cm_out( data[0] ) ;
    i2cm_out( (unsigned int) data[1] ) ;
    i2cm_stop( );   
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