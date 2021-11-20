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

void main()
{
	unsigned char lednum = 0;
	while(1){
		if(P3_1 == 0){
			delayms(20);
			while(P3_1 == 0);
			delayms(20);
			
			lednum++;
			P2 = ~lednum;
			
		}
	}
}