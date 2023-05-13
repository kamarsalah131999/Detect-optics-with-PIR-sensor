/*
 * DIO_drivers.c
 *
 * Created: 4/09/2021 4:25:38 PM
 *  Author: kamar salah
 */ 

#include <avr/io.h>
#include "DIO drivers.h"
#include "macros.h"


void DIO_vset_pin_dir(char port_name, char pin_num, char dir)
{
  switch (port_name)
  {
	  case 'A':
	  case 'a':
	  if (dir==1)
	  {
		  SET_BIT(DDRA, pin_num);       // set the direction of the given bin in port A as output
      }
	  else
	  {
		  CLEAR_BIT(DDRA, pin_num);    // clear the direction of the given bin in port A as input
	  }
	  break;
	  
	  case 'B':
	  case 'b':
	  if (dir==1)
	  {
		  SET_BIT(DDRB, pin_num);       // set the direction of the given bin in port B as output
	  }
	  else
	  {
		  CLEAR_BIT(DDRB, pin_num);    // clear the direction of the given bin in port B as input
	  }
	  break;
	  
	  case 'C':
	  case 'c':
	  if (dir==1)
	  {
		  SET_BIT(DDRC, pin_num);       // set the direction of the given bin in port C as output
	  }
	  else
	  {
		  CLEAR_BIT(DDRC, pin_num);    // clear the direction of the given bin in port C as input
	  }
	  break;
	  
	  case 'D':
	  case 'd':
	  if (dir==1)
	  {
		  SET_BIT(DDRD, pin_num);       // set the direction of the given bin in port D as output
	  }
	  else
	  {
		  CLEAR_BIT(DDRD, pin_num);    // clear the direction of the given bin in port D as input
	  }
	  break;
  }
}

void DIO_vwrite_pin(char port_name, char pin_num, char out_value)
{
	switch (port_name)
	{
		 case 'A':
		 case 'a':
		 if (out_value==1)
		 {
			 SET_BIT(PORTA, pin_num);       // set the direction of the given bin in port A is high
		 }
		 else
		 {
			 CLEAR_BIT(PORTA, pin_num);    // clear the direction of the given bin in port A is law
		 }
		 break;
		 
		 case 'B':
		 case 'b':
		 if (out_value==1)
		 {
			 SET_BIT(PORTB, pin_num);       // set the direction of the given bin in port B is high
		 }
		 else
		 {
			 CLEAR_BIT(PORTB, pin_num);    // clear the direction of the given bin in port B is law
		 }
		 break;
		 
		 case 'C':
		 case 'c':
		 if (out_value==1)
		 {
			 SET_BIT(PORTC, pin_num);       // set the direction of the given bin in port C is high
		 }
		 else
		 {
			 CLEAR_BIT(PORTC, pin_num);    // clear the direction of the given bin in port C is law
		 }
		 break;
		 
		 case 'D':
		 case 'd':
		 if (out_value==1)
		 {
			 SET_BIT(PORTD, pin_num);       // set the direction of the given bin in port D is high
		 }
		 else
		 {
			 CLEAR_BIT(PORTD, pin_num);    // clear the direction of the given bin in port D is law
		 }
		 break;
	}
}

void DIO_vtaggle_pin(char port_name, char pin_num)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin_num);           // taggle the value of the given bin in portA
		break;
		
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin_num);           // taggle the value of the given bin in portB
		break;
		
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin_num);           // taggle the value of the given bin in portC
		break;
		
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin_num);           // taggle the value of the given bin in portD
		break;
	}
}

unsigned char DIO_u8read_pin(char port_name, char pin_num)
{
	unsigned char  value=0;
	switch(port_name)
	{
		case 'A':
		case 'a':
		value= READ_BIT(PINA, pin_num);       // read the value from the given pin in port A
		break;
		
		case 'B':
		case 'b':
		value= READ_BIT(PINB, pin_num);       // read the value from the given pin in port B
		break;
		
		case 'C':
		case 'c':
		value= READ_BIT(PINC, pin_num);       // read the value from the given pin in port C
		break;
		
		case 'D':
		case 'd':
		value= READ_BIT(PIND, pin_num);       // read the value from the given pin in port D
		break;
	}
	return value;
}

void DIO_vset_port_dir(char port_name, char direction)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		DDRA=direction;            // set direction of port A
		break;
		
		case 'B':
		case 'b':
		DDRB=direction;            // set direction of port B
		break;
		
		case 'C':
		case 'c':
		DDRC=direction;            // set direction of port C
		break;
		
		case 'D':
		case 'd':
		DDRD=direction;            // set direction of port D
		break;
	}
}

void DIO_vwrite_port(char port_name, char out_value)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		PORTA= out_value;        // write the given value in port A
		break;
		
		case 'B':
		case 'b':
		PORTB= out_value;       // write the given value in port B
		break;
		
		case 'C':
		case 'c':
		PORTC= out_value;      // write the given value in port C
		break;
		
		case 'D':
		case 'd':
		PORTD= out_value;     // write the given value in port D
		break;
	}
}

void DIO_vtaggle_port(char port_name)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA;      // taggle the value of given port
		break;
		
		case 'B':
		case 'b':
		PORTB=~PORTB;      // taggle the value of given port
		break;
		
		case 'C':
		case 'c':
		PORTC=~PORTC;      // taggle the value of given port
		break;
		
		case 'D':
		case 'd':
		PORTD=~PORTD;      // taggle the value of given port
		break;
	}
}

unsigned char DIO_u8read_port(char port_name)
{
	unsigned char port_value=0;
	switch(port_name)
	{
		case 'A':
		case 'a':
		port_value= PINA;              // read value of port A
		break;
		
		case 'B':
		case 'b':
		port_value= PINB;             // read value of port B
		break;
		
		case 'C':
		case 'c':
		port_value= PINC;             // read value of port C
		break;
		
		case 'D':
		case 'd':
		port_value= PIND;             // read value of port D
		break;
		
	}
	return port_value;
}

 void DIO_vwrite_law_nibble (char port_name, char value)
 {
	 DIO_vwrite_pin(port_name,0,READ_BIT(port_name,0));          // read value on given port on pin 0
	 DIO_vwrite_pin(port_name,1,READ_BIT(port_name,1));          // read value on given port on pin 1
	 DIO_vwrite_pin(port_name,2,READ_BIT(port_name,2));          // read value on given port on pin 2
	 DIO_vwrite_pin(port_name,3,READ_BIT(port_name,3));          // read value on given port on pin 3
 }

 void DIO_vwrite_high_nibble (char port_name, char value)
 {
	 DIO_vwrite_pin(port_name,4,READ_BIT(port_name,4));          // read value on given port on pin 4
	 DIO_vwrite_pin(port_name,5,READ_BIT(port_name,5));          // read value on given port on pin 5
	 DIO_vwrite_pin(port_name,6,READ_BIT(port_name,6));          // read value on given port on pin 6
	 DIO_vwrite_pin(port_name,7,READ_BIT(port_name,7));          // read value on given port on pin 7
 }	
		
	 
	 
