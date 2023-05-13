/*
 * LCD_driver.h
 *
 * Created: 23/09/2021 4:49:08 PM
 *  Author: hp
 */ 


#ifndef LCD DRIVER_H_
#define LCD DRIVER_H_

#define EN 1
#define RS 0
#define RW 2
#define EIGHT_BIT_MODE 0x38
#define FOUR_BIT_MODE 0x28
#define CURSOR_ON_DESPLAY_ON 0x0e
#define ENTRY_MODE 0x06
#define RETURN_HOME 0x02

/*function description:
intialize lcd
*/
void LCD_vinit ();

/* function description :
send clock to enable
*/
static LCD_send_faling_edge (void);

/*function description:
sending char to data lines >> data register
*/
void LCD_vsend_char (char data);

/*function description:
sending comand to data lines >> command register
*/
void LCD_vsend_com (char cmd);

/*function description:
move curssor to spisific address
*/
void LCD_vmove_cursor (char row, char coul);

/*function description:
sending string to appare on lcd
*/
void LCD_vsend_string (char *data);

/* function description:
sending command >> clear screen
*/
void LCD_vclear_screen ();

#endif /* LCD DRIVER_H_ */