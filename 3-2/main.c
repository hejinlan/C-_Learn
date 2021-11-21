#include <REGX52.H>

void delayms(unsigned int xms)
{
	unsigned char i,j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		}while (--i);
	}
}

unsigned char lednum = 0;
void main()
{
	
	while(1){
		if(P3_1 == 0){
			delayms(20);
			while(P3_1 == 0);
			delayms(20);
			
			if(lednum >= 8)
				lednum = 0;
			P2 = ~(0x01<<lednum);
			lednum++;
			
		}
		
		if(P3_0 == 0){
			delayms(20);
			while(P3_0 == 0);
			delayms(20);
			
			if(lednum == 0)
				lednum = 8;
			else
				lednum--;
			P2 = ~(0x01<<lednum);
			
			
		}
	}
}