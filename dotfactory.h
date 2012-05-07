
#ifndef __BITMAP_DB_H_
#define __BITMAP_DB_H_

// ==========================================================================
// structure definition
// ==========================================================================

#define uint_8 unsigned char 
#define uint_16 unsigned int

void writeSansSerifString(uint_8 x, uint_8 y, unsigned char *c);
int writeSansSerif(uint_8 x, uint_8 y, unsigned char c);
void writeJingJingString(uint_8 x, uint_8 y, unsigned char *c);
int writeJingJing(uint_8 x, uint_8 y, unsigned char c);

// This structure describes a single character's display information
typedef struct
{
	const uint_8 widthBits;					// width, in bits (or pixels), of the character
	const uint_16 offset;					// offset of the character's bitmap, in bytes, into the the FONT_INFO's data array
	
} FONT_CHAR_INFO;	

// Describes a single font
typedef struct
{
	const uint_8 			heightPages;	// height, in pages (8 pixels), of the font's characters
	const uint_8 			startChar;		// the first character in the font (e.g. in charInfo and data)
	const uint_8 			endChar;		// the last character in the font
	const uint_8			spacePixels;	// number of pixels that a space character takes up
	const FONT_CHAR_INFO*	charInfo;		// pointer to array of char information
	const uint_8*			data;			// pointer to generated array of character visual representation
		
} FONT_INFO;	


#endif /* __BITMAP_DB_H_ */

