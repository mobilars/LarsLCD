

void init_display(void);
void send(char config, char data);
void clear(void);
void clearLine();
void setInverse(char inverse);
void home(void);
void setCursor(unsigned char column, unsigned char line);
void write(unsigned char chr);
void drawBitmap(const unsigned char *data, unsigned char mx, unsigned char my, char xpos, char ypos);
void writeMegaFont(char xpos, char ypos, char ch);