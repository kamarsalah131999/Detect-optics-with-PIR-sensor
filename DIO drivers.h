/*
 * DIO_drivers.h
 *
 * Created: 4/09/2021 4:25:09 PM
 *  Author: kamar salah
 */ 


#ifndef DIO DRIVERS_H_
#define DIO DRIVERS_H_

/*  function describtion:
this function detrmine the pin in given port is (input=0 , output=1)
*/
void DIO_vset_pin_dir(char port_name, char pin_num, char dir);

/* function description:
this function can use only if modified bin output. uses it writing in given bin
*/
void DIO_vwrite_pin(char port_name, char pin_num, char out_value);

/* function description:
taggle value of the pin in given port
*/
void DIO_vtaggle_pin(char port_name, char pin_num);

/* function description:
this function can use only if modified bin input. uses it reade the value in pin register 
*/
unsigned char DIO_u8read_pin(char port_name, char pin_num);

/* function description:
this function detrmine the port direction (input=0, output=1)
*/
void DIO_vset_port_dir(char port_name, char direction);

/*function description:
this function can use only if modified port is output. uses it writing in given port
*/
void DIO_vwrite_port(char port_name, char out_value);

/* function description:
taggle value of the given port
*/
void DIO_vtaggle_port(char port_name);

/* function description :
this function can use only if modified bin input. uses it reade the value in given port
*/
unsigned char DIO_u8read_port(char port_name);

/*function description:
write on law nibble in given port
*/
void DIO_vwrite_law_nibble (char port_name, char value);

/*function description:
write on high  nibble in given port
*/
void DIO_vwrite_high_nibble (char port_name, char value);




#endif /* DIO DRIVERS_H_ */