// Derived from: http://lakeweb.net/MSP430/

#include <msp430.h>
#include "I2C_master.h"
  
#include <stdint.h> // For uint16_t

#define SCL_HIGH I2C_MASTER_OUT |= I2C_MASTER_SCL
#define SCL_LOW I2C_MASTER_OUT &= ~I2C_MASTER_SCL
#define SDA_HIGH I2C_MASTER_OUT |= I2C_MASTER_SDA
#define SDA_LOW I2C_MASTER_OUT &= ~I2C_MASTER_SDA

//Send data byte out on bang i2c, return false if ack
//Assumes start has been set up or a next byte
//so  both lines are assumed low
// **Lower byte of 'data' is sent**
unsigned char i2cm_out( register unsigned int data )
{
	volatile unsigned int i = 0; 
        
        // Set SDA and SCL OUT
        I2C_MASTER_DIR |= I2C_MASTER_SDA | I2C_MASTER_SCL;
        
        brief_pause( I2C_MASTER_DDLY );
        
	for( ; i < 8; ++i )
	{
		//send the data bit
                if( data & 0x80 ) 
                {
                        SDA_HIGH;
                }
		else
                {
                        SDA_LOW;
                }
		brief_pause(  );
		//shift next data bit
		data <<= 1;
                SCL_HIGH;
		brief_pause(  );
		//Set SCL Low
                SCL_LOW;
                brief_pause(  );
	}

	//make sure SDA inputs
	I2C_MASTER_DIR &= ~I2C_MASTER_SDA;
        SDA_HIGH; // Pull-up
        brief_pause(  );

	//Set  SCL High
	SCL_HIGH;
        brief_pause(  );
        brief_pause(  );
        
	//get the ack bit, true if ack
	uint8_t ack = !( I2C_MASTER_IN & I2C_MASTER_SDA );
	
        // Probably not right for READ...
	//if ( ack ) //leave SDA in last state!
        //{
		I2C_MASTER_DIR |= I2C_MASTER_SDA;
        //}

	//Set SCL Low
	SCL_LOW;
        brief_pause(  );

	return ack;
}

void i2cm_start( void )
{
    SDA_HIGH;
    SCL_HIGH;
    I2C_MASTER_DIR |= I2C_MASTER_SDA | I2C_MASTER_SCL;
    long_pause(  );
    
    SDA_LOW;
    long_pause(  );
    SCL_LOW;
    long_pause(  );
    long_pause(  );
}

//Assumes SCL is low
void i2cm_stop( void )
{
    I2C_MASTER_DIR |= I2C_MASTER_SDA;
    SDA_LOW;
    long_pause(  );
    SCL_HIGH;
    long_pause(  );
    SDA_HIGH;
    long_pause(  );
}

static void brief_pause( )
{
  // No delay necessary (might be able to remove fn call also)
  //__delay_cycles(0x20);
  //__delay_cycles(0x01);
}

static void long_pause()
{
  //__delay_cycles(0x70);
  //__delay_cycles(0x02);
}

