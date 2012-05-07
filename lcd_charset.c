
#ifndef CHARSET
#define CHARSET


const unsigned char ball [] = {
0x00, 0x3C, 0x7E, 0xFF, 0xFF
};

// The 7-bit ASCII character set...
const unsigned char charset[][5] = {
  { 0x00, 0x00, 0x00, 0x00, 0x00 },  // 20 space
  { 0x00, 0x00, 0x5f, 0x00, 0x00 },  // 21 !
  { 0x00, 0x07, 0x00, 0x07, 0x00 },  // 22 "
  { 0x14, 0x7f, 0x14, 0x7f, 0x14 },  // 23 #
  { 0x24, 0x2a, 0x7f, 0x2a, 0x12 },  // 24 $
  { 0x23, 0x13, 0x08, 0x64, 0x62 },  // 25 %
  { 0x36, 0x49, 0x55, 0x22, 0x50 },  // 26 &
  { 0x00, 0x05, 0x03, 0x00, 0x00 },  // 27 '
  { 0x00, 0x1c, 0x22, 0x41, 0x00 },  // 28 (
  { 0x00, 0x41, 0x22, 0x1c, 0x00 },  // 29 )
  { 0x14, 0x08, 0x3e, 0x08, 0x14 },  // 2a *
  { 0x08, 0x08, 0x3e, 0x08, 0x08 },  // 2b +
  { 0x00, 0x50, 0x30, 0x00, 0x00 },  // 2c ,
  { 0x08, 0x08, 0x08, 0x08, 0x08 },  // 2d -
  { 0x00, 0x60, 0x60, 0x00, 0x00 },  // 2e .
  { 0x20, 0x10, 0x08, 0x04, 0x02 },  // 2f /
  { 0x3e, 0x51, 0x49, 0x45, 0x3e },  // 30 0
  { 0x00, 0x42, 0x7f, 0x40, 0x00 },  // 31 1
  { 0x42, 0x61, 0x51, 0x49, 0x46 },  // 32 2
  { 0x21, 0x41, 0x45, 0x4b, 0x31 },  // 33 3
  { 0x18, 0x14, 0x12, 0x7f, 0x10 },  // 34 4
  { 0x27, 0x45, 0x45, 0x45, 0x39 },  // 35 5
  { 0x3c, 0x4a, 0x49, 0x49, 0x30 },  // 36 6
  { 0x01, 0x71, 0x09, 0x05, 0x03 },  // 37 7
  { 0x36, 0x49, 0x49, 0x49, 0x36 },  // 38 8
  { 0x06, 0x49, 0x49, 0x29, 0x1e },  // 39 9
  { 0x00, 0x36, 0x36, 0x00, 0x00 },  // 3a :
  { 0x00, 0x56, 0x36, 0x00, 0x00 },  // 3b ;
  { 0x08, 0x14, 0x22, 0x41, 0x00 },  // 3c <
  { 0x14, 0x14, 0x14, 0x14, 0x14 },  // 3d =
  { 0x00, 0x41, 0x22, 0x14, 0x08 },  // 3e >
  { 0x02, 0x01, 0x51, 0x09, 0x06 },  // 3f ?
  { 0x32, 0x49, 0x79, 0x41, 0x3e },  // 40 @
  { 0x7e, 0x11, 0x11, 0x11, 0x7e },  // 41 A
  { 0x7f, 0x49, 0x49, 0x49, 0x36 },  // 42 B
  { 0x3e, 0x41, 0x41, 0x41, 0x22 },  // 43 C
  { 0x7f, 0x41, 0x41, 0x22, 0x1c },  // 44 D
  { 0x7f, 0x49, 0x49, 0x49, 0x41 },  // 45 E
  { 0x7f, 0x09, 0x09, 0x09, 0x01 },  // 46 F
  { 0x3e, 0x41, 0x49, 0x49, 0x7a },  // 47 G
  { 0x7f, 0x08, 0x08, 0x08, 0x7f },  // 48 H
  { 0x00, 0x41, 0x7f, 0x41, 0x00 },  // 49 I
  { 0x20, 0x40, 0x41, 0x3f, 0x01 },  // 4a J
  { 0x7f, 0x08, 0x14, 0x22, 0x41 },  // 4b K
  { 0x7f, 0x40, 0x40, 0x40, 0x40 },  // 4c L
  { 0x7f, 0x02, 0x0c, 0x02, 0x7f },  // 4d M
  { 0x7f, 0x04, 0x08, 0x10, 0x7f },  // 4e N
  { 0x3e, 0x41, 0x41, 0x41, 0x3e },  // 4f O
  { 0x7f, 0x09, 0x09, 0x09, 0x06 },  // 50 P
  { 0x3e, 0x41, 0x51, 0x21, 0x5e },  // 51 Q
  { 0x7f, 0x09, 0x19, 0x29, 0x46 },  // 52 R
  { 0x46, 0x49, 0x49, 0x49, 0x31 },  // 53 S
  { 0x01, 0x01, 0x7f, 0x01, 0x01 },  // 54 T
  { 0x3f, 0x40, 0x40, 0x40, 0x3f },  // 55 U
  { 0x1f, 0x20, 0x40, 0x20, 0x1f },  // 56 V
  { 0x3f, 0x40, 0x38, 0x40, 0x3f },  // 57 W
  { 0x63, 0x14, 0x08, 0x14, 0x63 },  // 58 X
  { 0x07, 0x08, 0x70, 0x08, 0x07 },  // 59 Y
  { 0x61, 0x51, 0x49, 0x45, 0x43 },  // 5a Z
  { 0x00, 0x7f, 0x41, 0x41, 0x00 },  // 5b [
  { 0x02, 0x04, 0x08, 0x10, 0x20 },  // 5c backslash 
  { 0x00, 0x41, 0x41, 0x7f, 0x00 },  // 5d ]
  { 0x04, 0x02, 0x01, 0x02, 0x04 },  // 5e ^
  { 0x40, 0x40, 0x40, 0x40, 0x40 },  // 5f _
  { 0x00, 0x01, 0x02, 0x04, 0x00 },  // 60 `
  { 0x20, 0x54, 0x54, 0x54, 0x78 },  // 61 a
  { 0x7f, 0x48, 0x44, 0x44, 0x38 },  // 62 b
  { 0x38, 0x44, 0x44, 0x44, 0x20 },  // 63 c
  { 0x38, 0x44, 0x44, 0x48, 0x7f },  // 64 d
  { 0x38, 0x54, 0x54, 0x54, 0x18 },  // 65 e
  { 0x08, 0x7e, 0x09, 0x01, 0x02 },  // 66 f
  { 0x0c, 0x52, 0x52, 0x52, 0x3e },  // 67 g
  { 0x7f, 0x08, 0x04, 0x04, 0x78 },  // 68 h
  { 0x00, 0x44, 0x7d, 0x40, 0x00 },  // 69 i
  { 0x20, 0x40, 0x44, 0x3d, 0x00 },  // 6a j 
  { 0x7f, 0x10, 0x28, 0x44, 0x00 },  // 6b k
  { 0x00, 0x41, 0x7f, 0x40, 0x00 },  // 6c l
  { 0x7c, 0x04, 0x18, 0x04, 0x78 },  // 6d m
  { 0x7c, 0x08, 0x04, 0x04, 0x78 },  // 6e n
  { 0x38, 0x44, 0x44, 0x44, 0x38 },  // 6f o
  { 0x7c, 0x14, 0x14, 0x14, 0x08 },  // 70 p
  { 0x08, 0x14, 0x14, 0x18, 0x7c },  // 71 q
  { 0x7c, 0x08, 0x04, 0x04, 0x08 },  // 72 r
  { 0x48, 0x54, 0x54, 0x54, 0x20 },  // 73 s
  { 0x04, 0x3f, 0x44, 0x40, 0x20 },  // 74 t
  { 0x3c, 0x40, 0x40, 0x20, 0x7c },  // 75 u
  { 0x1c, 0x20, 0x40, 0x20, 0x1c },  // 76 v
  { 0x3c, 0x40, 0x30, 0x40, 0x3c },  // 77 w
  { 0x44, 0x28, 0x10, 0x28, 0x44 },  // 78 x
  { 0x0c, 0x50, 0x50, 0x50, 0x3c },  // 79 y
  { 0x44, 0x64, 0x54, 0x4c, 0x44 },  // 7a z
  { 0x00, 0x08, 0x36, 0x41, 0x00 },  // 7b {
  { 0x00, 0x00, 0x7f, 0x00, 0x00 },  // 7c |
  { 0x00, 0x41, 0x36, 0x08, 0x00 },  // 7d }
  { 0x10, 0x08, 0x08, 0x10, 0x08 },  // 7e ~
  { 0x00, 0x00, 0x00, 0x00, 0x00 }   // 7f 
};



