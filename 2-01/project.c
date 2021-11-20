#include <REGX52.H>

void delayms(unsigned int xms)
{
	unsigned char i,j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		}while (--i);
		xms--;
	}
}

void main()
{
	while(1){
		if(P3_1 == 0){
			delayms(20);
			while(P3_1 == 0);
			delayms(20);
			
			P2_0 = ~P2_0;
		}
	}
}