/* 
**  Font data for Microsoft Sans Serif 16pt
*/

#include "dotfactory.h"
#include "lcd.h"



/* 
**  Font data for Microsoft Sans Serif 16pt
*/

/* Character bitmaps for Microsoft Sans Serif 16pt */
const uint_8 microsoftSansSerif16ptBitmaps[] = 
{
	/* @0 '0' (10 pixels wide) */
	0xF0, 0x0F, /* ####        #### */
	0xFC, 0x1F, /* ######     ##### */
	0x0E, 0x38, /*     ###   ###    */
	0x03, 0x60, /*       ## ##      */
	0x03, 0x60, /*       ## ##      */
	0x03, 0x60, /*       ## ##      */
	0x03, 0x60, /*       ## ##      */
	0x0E, 0x38, /*     ###   ###    */
	0xFC, 0x1F, /* ######     ##### */
	0xF0, 0x0F, /* ####        #### */

	/* @20 '1' (6 pixels wide) */
	0x18, 0x00, /*    ##            */
	0x18, 0x00, /*    ##            */
	0x18, 0x00, /*    ##            */
	0x0C, 0x00, /*     ##           */
	0xFF, 0x7F, /* ######## ####### */
	0xFF, 0x7F, /* ######## ####### */

	/* @32 '2' (10 pixels wide) */
	0x0C, 0x60, /*     ##   ##      */
	0x0E, 0x70, /*     ###  ###     */
	0x07, 0x78, /*      ### ####    */
	0x03, 0x6C, /*       ## ## ##   */
	0x03, 0x66, /*       ## ##  ##  */
	0x03, 0x63, /*       ## ##   ## */
	0x03, 0x61, /*       ## ##    # */
	0xC7, 0x61, /* ##   ### ##    # */
	0xFE, 0x60, /* #######  ##      */
	0x3C, 0x60, /*   ####   ##      */

	/* @52 '3' (10 pixels wide) */
	0x0C, 0x18, /*     ##     ##    */
	0x0E, 0x38, /*     ###   ###    */
	0x07, 0x70, /*      ### ###     */
	0x03, 0x60, /*       ## ##      */
	0xC3, 0x60, /* ##    ## ##      */
	0xC3, 0x60, /* ##    ## ##      */
	0xE7, 0x60, /* ###  ### ##      */
	0xFE, 0x31, /* #######   ##   # */
	0xBC, 0x3F, /* # ####    ###### */
	0x00, 0x1E, /*            ####  */

	/* @72 '4' (11 pixels wide) */
	0x00, 0x07, /*              ### */
	0x80, 0x07, /* #            ### */
	0xC0, 0x06, /* ##           ##  */
	0x60, 0x06, /*  ##          ##  */
	0x30, 0x06, /*   ##         ##  */
	0x1C, 0x06, /*    ###       ##  */
	0x0E, 0x06, /*     ###      ##  */
	0xFF, 0x7F, /* ######## ####### */
	0xFF, 0x7F, /* ######## ####### */
	0x00, 0x06, /*              ##  */
	0x00, 0x06, /*              ##  */

	/* @94 '5' (10 pixels wide) */
	0x00, 0x18, /*            ##    */
	0xF0, 0x38, /* ####      ###    */
	0xFF, 0x70, /* ######## ###     */
	0x6F, 0x60, /*  ## #### ##      */
	0x63, 0x60, /*  ##   ## ##      */
	0x63, 0x60, /*  ##   ## ##      */
	0x63, 0x60, /*  ##   ## ##      */
	0xE3, 0x30, /* ###   ##  ##     */
	0xC3, 0x3F, /* ##    ##  ###### */
	0x80, 0x0F, /* #           #### */

	/* @114 '6' (10 pixels wide) */
	0xF0, 0x07, /* ####         ### */
	0xFC, 0x1F, /* ######     ##### */
	0xCE, 0x38, /* ##  ###   ###    */
	0x67, 0x70, /*  ##  ### ###     */
	0x63, 0x60, /*  ##   ## ##      */
	0x63, 0x60, /*  ##   ## ##      */
	0x63, 0x60, /*  ##   ## ##      */
	0xE7, 0x30, /* ###  ###  ##     */
	0xCE, 0x3F, /* ##  ###   ###### */
	0x0C, 0x0F, /*     ##      #### */

	/* @134 '7' (10 pixels wide) */
	0x03, 0x00, /*       ##         */
	0x03, 0x00, /*       ##         */
	0x03, 0x40, /*       ## #       */
	0x03, 0x70, /*       ## ###     */
	0x03, 0x3E, /*       ##  #####  */
	0x83, 0x0F, /* #     ##    #### */
	0xE3, 0x01, /* ###   ##       # */
	0x7B, 0x00, /*  #### ##         */
	0x1F, 0x00, /*    #####         */
	0x07, 0x00, /*      ###         */

	/* @154 '8' (10 pixels wide) */
	0x00, 0x1E, /*            ####  */
	0x1C, 0x3F, /*    ###    ###### */
	0xBE, 0x71, /* # #####  ###   # */
	0xE3, 0x61, /* ###   ## ##    # */
	0xC3, 0x60, /* ##    ## ##      */
	0xC3, 0x60, /* ##    ## ##      */
	0xE3, 0x61, /* ###   ## ##    # */
	0xBE, 0x71, /* # #####  ###   # */
	0x1C, 0x3F, /*    ###    ###### */
	0x00, 0x1E, /*            ####  */

	/* @174 '9' (10 pixels wide) */
	0x78, 0x18, /*  ####      ##    */
	0xFE, 0x39, /* #######   ###  # */
	0x86, 0x73, /* #    ##  ###  ## */
	0x03, 0x63, /*       ## ##   ## */
	0x03, 0x63, /*       ## ##   ## */
	0x03, 0x63, /*       ## ##   ## */
	0x07, 0x73, /*      ### ###  ## */
	0x8E, 0x39, /* #   ###   ###  # */
	0xFC, 0x1F, /* ######     ##### */
	0xF0, 0x07, /* ####         ### */
};

