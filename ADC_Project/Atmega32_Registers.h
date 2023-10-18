
#include "STD.h"
#ifndef ATMEGA32_H_
#define ATMEGA32_H_

/******************************[ DIO_PORT_A ]**********************************/
#define DDRA (*(volatile uint8*)(0x3A))
#define PORTA (*(volatile uint8*)(0x3B))
#define PINA (*(volatile uint8*)(0x39))
/******************************[ DIO_PORT_B ]**********************************/
#define DDRB (*(volatile uint8*)(0x37))
#define PORTB (*(volatile uint8*)(0x38))
#define PINB (*(volatile uint8*)(0x36))
/******************************[ DIO_PORT_C ]**********************************/
#define DDRC (*(volatile uint8*)(0x34))
#define PORTC (*(volatile uint8*)(0x35))
#define PINC (*(volatile uint8*)(0x33))
/******************************[ DIO_PORT_D ]**********************************/
#define DDRD (*(volatile uint8*)(0x31))
#define PORTD (*(volatile uint8*)(0x32))
#define PIND (*(volatile uint8*)(0x30))
/******************************[ ADC ]**********************************/
#define ADMUX (*(volatile uint8*)(0x27))
#define ADCSRA (*(volatile uint8*)(0x26))
#define ADCH (*(volatile uint8*)(0x25))
#define ADCL (*(volatile uint8*)(0x24))
#define ADC_VALUE (*(volatile uint16*)(0x24))
#define SFIOR (*(volatile uint8*)(0x50))
/******************************[ EXT INT ]**********************************/
#define SREG    (*(volatile char*)(0x5F))
#define GICR    (*(volatile char*)(0x5B))
#define GIFR    (*(volatile char*)(0x5A))
#define MCUCR   (*(volatile char*)(0x55))
#define MCUCSR  (*(volatile char*)(0x54))
/******************************[ UART ]**********************************/
#define UCSRA  (*(volatile char*)(0x2B))
#define UCSRB  (*(volatile char*)(0x2A))
#define UCSRC  (*(volatile char*)(0x40))
#define UBRRH  (*(volatile char*)(0x40))
#define UBRRL  (*(volatile char*)(0x29))
#define UDR    (*(volatile char*)(0x2C))
/******************************[ SPI ]**********************************/
#define SPCR    (*(volatile char*)(0x2D))
#define SPSR    (*(volatile char*)(0x2E))
#define SPDR    (*(volatile char*)(0x2F))
/******************************[ I2C ]**********************************/
#define TWCR    (*(volatile char*)(0x56))
#define TWDR    (*(volatile char*)(0x23))
#define TWAR    (*(volatile char*)(0x22))
#define TWBR    (*(volatile char*)(0x20))
#define TWSR    (*(volatile char*)(0x21))
/******************************[ Timers ]**********************************/
#define TIMSK    (*(volatile char*)(0x59))
#define TIFR     (*(volatile char*)(0x58))

/******************************[ Timer0 ]**********************************/
#define TCCR0    (*(volatile char*)(0x53))
#define TCNT0    (*(volatile char*)(0x52))
#define OCR0     (*(volatile char*)(0x5C))
/******************************[ Timer1 ]**********************************/
#define TCCR1A    (*(volatile char*)(0x4F))
#define TCCR1B    (*(volatile char*)(0x4E))
#define TCNT1H    (*(volatile char*)(0x4D))
#define TCNT1L    (*(volatile char*)(0x4C))
#define TCNT1    (*(volatile uint16*)(0x4C))
#define OCR1AH    (*(volatile char*)(0x4B))
#define OCR1AL    (*(volatile char*)(0x4A))
#define OCR1A    (*(volatile uint16*)(0x4A))
#define OCR1BH    (*(volatile char*)(0x49))
#define OCR1BL    (*(volatile char*)(0x48))
#define ICR1H     (*(volatile char*)(0x47))
#define ICR1L     (*(volatile char*)(0x46))
/******************************[ Timer2 ]**********************************/
#define TCCR2    (*(volatile char*)(0x45))
#define TCNT2    (*(volatile char*)(0x44))
#define OCR2     (*(volatile char*)(0x43))


#endif /* ATMEGA32_H_ */