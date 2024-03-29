#include "MatrixLED.h"

//动画数据
unsigned char code Animation[]={
	0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C,
	0x3C,0x42,0xA1,0x85,0x85,0xA1,0x42,0x3C,
	0x3C,0x42,0xA5,0x89,0x89,0xA5,0x42,0x3C,
};
unsigned char code strAnimation[]={
/*--  文字:  金  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x0C,0x1E,0x3B,0x7F,0x6F,0x3B,0x1F,

/*--  文字:  桐  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x1E,0x00,0x16,0x7F,0x7F,0x7F,0x7F,

/*--  文字:  是  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x5E,0x5E,0x7F,0x00,0x04,0x07,0x7F,

/*--  文字:  真  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x7D,0x6F,0x7F,0x7E,0x0E,0x00,0x21,

/*--  文字:  的  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x21,0x3F,0x7F,0x7F,0x7F,0x7F,0x63,

/*--  文字:  ！  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x00,0x3F,0x7F,0x64,0x7F,0x3F,0x7C,

/*--  文字:  ！  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x54,0x3F,0x00,0x00,0x00,0x3F,0x3F,

/*--  文字:  ！  --*/
/*--  宋体5;  此字体下对应的点阵为：宽x高=7x7   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=8x7  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

void main()
{
	  unsigned char i, offset = 0, Count = 0;
	  MatrixLED_Init();
		while(1)
		{
			for(i = 0; i < 8; i++){
					MatrixLED_ShowColumn(i, strAnimation[i + offset]);
			}
			
			Count++;
			if(Count > 10){
			   Count = 0;
				 offset+= 1; //offset++;// offset+= 8;
				 if(offset > 7*8){
						offset  = 0;
				 }
			}
		}
}