/* Character descriptors for Microsoft Sans Serif 16pt */
/* { [Char width in bits], [Offset into microsoftSansSerif16ptCharBitmaps in bytes] } */
const FONT_CHAR_INFO microsoftSansSerif16ptDescriptors[] = 
{
	{10, 0}, 		/* 0 */ 
	{6, 20}, 		/* 1 */ 
	{10, 32}, 		/* 2 */ 
	{10, 52}, 		/* 3 */ 
	{11, 72}, 		/* 4 */ 
	{10, 94}, 		/* 5 */ 
	{10, 114}, 		/* 6 */ 
	{10, 134}, 		/* 7 */ 
	{10, 154}, 		/* 8 */ 
	{10, 174}, 		/* 9 */ 
};

/* Font information for Microsoft Sans Serif 16pt */
const FONT_INFO microsoftSansSerif16ptFontInfo =
{
	2, /*  Character height */
	'0', /*  Start character */
	'9', /*  End character */
	2, /*  Width, in pixels, of space character */
	microsoftSansSerif16ptDescriptors, /*  Character descriptor array */
	microsoftSansSerif16ptBitmaps, /*  Character bitmap array */
};

/* 
**  Font data for Jing Jing 12pt
*/

/* Character bitmaps for Jing Jing 12pt */
const uint_8 jingJing12ptBitmaps[] = 
{
	/* @0 '0' (9 pixels wide) */
	0xF0, 0x03, /* ####          ## */
	0xFC, 0x07, /* ######       ### */
	0x02, 0x0E, /*       #     ###  */
	0x03, 0x1C, /*       ##   ###   */
	0x07, 0x18, /*      ###   ##    */
	0x07, 0x18, /*      ###   ##    */
	0x1E, 0x0C, /*    ####     ##   */
	0xFC, 0x07, /* ######       ### */
	0xF0, 0x01, /* ####           # */

	/* @18 '1' (6 pixels wide) */
	0x10, 0x00, /*    #             */
	0x08, 0x00, /*     #            */
	0x0E, 0x00, /*     ###          */
	0x1F, 0x00, /*    #####         */
	0xFF, 0x3F, /* ########  ###### */
	0xFE, 0x03, /* #######       ## */

	/* @30 '2' (9 pixels wide) */
	0x00, 0x20, /*           #      */
	0x06, 0x20, /*      ##   #      */
	0x03, 0x18, /*       ##   ##    */
	0x03, 0x1C, /*       ##   ###   */
	0x03, 0x17, /*       ##   # ### */
	0xCA, 0x1B, /* ##  # #    ## ## */
	0xF2, 0x19, /* ####  #    ##  # */
	0x74, 0x38, /*  ### #    ###    */
	0x28, 0x38, /*   # #     ###    */

	/* @48 '3' (8 pixels wide) */
	0x04, 0x1C, /*      #     ###   */
	0x03, 0x18, /*       ##   ##    */
	0x83, 0x10, /* #     ##   #     */
	0x43, 0x10, /*  #    ##   #     */
	0x66, 0x10, /*  ##  ##    #     */
	0xBA, 0x17, /* # ### #    # ### */
	0x1C, 0x0F, /*    ###      #### */
	0x0C, 0x0A, /*     ##      # #  */

	/* @64 '4' (10 pixels wide) */
	0x00, 0x03, /*               ## */
	0x00, 0x01, /*                # */
	0xC0, 0x01, /* ##             # */
	0x3F, 0x01, /*   ######       # */
	0x1E, 0x01, /*    ####        # */
	0x84, 0x39, /* #    #    ###  # */
	0xC0, 0x3F, /* ##        ###### */
	0xFC, 0x1F, /* ######     ##### */
	0x82, 0x01, /* #     #        # */
	0x80, 0x01, /* #              # */

	/* @84 '5' (8 pixels wide) */
	0x94, 0x14, /* #  # #     # #   */
	0xFE, 0x18, /* #######    ##    */
	0x47, 0x10, /*  #   ###   #     */
	0x46, 0x10, /*  #   ##    #     */
	0x46, 0x1C, /*  #   ##    ###   */
	0xC6, 0x10, /* ##   ##    #     */
	0xC2, 0x0F, /* ##    #     #### */
	0x81, 0x07, /* #      #     ### */

	/* @100 '6' (8 pixels wide) */
	0xE0, 0x03, /* ###           ## */
	0xF8, 0x0F, /* #####       #### */
	0x4C, 0x0E, /*  #  ##      ###  */
	0x32, 0x1C, /*   ##  #    ###   */
	0x31, 0x18, /*   ##   #   ##    */
	0x71, 0x08, /*  ###   #    #    */
	0xE0, 0x0F, /* ###         #### */
	0xC0, 0x03, /* ##            ## */

	/* @116 '7' (9 pixels wide) */
	0x07, 0x20, /*      ###  #      */
	0x07, 0x38, /*      ###  ###    */
	0x03, 0x3E, /*       ##  #####  */
	0x83, 0x1F, /* #     ##   ##### */
	0xE3, 0x03, /* ###   ##      ## */
	0x72, 0x00, /*  ###  #          */
	0x0E, 0x00, /*     ###          */
	0x03, 0x00, /*       ##         */
	0x03, 0x00, /*       ##         */

	/* @134 '8' (8 pixels wide) */
	0x9E, 0x0F, /* #  ####     #### */
	0xB2, 0x1C, /* # ##  #    ###   */
	0x61, 0x18, /*  ##    #   ##    */
	0xE1, 0x18, /* ###    #   ##    */
	0xE7, 0x09, /* ###  ###    #  # */
	0xDB, 0x0F, /* ## ## ##    #### */
	0x8F, 0x07, /* #   ####     ### */
	0x04, 0x02, /*      #        #  */

	/* @150 '9' (8 pixels wide) */
	0x78, 0x00, /*  ####            */
	0xFE, 0x00, /* #######          */
	0xC2, 0x11, /* ##    #    #   # */
	0x83, 0x11, /* #     ##   #   # */
	0x87, 0x09, /* #    ###    #  # */
	0x8E, 0x06, /* #   ###      ##  */
	0xFE, 0x03, /* #######       ## */
	0xF8, 0x00, /* #####            */
};

