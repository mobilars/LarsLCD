/*
* License: BSD
* Contributors: Lars Roland, Cor Berrevoets
*/

#define DATA 0x01
#define CMD 0x00

void SPISetup(void);
void SPIWrite(char conf, char value);
void SPIRead(char conf, char value);
void partial();

void SPIBBSetup(void);
void SPIBBWrite(char addr, char value);

void writeChar(char x, char y, unsigned char chr);
void writeHex (char x,char y,const unsigned char out);
void writeInt (char x, char y,const unsigned int out, unsigned int precision);

void writeString(char x, char y,char * string);
void writeRString(char x, char y, char * string);
void clear();

void setscreenmode(char mode);
void setcharmode(char mode);
void setpixelmode(char mode);
void updatepixels();
void clearpixels();
void setpixel(char x, char y);
void drawbox(char x, char y, char w, char h);

void setCursor(unsigned char column, unsigned char line);
void writeMegaFont(char xpos, char ypos, char ch);
void drawBitmap(const unsigned char *data, unsigned char mx, unsigned char my, char xpos, char ypos);

