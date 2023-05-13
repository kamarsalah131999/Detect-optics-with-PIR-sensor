/*
 * LCD_driver.c
 *
 * Created: 23/09/2021 4:48:49 PM
 *  Author: kamar salah
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD driver.h"
#include "DIO drivers.h"
#include "LCD configuration1.h"

void LCD_vinit ()
{
	
	_delay_ms(200);
	#if defined eight_bit_mod
	DIO_vset_pin_dir('A',0,1);                             //pin 0 on port A is output
	DIO_vset_pin_dir('A',1,1);                            //pin 1 on port A is output
	DIO_vset_pin_dir('A',2,1);                           //pin 2 on port A is output
	DIO_vset_pin_dir('A',3,1);                          //pin 3 on port A is output
	DIO_vset_pin_dir('A',4,1);                         //pin 4 on port A is output
	DIO_vset_pin_dir('A',5,1);                        //pin 5 on port A is output
	DIO_vset_pin_dir('A',6,1);                       //pin 6 on port A is output
	DIO_vset_pin_dir('A',7,1);                      //pin 7 on port A is output
	DIO_vset_pin_dir('B',EN,1);                    //pin 0 on port B is output
	DIO_vset_pin_dir('B',RW,1);                   //pin 1 on port B is output
	DIO_vset_pin_dir('B',RS,1);                  //pin 2 on port B is output
	DIO_vwrite_pin('B',RW,0);                   // RW=0 to send commands
	LCD_vsend_com(EIGHT_BIT_MODE);             // connection is 8 bit mode
	_delay_ms(1);
	LCD_vsend_com(CURSOR_ON_DESPLAY_ON);     // desplay cursor on
	_delay_ms(1);
	LCD_vclear_screen();                     // clear screen
	_delay_ms(10);
	LCD_vsend_com(ENTRY_MODE);               // shift cursor to next column
	_delay_ms(1);
	
	#elif defined four_bit_mode
	DIO_vset_pin_dir('A',4,1);                        //pin 4 on port A is output
	DIO_vset_pin_dir('A',5,1);                       //pin 5 on port A is output
	DIO_vset_pin_dir('A',6,1);                      //pin 6 on port A is output
	DIO_vset_pin_dir('A',7,1);                     //pin 7 on port A is output
	DIO_vset_pin_dir('B',EN,1);                   //pin 0 on port B is output
	DIO_vset_pin_dir('B',RW,1);                  //pin 1 on port B is output
	DIO_vset_pin_dir('B',RS,1);                 //pin 2 on port B is output
	DIO_vwrite_pin('B',RW,0);                  // RW=0 to send commands
	LCD_vsend_com(RETURN_HOME);                // return the cursour to col 1 in raw 1
	_delay_ms(10);
	LCD_vsend_com(FOUR_BIT_MODE);             // conniction with 4 bit mode
	_delay_ms(1);
	LCD_vsend_com(CURSOR_ON_DESPLAY_ON);     // desplay cursor on
	_delay_ms(1);
	LCD_vclear_screen();                     // clear screen
	_delay_ms(10);
	LCD_vsend_com(ENTRY_MODE);               // shift cursor to next column
	#endif
	_delay_ms(1);
	
}
static send_faling_edge (void)
{
	DIO_vwrite_pin('B',EN,1);          // conected enable with pin 1 on port B
	_delay_ms(2);
	DIO_vwrite_pin('B',EN,0);
	_delay_ms(2);
	
}

void LCD_vsend_char (char data)
{
	#if defined eight_bit_mod
	
	DIO_vwrite_port('A',data);        // appare sending data on port A
	DIO_vwrite_pin('B',RS,1);         //  selected Rigister Selector  to write data
	send_faling_edge();
	
	#elif defined four_bit_mode
	DIO_vwrite_law_nibble('A',data>>4) ;            // sending 4 most bit
	DIO_vwrite_pin('B',RS,1);
	LCD_send_faling_edge();
	DIO_vwrite_law_nibble('A',data) ;               // sending 4 bit list
	LCD_send_faling_edge();
	#endif
}

void LCD_vsend_com (char cmd)
{
	#if defined eight_bit_mod
	DIO_vwrite_port('A',cmd);        // appare sending data on port A
	DIO_vwrite_pin('B',RS,0);         //  selected Rigister Selector  to write data
	send_faling_edge();
	_delay_ms(1);
	
	#elif defined four_bit_mode
	DIO_vwrite_law_nibble('A',cmd>>4) ;            // sending 4 most bit
	DIO_vwrite_pin('B',RS,1);
	LCD_send_faling_edge();
	DIO_vwrite_law_nibble('A',cmd) ;               // sending 4 bit list
	LCD_send_faling_edge();
	#endif
	_delay_ms(1);
}

void LCD_vclear_screen ()
{
	LCD_vsend_com(0x01);
}

void LCD_vmove_cursor (char row, char coul)
{
	char data;
	if (row>2||row<1||coul>16||coul<1)
	{
		data= 0x80;                                       // move cursor to row 1 col 1
	}
	else if (row==1)
	{
		data=0x80+coul-1;                                // move cursor to row 1 given col
	}
	else if (row==2)
	{
		data=0xc0+coul-1;                                // move cursor to row 2 given col
	}
	LCD_vsend_com(data);
	_delay_ms(1);
}

void LCD_vsend_string (char *data)
{
	while ((*data)!='\0')                   // if pointer accses adress
	{
		LCD_vsend_char(*data);
		data++;
	}
}