/*
 * PIR sensor to detect opsticals.c
 *
 * Created: 8/05/2023 4:47:35 PM
 * Author : kamar salah
 */ 

#include <avr/io.h>
#include "LCD driver.h"
#include "LCD configuration1.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    LCD_vinit ();
    while (1) 
    {
		if (DIO_u8read_pin('D', 0)==1)                                              // recived reflected signal from transmited signal
		{
			LCD_vclear_screen ();
			LCD_vsend_string ("There is");
			LCD_vmove_cursor (2,1);
			LCD_vsend_string ("Opstical");
		}
		else                                                                     // not recived any reflected signal 
		{
			LCD_vclear_screen ();
			LCD_vsend_string ("There is");
			LCD_vmove_cursor (2,1);
			LCD_vsend_string ("No Opsticals");
		}
		_delay_ms(500);
			
    }
}

