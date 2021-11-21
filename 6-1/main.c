#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"
#include <windows.h>


unsigned char keynumber;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Test_Info");

	while(1)
	{
		 keynumber = MatrixKey();
		 LCD_ShowString(1,1,"Test_Info");
		 if(keynumber)
		 {
			 LCD_ShowNum(2,1,keynumber,2);
			 Sleep(1000);
		 }
	}
}
