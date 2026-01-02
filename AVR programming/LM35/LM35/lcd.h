/*
 * lcd.h
 *
 * Created: 12/20/2025 4:55:56 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

//rs =12, en=11, d4=5, d5=4, d6=3, d7=2; this is our connection

//for RS pin
#define LCD_RS_PORT   PORTB
#define LCD_RS_DDR    DDRB
#define LCD_RS_PIN    PB4

//for enable pin
#define  LCD_EN_PORT    PORTB
#define  LCD_EN_DDR     DDRB
#define  LCD_EN_PIN     PB3

//for data /commands
#define LCD_D_PORT     PORTD
#define LCD_D_DDR      DDRD
#define LCD_D7_PIN     PD2
#define LCD_D6_PIN     PD3
#define LCD_D5_PIN     PD4
#define LCD_D4_PIN     PD5

//now lets declare the functions

void lcd_init();                          //for initialising sequence
void lcd_cmd(uint8_t c);                  //for commands(instructions)
void lcd_data(uint8_t d);                  //for data
void lcd_set_cursor(uint8_t row, uint8_t col);     //for setting cursor(row:0
void lcd_print(const char *s);                    //to print string
void lcd_clear();                                //to clear_lcd
void lcd_home();                                     //to return cursor to origin (row=0 column=0)

void lcd_print_uint16(uint16_t v);              //to print an integer value
void lcd_print_float(float value);







#endif /* LCD_H_ */