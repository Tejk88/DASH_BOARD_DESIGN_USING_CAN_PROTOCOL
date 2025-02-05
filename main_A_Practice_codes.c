//////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include <LPC21xx.H>
#include "header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
CAN2 v1;
u32 temp,result=0,battery=0;
u32 flag1=0,flag2=0,flag3=0;
u32 vout,temperature;
extern int timer1,timer0;
int main()
{
	can2_init();
	adc_init();
	lcd_init();
	uart0_init(9600);

	config_vic_for_timer0();
	timer0_config();
	config_vic_for_timer1();
	timer1_config();	



	IODIR0=IOSET0|=LED1|LED2|LED3;
	v1.id=0x500;
	v1.rtr=0;
	v1.dlc=7;
	v1.byteA=0;

	while(1)
	{
		if(sw1==0)
		{
			while(sw1==0);
			{
				flag1^=1;
				if(flag1)
				{
					v1.byteA=(0x05);
					can2_tx(v1);
					IOCLR0=LED1;
				}
				else
				{
					v1.byteA=(0x06);
					can2_tx(v1);
					IOSET0=LED1;
				}
				v1.byteA=0;
			}
		} 
		if(sw2==0)
		{
			while(sw2==0);
			{
				flag2^=1;
				if(flag2)
				{
					v1.byteA=(0x07);
					can2_tx(v1);
					IOCLR0=LED2;
				}
				else
				{
					v1.byteA=(0x08);
					can2_tx(v1);
					IOSET0=LED2;
				}
				v1.byteA=0;
			}
		} 
		if(sw3==0)
		{
			while(sw3==0);
			{
				flag3^=1;
				if(flag3)
				{
					v1.byteA=(0x09);
					can2_tx(v1);
					IOCLR0=LED3;
				}
				else
				{
					v1.byteA=(0x10);
					can2_tx(v1);
					IOSET0=LED3;
				}
				v1.byteA=0;
			}
		}
		temp=adc_read(1);//for temperature
//		vout=(temp*3.3)/1023;
//		temperature=((vout-0.5)/0.01);
		//uart0_atoi(temperature);	   	
		//uart0_tx(' ');

		result=adc_read(2);//Read Pot.(Battery)
//		vout=(result*3.3)/1023;
//		battery=(vout*30.30);
		//uart0_atof(battery);

		v1.byteA=(v1.byteA&0x000000FF)|(temp<<8)|(result<<16);

		if(timer1==1){
			//delay_ms(2);
			timer1=0;

			uart0_tx_string("Temperature ");
			can2_tx(v1);
			uart0_tx(((v1.byteA>>8)&0xFF)/10+48);
			uart0_tx(((v1.byteA>>8)&0xFF)%10+48);
			uart0_tx_string("\r\n");
		}	

		if(timer0==1){
			//delay_ms(2);
			timer0=0;
			uart0_tx_string("battery");
			can2_tx(v1);
			uart0_tx(((v1.byteA>>16&(0xFFFF))/100)+48);
			uart0_tx((((v1.byteA>>16&(0xFFFF))/10)%10)+48);
			uart0_tx(((v1.byteA>>16&(0xFFFF))%10)+48);
			
			uart0_tx_string("\r\n");
		}
	}
}*/ 








