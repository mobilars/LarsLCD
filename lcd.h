
#define DATA 0x01
#define CMD 0x00

void SPISetup(void);
void SPIWrite(char conf, char value);
void partial();

void SPIBBSetup(void);
void SPIBBWrite(char addr, char value);

void writeChar(unsigned char chr);
void writeString(char * string);
void clear();
void setCursor(unsigned char column, unsigned char line);
void writeMegaFont(char xpos, char ypos, char ch);
void writeMegaNumber(char xpos, char ypos, char ch);
void drawBitmap(const unsigned char *data, unsigned char mx, unsigned char my, char xpos, char ypos);


