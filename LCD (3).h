#ifndef LCD_H_
#define LCD_H_

#include "Standard_types_ARM.h"
#include "common_macros_ARM.h"

#include "delay.h"
#include "tm4c123gh6pm.h"
/***************************
 *                      Preprocessor Macros                                    *
 ***************************/
/* LCD HW Pins */
#define RS 0
#define RW 1
#define E  2
#define LCD_CTRL_PORT GPIO_PORTD_DATA_R       
#define LCD_CTRL_PORT_DIR GPIO_PORTD_DIR_R
#define LCD_CTRL_PORT_DEN GPIO_PORTD_DEN_R


#define LCD_DATA_PORT GPIO_PORTB_DATA_R
#define LCD_DATA_PORT_DIR GPIO_PORTB_DIR_R
#define LCD_DATA_PORT_DEN GPIO_PORTB_DEN_R

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 
#define AUTO_INCREMENT 0x06
#define wake_up 0x30
#define display_on 0x0F
/***************************
 *                      Functions Prototypes                                   *
 ***************************/
void LCD_sendCommand(uint8_t command);
void LCD_displayCharacter(uint8_t data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void dmilli_break(int n);
void dmilli(int n);


#endif /* LCD_H_ */
