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
		unsigned int i;
		for(i = 0; i < 8; i++){
			delayms(1000);
			P2 = ~(1 << i);
		}
	}
}