const unsigned char number[13][3][16] = {

{{0,128,192,224,224,96,224,224,  //'0'
192,128,0,0,0,0,0,0}
,
{112,255,255,1,0,0,0,0,
255,255,254,0,0,0,0,0}
,
{0,15,31,60,56,48,56,56,
31,15,3,0,0,0,0,0}
},
{
{0,0,0,0,128,224,224,0, 		   //'1'
0,0,0,0,0,0,0,0}
,
{0,0,3,3,3,255,255,0,
0,0,0,0,0,0,0,0}
,
{0,0,56,56,56,63,63,56,
56,56,0,0,0,0,0,0}
},
{
{0,192,192,224,96,96,224,224,   //'2'
192,128,0,0,0,0,0,0}
,
{0,1,0,0,128,192,224,249,
63,31,0,0,0,0,0,0}
,
{0,60,62,63,63,59,57,56,
56,56,56,0,0,0,0,0}
},
{
{0,192,224,224,96,96,224,224,   //'3'
192,192,0,0,0,0,0,0}
,
{0,1,0,0,48,48,56,125,
239,207,0,0,0,0,0,0}
,
{0,28,56,56,48,48,56,60,
31,15,1,0,0,0,0,0}
},
{
{0,0,0,0,0,128,192,224, 		   //'4'
224,0,0,0,0,0,0,0}
,
{224,240,248,222,207,199,193,255,
255,192,192,0,0,0,0,0}
,
{0,0,0,0,0,0,0,63,
63,0,0,0,0,0,0,0}
},
{
{0,224,224,224,224,224,224,224,	//'5'
224,224,224,0,0,0,0,0}
,
{0,63,63,63,56,56,48,112,
240,224,0,0,0,0,0,0}
,
{0,28,56,56,48,48,56,60,
31,15,1,0,0,0,0,0}
},
{
{0,0,128,192,192,224,96,96,		//'6'
224,224,0,0,0,0,0,0}
,
{224,254,255,55,57,24,24,56,
240,240,192,0,0,0,0,0}
,
{0,15,31,28,56,48,48,56,
31,15,7,0,0,0,0,0}
},
{
{0,224,224,224,224,224,224,224,		 //'7'
224,224,224,0,0,0,0,0}
,
{0,0,0,0,128,224,248,126,
31,7,1,0,0,0,0,0}
,
{0,0,56,62,31,7,1,0,
0,0,0,0,0,0,0,0}
},
{
{0,128,192,224,224,96,96,224,		 //'8'
192,192,0,0,0,0,0,0}
,
{0,207,255,127,56,48,112,112,
255,239,199,0,0,0,0,0}
,
{3,15,31,60,56,48,48,56,
31,31,15,0,0,0,0,0}
},
{
{0,128,192,224,224,96,224,224,		 //'9'
192,128,0,0,0,0,0,0}
,
{12,63,127,241,224,192,192,225,
255,255,254,0,0,0,0,0}
,
{0,0,56,48,48,56,56,30,
15,7,0,0,0,0,0,0}
},
{

{0,0,0,0,0,0,0,0,	  		  		 //'.'
0,0,0,0,0,0,0,0}
,
{0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0}
,
{60,60,60,0,0,0,0,0,
0,0,0,0,0,0,0,0} 
},
{
{0,0,0,0,0,0,0,0,   					 //'+'
0,0,0,0,0,0,0,0}
,
{0,0,64,64,64,64,64,254,
254,64,64,64,64,64,0,0}
,
{0,0,0,0,0,0,0,15,
15,0,0,0,0,0,0,0}
},
{
{0,0,0,0,0,0,0,0, 	   				 //'-'
0,0,0,0,0,0,0,0}
,
{0,64,64,64,64,64,64,0,
0,0,0,0,0,0,0,0}
,
{0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0}
}};


