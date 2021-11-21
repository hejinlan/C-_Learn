#include <REGX52.H>
#include "LCD1602.h"

void main()
{
	LCD_Init();
	
	while(1)
	{
			LCD_ShowString(1,1,"Hello,LYT&JC 687");
			LCD_ShowString(2,1,"JTSZD JC&LYT 687");
	}
	
}