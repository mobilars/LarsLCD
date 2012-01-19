


void Master_RPT(void);

void Master_Transmit(char data[], int length);
void Master_Receive(void);

void Setup_USI_Master_TX(void);
void Setup_USI_Master_RX(void);

void init_i2c(int slave_address);

void long_delay();
void delay();