/* Character descriptors for Jing Jing 12pt */
/* { [Char width in bits], [Offset into jingJing12ptCharBitmaps in bytes] } */
const FONT_CHAR_INFO jingJing12ptDescriptors[] = 
{
	{9, 0}, 		/* 0 */ 
	{6, 18}, 		/* 1 */ 
	{9, 30}, 		/* 2 */ 
	{8, 48}, 		/* 3 */ 
	{10, 64}, 		/* 4 */ 
	{8, 84}, 		/* 5 */ 
	{8, 100}, 		/* 6 */ 
	{9, 116}, 		/* 7 */ 
	{8, 134}, 		/* 8 */ 
	{8, 150}, 		/* 9 */ 
};

/* Font information for Jing Jing 12pt */
const FONT_INFO jingJing12ptFontInfo =
{
	2, /*  Character height */
	'0', /*  Start character */
	'9', /*  End character */
	2, /*  Width, in pixels, of space character */
	jingJing12ptDescriptors, /*  Character descriptor array */
	jingJing12ptBitmaps, /*  Character bitmap array */
};


// Functions


int writeSansSerif(uint_8 x, uint_8 y_font, unsigned char c)
{
  int i;
  char ch = c - microsoftSansSerif16ptFontInfo.startChar;
  int offset = microsoftSansSerif16ptFontInfo.charInfo[ch].offset;
  int widthBits = microsoftSansSerif16ptFontInfo.charInfo[ch].widthBits;
  int heightPages = microsoftSansSerif16ptFontInfo.heightPages;
  int y = (y_font*heightPages);
  uint_8 spacePixels = microsoftSansSerif16ptFontInfo.spacePixels;
    
  setCursor(x, y);
  for (i = 0; i < widthBits; i++) {
      SPIWrite(DATA, microsoftSansSerif16ptBitmaps[offset+(i*2)]);
  }
  for (i = 0; i < spacePixels; i++) {
      SPIWrite(DATA, 0x00);
  }
  setCursor(x, y+1);
  for (i = 0; i < widthBits; i++) {
      SPIWrite(DATA, microsoftSansSerif16ptBitmaps[offset+(i*2)+1]);
  }
  for (i = 0; i < spacePixels; i++) {
      SPIWrite(DATA, 0x00);
  }
  
  return widthBits+spacePixels;
    
}