const unsigned char blackbird_96_64 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x30, 0x30,
0x70, 0x70, 0xF0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF,
0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xE0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0xFE,
0x7E, 0x3C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFC, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
0x20, 0x20, 0x10, 0x98, 0xFC, 0x7C, 0x7E, 0x3E, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x03,
0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x07, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char big_0 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0,
0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFC,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x1F,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xE0, 0x80, 0x80, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x04, 0x3C, 0x58,
0xEC, 0x10, 0xC8, 0x44, 0x80, 0xF8, 0x28, 0x48, 
};

const unsigned char big_1 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0,
0xF0, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0x7F,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char big_2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x38, 0x3E, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x0F, 0x07, 0x03, 0x01, 0x01,
0x01, 0x01, 0x01, 0x03, 0x03, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE,
0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xE7,
0xE3, 0xE1, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x1C, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00
};


const unsigned char big_3 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xE0, 0xF0, 0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x18, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x0F, 0x03, 0x03, 0x01, 0x01,
0x01, 0x01, 0x03, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xF8,
0xF8, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x8F, 0x87, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x03, 0x07, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x0C, 0x7C, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xF8, 0xE0, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
};



const unsigned char big_4 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xFE,
0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0xFE, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07,
0x03, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xF0, 0xF8, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE3, 0xE1, 0xE0, 0xE0, 0xE0, 0xE0,
0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char big_5 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFE,
0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x03, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x0C, 0x7C, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xF8, 0xE0, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char big_6 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x07, 0x03, 0x01, 0x01,
0x01, 0x01, 0x03, 0x03, 0x0F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x18, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x07, 0x03, 0x01, 0x01, 0x01,
0x01, 0x01, 0x03, 0x03, 0x07, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0x80, 0xC0, 0xE0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x0F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00
};



