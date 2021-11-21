#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"

unsigned int Sec,Min, Hour;
void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
	  LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);	
		LCD_ShowNum(2,7,Sec,2);
	}

}


void Timer0_Routine() interrupt 1
{
	  static unsigned int T0Count;
		TL0 = 0x18;
		TH0 = 0xFC;
		T0Count++;
	  if(T0Count >= 1000)
		{
			T0Count = 0;
			P2_0 = ~P2_0;
			Sec++;
			if(Sec > 60)
			{
				Sec = 0;
				Min++;
				if(Min > 60)
				{
					Min = 0;
					Hour++;
					if(Hour > 24)
					{
						Hour = 0;
					}
				}
			}
		}
}