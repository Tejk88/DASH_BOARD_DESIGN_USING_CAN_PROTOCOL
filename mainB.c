#include <LPC21xx.H>
#include "header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
u32 temp2,vout,temperature,speed;
extern u32 flag; //CAN Flag
CAN2 v1;
extern unsigned int timer1;
extern unsigned int timer2;
u32 sflag1=0,sflag2=0; //indi. flags
u32 lower=0;
int main()
{
	can2_init();
	uart0_init(9600);
	lcd_init();
	lcd_cgram();
	lcd_cmd(0x80);
	delay_ms(100);
	lcd_data(0);
	lcd_cmd(0x8F);
	lcd_data(1);
	lcd_cmd(0x0C);
	IODIR0=LED1|LED2|LED3;
	IOSET0=LED1|LED2|LED3;
	config_vic_for_timer1();
	timer1_config();
	config_vic_for_CAN2();

	while(1)
	{
		if(flag==1)
		{
			flag=0;
			temp2=((v1.byteA)&(0xFFFF)); 
			vout=(280*temp2)/1023;
			lcd_cmd(0xc1);
			lcd_string("speed:");
			lcd_cmd(0xc7);
			lcd_data((((vout/100))+48));
			lcd_data(((((vout/10)%10))+48));
			lcd_data((((temperature%10))+48));
		
		
			lcd_string("kmph");
		
		
			if((v1.byteA&0xFF)==0x05)
			{
				lcd_cmd(0x87);
				lcd_data(2);
				lcd_data('D');
				IOCLR0=LED1;
			}
			if((v1.byteA&0xFF)==0x06)
			{
				lcd_cmd(0x87);
				lcd_data(' ');
				lcd_data(' ');
				IOSET0=LED1;
			}
		
			if((v1.byteA&0xFF)==0x07) //L ON
			{
				sflag1=1;
			}
			if((v1.byteA&0xFF)==0x09)  //R ON
			{
				sflag2=1;
			}
		
			if(sflag1==1) //for L indi.
			{
				if(timer1==1)
				{
					lcd_cmd(0x80);
					lcd_data(0);
					IOCLR0=LED2;
				}
				else
				{
					lcd_cmd(0x80);
					lcd_data(' ');
					IOSET0=LED2;
				}
			}
			if(((v1.byteA&0xFF)==0x08) || ((v1.byteA&0xFF)==0x09))
			{
				sflag1=0;
				lcd_cmd(0x80);
				lcd_data(0);
				IOSET0=LED2;
				}
				
				if(sflag2==1)
				{
					if(timer2==1)
					{
					lcd_cmd(0x8F);
					lcd_data(1);
					IOCLR0=LED3;
					}
					else
					{
						lcd_cmd(0x8F);
						lcd_data(' ');
						IOSET0=LED3;
					}
			}
			if(((v1.byteA&0xFF)==0x07) || ((v1.byteA&0xFF)==0x10))
			{
				sflag2=0;
				lcd_cmd(0x8F);
				lcd_data(1);
				IOSET0=LED3;	
			}
		}
	}
}

