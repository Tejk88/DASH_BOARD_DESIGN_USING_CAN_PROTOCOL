#include <LPC21xx.H>
#include "header.h"

#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3((IOPIN0>>16)&1)
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)

CAN2 v1,v2,v3;
u32 temp,result,flag1=0,flag2=0,flag3=0;
float vout,temperature;
int main()
{
can2_init();
adc_init();
lcd_init();
uart0_init(9600);

IOSET0|=LED1|LED2|LED3;
v1.id=0x500;
v1.rtr=0;
v1.dlc=1;
v1.byteA=0;


v2.id=0x501;
v2.rtr=0;
v2.dlc=1;
v2.byteA=0;


v3.id=0x502;
v3.rtr=0;
v3.dlc=1;
v3.byteA=0;

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
          v2.byteA=(0x07);
 		  can2_tx(v2);
		  IOCLR0=LED2;
}
else
{
        v2.byteA=(0x08);
 	   	can2_tx(v2);
		IOSET0=LED2;
  }
 }
} 
if(sw3==0)
{
while(sw3==0);
{
flag3^=1;
if(flag3)
{
          v3.byteA=(0x09);
 		  can2_tx(v3);
		  IOCLR0=LED3;
}
else
{
        v3.byteA=(0x10);
 	   	can2_tx(v3);
		IOSET0=LED3;
    }
   }
  }
temp=adc_read(1);
 		vout=(temp*3.3)/1023;
		temperature=(vout-0.5)/0.01;
		uart0_atoi(temperature);
		uart0_tx(' ');

result=adc_read(2);//Read Pot.
vout=(result*3.3)/1023;
uart0_atoi(result);
//lcd_data(temp);	
uart0_tx(' ');
////lcd_atof(vout);	
uart0_atof(vout);
uart0_tx_string("\r\n");


 }
}



	       
	  
 





   //config_vic_for_uart0();
//config_uart0_interrupt();



	
//#include <LPC21xx.H>
//#include "header.h"
//#define sw1 ((IOPIN0>>14)&1)
//#define sw2 ((IOPIN0>>15)&1)
//#define sw3 ((IOPIN0>>16)&1)
//CAN1 s1;
//int main()
//{
//adc_init();
//lcd_init();
//uart0_init(9600);	
//u32 temp;
//float vout,temperature;
//while(1)
//{
//if(sw1==0)
//{
//while(sw1==0);
//	{
//    	 
//	
//	}
//
//}	
///*temp=adc_read(2);//Read Pot.
//vout=(temp*3.3)/1023;
//uart0_atoi(temp);
////lcd_data(temp);	
//uart0_tx(' ');
////lcd_atof(vout);	
//uart0_atof(vout);
//uart0_tx_string("\r\n");*/	
//
//temperature=(vout-0.5)/0.01;
//uart0_atof(temperature);
//uart0_tx_string("\r\n");
//		
//#include <LPC21xx.H>
//#include "header.h"
//#define LED (1<<17)
//#define LED1 (1<<17)
//#define LED2 (1<<18)
//#define LED3 (1<<19)
  //can1_init();
//CAN1 r1;

//
//u32 temp;
//float vout,temperature;
//	


   //lcd_init();	
//	lcd_cgram1();
//	lcd_cmd(0x83);
//	lcd_cmd(0x0c);
//	lcd_data(0);//calling to page0 *MANDATORY*
//	
//	lcd_cgram2();
//	lcd_cmd(0x80);
//	lcd_data(2);//calling to page0 *MANDATORY*

//	lcd_cgram3();
//    lcd_cmd(0x87);
//	lcd_cmd(0x0c);
//	lcd_data(4);//calling to page0 *MANDATORY*
//		lcd_string("D");

















//}
// IODIR0=IODIR0|LED1;
//IODIR0=IODIR0|LED3;
//IODIR0=IODIR0|LED2;
//
//IOSET0=IOSET0|LED1;
//IOSET0=IOSET0|LED3;
//IOSET0=IOSET0|LED2;

//
//uart0_tx_string("Choose the option\r\n");
//uart0_tx_string("a.Turn ON Headlight\r\n");
//uart0_tx_string("b.Turn OFF Headlight\r\n");
//uart0_tx_string("c.Turn ON Left Indicator\r\n");
//uart0_tx_string("d.Turn OFF Left Indicator\r\n");
//uart0_tx_string("e.Turn ON Right Indicator\r\n");
//uart0_tx_string("f.Turn OFF Right Indicator\r\n");	\







 /*case 'c':v1.byteA=(0x07);
 		can2_tx(v1);
		 IOCLR0=LED2;
		 break;
 case 'd':v1.byteA=(0x08);
 		can2_tx(v1);
		IOSET0=LED2;
		break;
 case 'e':v1.byteA=(0x09);
 		can2_tx(v1);
		IOCLR0=LED3;
		break;
 case 'f':v1.byteA=(0x10);
 		can2_tx(v1);
		IOSET0=LED3;
		break;
 default:uart0_tx_string("choose the correct option\r\n");
	break;*/

