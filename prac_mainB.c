#include <LPC21xx.H>
#include "header.h"
CAN2 v1;
main()
{
	lcd_init();
//	lcd_cmd(0x80);
	lcd_cgram1();
	lcd_cgram2();
	lcd_cgram3();
	lcd_cmd(0x80);	
	lcd_data(0);
		
		
	lcd_data(1);
	
		
	lcd_data(2);
		lcd_data('D');
	
	
	}