void writeSansSerifString(uint_8 x, uint_8 y, unsigned char *str)
{
  int i,width;
  width = 0;
  
  for (i = 0; i < 100; i++) {
    if (str[i] == '\0') break;
    width += writeSansSerif(x+width,y,str[i]);
  }

}

int writeJingJing(uint_8 x, uint_8 y_font, unsigned char c)
{
  int i;
  char ch = c - jingJing12ptFontInfo.startChar;
  int offset = jingJing12ptFontInfo.charInfo[ch].offset;
  int widthBits = jingJing12ptFontInfo.charInfo[ch].widthBits;
  int heightPages = jingJing12ptFontInfo.heightPages;
  int y = (y_font*heightPages);
  uint_8 spacePixels = jingJing12ptFontInfo.spacePixels;
    
  setCursor(x, y);
  for (i = 0; i < widthBits; i++) {
      SPIWrite(DATA, jingJing12ptBitmaps[offset+(i*2)]);
  }
  for (i = 0; i < spacePixels; i++) {
      SPIWrite(DATA, 0x00);
  }
  setCursor(x, y+1);
  for (i = 0; i < widthBits; i++) {
      SPIWrite(DATA, jingJing12ptBitmaps[offset+(i*2)+1]);
  }
  for (i = 0; i < spacePixels; i++) {
      SPIWrite(DATA, 0x00);
  }
  
  return widthBits+spacePixels;
    
}

void writeJingJingString(uint_8 x, uint_8 y, unsigned char *str)
{
  int i,width;
  width = 0;
  
  for (i = 0; i < 100; i++) {
    if (str[i] == '\0') break;
    width += writeJingJing(x+width,y,str[i]);
  }
}