const unsigned char big_7 [] = {
0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0xC7, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8,
0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFE, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x7F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char big_8 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x03, 0x03, 0x01, 0x01,
0x01, 0x01, 0x03, 0x03, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x1F, 0x9F, 0xBF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xF8, 0xF8,
0xF8, 0xF8, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xBF, 0x9F, 0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x07, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x07, 0x0F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0x80, 0xC0, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00
};

const unsigned char big_9 [] = {
0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xF0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x07, 0x03, 0x01, 0x01, 0x01,
0x01, 0x01, 0x03, 0x03, 0x07, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0x80, 0xC0, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x18, 0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0xF0, 0xC0, 0xC0, 0x80, 0x80,
0x80, 0x80, 0xC0, 0xE0, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char change [] = {
0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFC, 0x7C, 0x3C, 0x1C, 0x0C, 0x04, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x04, 0x0E, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x9F, 0x1F, 0x1F, 0x1F, 0x1F,
0x1F, 0x5F, 0xDF, 0xDF, 0xDF, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0xF7, 0xF7, 0xF6, 0xF4, 0xF0,
0xF0, 0xF0, 0xF0, 0xF1, 0xF3, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0x40,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x41, 0x61, 0x71, 0x79, 0x7D, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00
};

//------------------------------------------------------------------------------
// File generated by LCD Assistant
// http://en.radzio.dxp.pl/bitmap_converter/
//------------------------------------------------------------------------------

const unsigned char logo43oh [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
0xE0, 0xF8, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0,
0x70, 0x78, 0x78, 0x78, 0x78, 0x78, 0xF8, 0xF0, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x7C, 0x1F, 0x07,
0x03, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xDF, 0xDF, 0x8F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0xC0, 0xF0, 0xF8, 0xFC, 0x3C, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x3C, 0xFC, 0xF8, 0xF0, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x78, 0x38, 0x1C, 0x1C, 0x1E, 0x1E, 0x1E, 0x7E,
0xFC, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1F, 0x1F, 0x1E, 0x1E, 0x1E, 0x1E,
0x1E, 0x1E, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC1, 0xE1, 0xFF, 0xFF, 0xFF, 0x7F, 0x1E, 0x00, 0x00, 0x00, 0x00,
0x1F, 0x7F, 0xFF, 0xF8, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF8, 0xFF, 0x7F, 0x1F,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03,
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x03, 0x03, 0x00, 
};


const unsigned char font_5_8[256][5]={
{0x00,0x00,0x00,0x00,0x00},	// 0x00
{0x1E,0x35,0x31,0x35,0x1E},	// 0x01
{0x1E,0x35,0x37,0x35,0x1E},	// 0x02
{0x0E,0x1F,0x3E,0x1F,0x0E},	// 0x03
{0x08,0x1C,0x7F,0x1C,0x08},	// 0x04
{0x18,0x4A,0x7F,0x4A,0x18},	// 0x05
{0x1C,0x4E,0x7F,0x4E,0x1C},	// 0x06
{0x00,0x00,0x00,0x00,0x00},	// 0x07
{0x00,0x00,0x00,0x00,0x00},	// 0x08
{0x00,0x00,0x00,0x00,0x00},	// 0x09
{0x00,0x00,0x00,0x00,0x00},	// 0x0A
{0x38,0x44,0x44,0x47,0x3B},	// 0x0B
{0x0E,0x51,0xF1,0x51,0x0E},	// 0x0C
{0x00,0x00,0x00,0x00,0x00},	// 0x0D
{0x60,0x7E,0x02,0x33,0x3F},	// 0x0E
{0x2A,0x1C,0x36,0x1C,0x2A},	// 0x0F
{0x3E,0x1C,0x1C,0x08,0x08},	// 0x10
{0x08,0x08,0x1C,0x1C,0x3E},	// 0x11
{0x00,0x22,0x7F,0x22,0x00},	// 0x12
{0x00,0x2E,0x00,0x2E,0x00},	// 0x13
{0x06,0x7F,0x01,0x7F,0x00},	// 0x14
{0x00,0x4A,0x55,0x29,0x00},	// 0x15
{0x00,0x18,0x18,0x18,0x18},	// 0x16
{0x00,0x4A,0x5F,0x4A,0x00},	// 0x17
{0x00,0x02,0x7F,0x02,0x00},	// 0x18
{0x00,0x20,0x7F,0x20,0x00},	// 0x19
{0x00,0x08,0x08,0x1C,0x08},	// 0x1A
{0x00,0x08,0x1C,0x08,0x08},	// 0x1B
{0x00,0x3C,0x20,0x20,0x20},	// 0x1C
{0x08,0x1C,0x08,0x1C,0x08},	// 0x1D
{0x20,0x38,0x3E,0x38,0x20},	// 0x1E
{0x02,0x0E,0x3E,0x0E,0x02},	// 0x1F
{0x00,0x00,0x00,0x00,0x00},	// 0x20
{0x00,0x00,0x2F,0x00,0x00},	// 0x21
{0x00,0x03,0x00,0x03,0x00},	// 0x22
{0x34,0x1C,0x36,0x1C,0x16},	// 0x23
{0x00,0x26,0x7F,0x32,0x00},	// 0x24
{0x32,0x0D,0x1E,0x2C,0x13},	// 0x25
{0x18,0x26,0x2D,0x12,0x28},	// 0x26
{0x00,0x00,0x03,0x00,0x00},	// 0x27
{0x00,0x1C,0x22,0x41,0x41},	// 0x28
{0x41,0x41,0x22,0x1C,0x00},	// 0x29
{0x00,0x0A,0x05,0x0A,0x00},	// 0x2A
{0x00,0x10,0x38,0x10,0x00},	// 0x2B
{0x00,0x80,0x60,0x00,0x00},	// 0x2C
{0x00,0x08,0x08,0x08,0x00},	// 0x2D
{0x00,0x00,0x20,0x00,0x00},	// 0x2E
{0x00,0x60,0x18,0x06,0x01},	// 0x2F
{0x00,0x1E,0x21,0x21,0x1E},	// 0x30
{0x00,0x22,0x3F,0x20,0x00},	// 0x31
{0x00,0x31,0x29,0x26,0x00},	// 0x32
{0x00,0x25,0x25,0x1A,0x00},	// 0x33
{0x00,0x0C,0x0A,0x3F,0x08},	// 0x34
{0x00,0x27,0x25,0x19,0x00},	// 0x35
{0x00,0x1E,0x25,0x25,0x18},	// 0x36
{0x00,0x01,0x39,0x05,0x03},	// 0x37
{0x00,0x1A,0x25,0x25,0x1A},	// 0x38
{0x00,0x06,0x29,0x29,0x1E},	// 0x39
{0x00,0x00,0x24,0x00,0x00},	// 0x3A
{0x00,0x80,0x64,0x00,0x00},	// 0x3B
{0x00,0x08,0x08,0x14,0x22},	// 0x3C
{0x00,0x14,0x14,0x14,0x14},	// 0x3D
{0x00,0x22,0x14,0x08,0x08},	// 0x3E
{0x00,0x01,0x29,0x05,0x02},	// 0x3F
{0x3C,0x42,0x59,0x55,0x5E},	// 0x40
{0x30,0x1C,0x12,0x1C,0x30},	// 0x41
{0x00,0x3E,0x2A,0x36,0x00},	// 0x42
{0x00,0x1C,0x22,0x22,0x22},	// 0x43
{0x00,0x3E,0x22,0x22,0x1C},	// 0x44
{0x00,0x3E,0x2A,0x2A,0x00},	// 0x45
{0x00,0x3E,0x0A,0x0A,0x00},	// 0x46
{0x00,0x1C,0x22,0x2A,0x3A},	// 0x47
{0x00,0x3E,0x08,0x08,0x3E},	// 0x48
{0x00,0x22,0x3E,0x22,0x00},	// 0x49
{0x00,0x22,0x22,0x1E,0x00},	// 0x4A
{0x00,0x3E,0x08,0x14,0x22},	// 0x4B
{0x00,0x3E,0x20,0x20,0x20},	// 0x4C
{0x3E,0x04,0x18,0x04,0x3E},	// 0x4D
{0x00,0x3E,0x04,0x08,0x3E},	// 0x4E
{0x1C,0x22,0x22,0x22,0x1C},	// 0x4F
{0x00,0x3E,0x0A,0x0A,0x04},	// 0x50
{0x1C,0x22,0x22,0x62,0x9C},	// 0x51
{0x00,0x3E,0x0A,0x14,0x20},	// 0x52
{0x00,0x24,0x2A,0x12,0x00},	// 0x53
{0x02,0x02,0x3E,0x02,0x02},	// 0x54
{0x00,0x1E,0x20,0x20,0x1E},	// 0x55
{0x00,0x0E,0x30,0x30,0x0E},	// 0x56
{0x0E,0x30,0x0C,0x30,0x0E},	// 0x57
{0x22,0x14,0x08,0x14,0x22},	// 0x58
{0x02,0x04,0x38,0x04,0x02},	// 0x59
{0x00,0x32,0x2A,0x2A,0x26},	// 0x5A
{0x00,0x00,0x7F,0x41,0x00},	// 0x5B
{0x01,0x06,0x18,0x60,0x00},	// 0x5C
{0x00,0x41,0x7F,0x00,0x00},	// 0x5D
{0x18,0x06,0x01,0x06,0x18},	// 0x5E
{0x40,0x40,0x40,0x40,0x40},	// 0x5F
{0x00,0x01,0x02,0x00,0x00},	// 0x60
{0x00,0x34,0x34,0x38,0x20},	// 0x61
{0x00,0x3F,0x24,0x24,0x18},	// 0x62
{0x00,0x18,0x24,0x24,0x00},	// 0x63
{0x18,0x24,0x24,0x3F,0x00},	// 0x64
{0x00,0x18,0x2C,0x28,0x00},	// 0x65
{0x00,0x04,0x3E,0x05,0x05},	// 0x66
{0x00,0x58,0x54,0x54,0x3C},	// 0x67
{0x00,0x3F,0x08,0x04,0x38},	// 0x68
{0x00,0x04,0x3D,0x00,0x00},	// 0x69
{0x00,0x44,0x44,0x3D,0x00},	// 0x6A
{0x00,0x3F,0x08,0x14,0x20},	// 0x6B
{0x00,0x01,0x3F,0x00,0x00},	// 0x6C
{0x3C,0x08,0x3C,0x08,0x3C},	// 0x6D
{0x00,0x3C,0x08,0x04,0x38},	// 0x6E
{0x00,0x18,0x24,0x24,0x18},	// 0x6F
{0x00,0x7C,0x24,0x24,0x18},	// 0x70
{0x18,0x24,0x24,0x7C,0x00},	// 0x71
{0x00,0x3C,0x08,0x04,0x00},	// 0x72
{0x00,0x28,0x2C,0x14,0x00},	// 0x73
{0x00,0x04,0x1E,0x24,0x04},	// 0x74
{0x00,0x1C,0x20,0x10,0x3C},	// 0x75
{0x00,0x0C,0x30,0x30,0x0C},	// 0x76
{0x0C,0x30,0x1C,0x30,0x0C},	// 0x77
{0x00,0x24,0x18,0x18,0x24},	// 0x78
{0x40,0x4C,0x70,0x30,0x0C},	// 0x79
{0x00,0x34,0x2C,0x2C,0x00},	// 0x7A
{0x00,0x08,0x36,0x41,0x00},	// 0x7B
{0x00,0x00,0x7F,0x00,0x00},	// 0x7C
{0x00,0x41,0x36,0x08,0x00},	// 0x7D
{0x10,0x08,0x08,0x10,0x08},	// 0x7E
{0x00,0x3C,0x22,0x3C,0x00},	// 0x7F
{0x00,0x1C,0xA2,0x62,0x22},	// 0x80
{0x00,0x1D,0x20,0x10,0x3D},	// 0x81
{0x00,0x18,0x2C,0x2A,0x01},	// 0x82
{0x00,0x36,0x35,0x39,0x22},	// 0x83
{0x00,0x35,0x34,0x39,0x20},	// 0x84
{0x01,0x36,0x34,0x38,0x20},	// 0x85
{0x00,0x36,0x35,0x3A,0x20},	// 0x86
{0x00,0x18,0xA4,0x64,0x00},	// 0x87
{0x00,0x1A,0x2D,0x29,0x02},	// 0x88
{0x00,0x19,0x2C,0x29,0x00},	// 0x89
{0x01,0x1A,0x2C,0x28,0x00},	// 0x8A
{0x00,0x05,0x3C,0x01,0x00},	// 0x8B
{0x00,0x06,0x3D,0x01,0x02},	// 0x8C
{0x01,0x06,0x3C,0x00,0x00},	// 0x8D
{0x30,0x1D,0x12,0x1D,0x30},	// 0x8E
{0x30,0x1A,0x15,0x1A,0x30},	// 0x8F
{0x00,0x3E,0x2A,0x2A,0x01},	// 0x90
{0x34,0x14,0x18,0x2C,0x28},	// 0x91
{0x30,0x1C,0x12,0x3E,0x2A},	// 0x92
{0x02,0x19,0x25,0x26,0x18},	// 0x93
{0x00,0x19,0x24,0x24,0x19},	// 0x94
{0x01,0x1A,0x24,0x24,0x18},	// 0x95
{0x02,0x1D,0x21,0x12,0x3C},	// 0x96
{0x00,0x1D,0x22,0x10,0x3C},	// 0x97
{0x40,0x4D,0x70,0x30,0x0D},	// 0x98
{0x1D,0x22,0x22,0x22,0x1D},	// 0x99
{0x01,0x1E,0x20,0x21,0x1E},	// 0x9A
{0x00,0x58,0x34,0x2C,0x1A},	// 0x9B
{0x10,0x3C,0x2A,0x20,0x00},	// 0x9C
{0x5C,0x32,0x2A,0x26,0x1D},	// 0x9D
{0x00,0x24,0x18,0x18,0x24},	// 0x9E
{0x00,0x48,0x3E,0x09,0x00},	// 0x9F
{0x00,0x34,0x34,0x3A,0x21},	// 0xA0
{0x00,0x04,0x3C,0x02,0x01},	// 0xA1
{0x00,0x18,0x24,0x26,0x19},	// 0xA2
{0x00,0x1C,0x20,0x12,0x3D},	// 0xA3
{0x00,0x3D,0x09,0x05,0x39},	// 0xA4
{0x01,0x3F,0x05,0x09,0x3F},	// 0xA5
{0x00,0x1D,0x15,0x1E,0x00},	// 0xA6
{0x00,0x0E,0x11,0x0E,0x00},	// 0xA7
{0x00,0x40,0x5A,0x20,0x00},	// 0xA8
{0x1E,0x21,0x3F,0x37,0x1E},	// 0xA9
{0x00,0x08,0x08,0x38,0x00},	// 0xAA
{0x21,0x17,0x0C,0x36,0x2D},	// 0xAB
{0x21,0x17,0x08,0x16,0x39},	// 0xAC
{0x00,0x00,0x74,0x00,0x00},	// 0xAD
{0x08,0x14,0x2A,0x14,0x22},	// 0xAE
{0x22,0x14,0x2A,0x14,0x08},	// 0xAF
{0x55,0x00,0x55,0x00,0x55},	// 0xB0
{0x55,0xAA,0x55,0xAA,0x55},	// 0xB1
{0xFF,0x55,0xFF,0x55,0xFF},	// 0xB2
{0x00,0x00,0xFF,0x00,0x00},	// 0xB3
{0x08,0x08,0xFF,0x00,0x00},	// 0xB4
{0x30,0x1C,0x12,0x1D,0x30},	// 0xB5
{0x30,0x1A,0x15,0x19,0x32},	// 0xB6
{0x30,0x1D,0x12,0x1C,0x30},	// 0xB7
{0x3E,0x41,0x5D,0x55,0x3E},	// 0xB8
{0x14,0xF7,0x00,0xFF,0x00},	// 0xB9
{0x00,0xFF,0x00,0xFF,0x00},	// 0xBA
{0x14,0xF4,0x04,0xFC,0x00},	// 0xBB
{0x14,0x17,0x10,0x1F,0x00},	// 0xBC
{0x00,0x1C,0x36,0x14,0x00},	// 0xBD
{0x02,0x14,0x38,0x14,0x02},	// 0xBE
{0x08,0x08,0xF8,0x00,0x00},	// 0xBF
{0x00,0x00,0x0F,0x08,0x08},	// 0xC0
{0x08,0x08,0x0F,0x08,0x08},	// 0xC1
{0x08,0x08,0xF8,0x08,0x08},	// 0xC2
{0x00,0x00,0xFF,0x08,0x08},	// 0xC3
{0x08,0x08,0x08,0x08,0x08},	// 0xC4
{0x08,0x08,0xFF,0x08,0x08},	// 0xC5
{0x02,0x35,0x35,0x3A,0x21},	// 0xC6
{0x32,0x19,0x15,0x1A,0x31},	// 0xC7
{0x00,0x1F,0x10,0x17,0x14},	// 0xC8
{0x00,0xFC,0x04,0xF4,0x14},	// 0xC9
{0x14,0x17,0x10,0x17,0x14},	// 0xCA
{0x14,0xF4,0x04,0xF4,0x14},	// 0xCB
{0x00,0xFF,0x00,0xF7,0x14},	// 0xCC
{0x14,0x14,0x14,0x14,0x14},	// 0xCD
{0x14,0xF7,0x00,0xF7,0x14},	// 0xCE
{0x22,0x1C,0x14,0x1C,0x22},	// 0xCF
{0x19,0x25,0x27,0x1D,0x00},	// 0xD0
{0x08,0x3E,0x2A,0x22,0x1C},	// 0xD1
{0x00,0x3F,0x2B,0x2B,0x00},	// 0xD2
{0x01,0x3E,0x2A,0x2A,0x01},	// 0xD3
{0x01,0x3E,0x2A,0x2A,0x00},	// 0xD4
{0x00,0x04,0x3C,0x00,0x00},	// 0xD5
{0x00,0x22,0x3E,0x22,0x01},	// 0xD6
{0x00,0x23,0x3F,0x23,0x00},	// 0xD7
{0x01,0x22,0x3E,0x22,0x01},	// 0xD8
{0x08,0x08,0x0F,0x00,0x00},	// 0xD9
{0x00,0x00,0xF8,0x08,0x08},	// 0xDA
{0xFF,0xFF,0xFF,0xFF,0xFF},	// 0xDB
{0xF0,0xF0,0xF0,0xF0,0xF0},	// 0xDC
{0x00,0x00,0xE7,0x00,0x00},	// 0xDD
{0x01,0x22,0x3E,0x22,0x00},	// 0xDE
{0x0F,0x0F,0x0F,0x0F,0x0F},	// 0xDF
{0x1C,0x22,0x22,0x22,0x1D},	// 0xE0
{0x00,0x3E,0x01,0x2E,0x10},	// 0xE1
{0x1C,0x23,0x23,0x23,0x1C},	// 0xE2
{0x1D,0x22,0x22,0x22,0x1C},	// 0xE3
{0x02,0x19,0x25,0x26,0x19},	// 0xE4
{0x1D,0x23,0x23,0x23,0x1C},	// 0xE5
{0x00,0x7C,0x20,0x10,0x3C},	// 0xE6
{0x00,0x7F,0x24,0x24,0x18},	// 0xE7
{0x00,0x3E,0x14,0x14,0x08},	// 0xE8
{0x1E,0x20,0x20,0x1E,0x01},	// 0xE9
{0x00,0x1F,0x21,0x21,0x1F},	// 0xEA
{0x01,0x1E,0x20,0x20,0x1E},	// 0xEB
{0x40,0x4C,0x30,0x32,0x0D},	// 0xEC
{0x02,0x04,0x3A,0x05,0x02},	// 0xED
{0x01,0x01,0x01,0x01,0x01},	// 0xEE
{0x00,0x00,0x02,0x01,0x00},	// 0xEF
{0x00,0x08,0x08,0x08,0x00},	// 0xF0
{0x00,0x28,0x3C,0x28,0x00},	// 0xF1
{0xA0,0xA0,0xA0,0xA0,0xA0},	// 0xF2
{0x2B,0x1F,0x08,0x16,0x39},	// 0xF3
{0x06,0x7F,0x01,0x7F,0x00},	// 0xF4
{0x00,0x4A,0x55,0x29,0x00},	// 0xF5
{0x00,0x08,0x2A,0x08,0x00},	// 0xF6
{0x00,0x80,0x40,0x00,0x00},	// 0xF7
{0x00,0x06,0x09,0x09,0x06},	// 0xF8
{0x00,0x01,0x00,0x01,0x00},	// 0xF9
{0x00,0x00,0x08,0x00,0x00},	// 0xFA
{0x00,0x11,0x1F,0x10,0x00},	// 0xFB
{0x00,0x15,0x15,0x0A,0x00},	// 0xFC
{0x00,0x19,0x15,0x12,0x00},	// 0xFD
{0x00,0x3C,0x3C,0x3C,0x3C},	// 0xFE
{0x00,0x00,0x00,0x00,0x00} 	// 0xFF
};
#endif