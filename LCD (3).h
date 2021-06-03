#ifndef LCD_H_
#define LCD_H_

#include "Standard_types_ARM.h"
#include "common_macros_ARM.h"
#include "tm4c123gh6pm.h"
#include "delay.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD HW Pins */
#define RS PC4
#define RW PC5
#define E  PC6
#define LCD_CTRL_PORT GPIO_PORTC_AHB_DATA_R       
#define LCD_CTRL_PORT_DIR GPIO_PORTC_AHB_DIR_R
#define LCD_CTRL_PORT_DEN GPIO_PORTC_AHB_DEN_R


#define LCD_DATA_PORT GPIO_PORTD_AHB_DATA_R
#define LCD_DATA_PORT_DIR GPIO_PORTD_AHB_DIR_R
#define LCD_DATA_PORT_DEN GPIO_PORTD_AHB_DEN_R

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(uint8_t command);
void LCD_displayCharacter(uint8_t data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);


#endif /* LCD_H_ */
