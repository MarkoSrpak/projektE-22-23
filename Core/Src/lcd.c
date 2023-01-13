/*
 * lcd.c
 *
 *  Created on: Jan 9, 2023
 *      Author: User02
 */

#include "stm32f429i_discovery_lcd.h"


//extern int num_of_players=0;
extern int state=0;

void change_LCD_state(int state){
	uint32_t x= BSP_LCD_GetXSize();
	uint32_t y= BSP_LCD_GetYSize();
	switch (state){
		case 0:;

			BSP_LCD_SetFont(&Font20);
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_DisplayStringAtLine(5,(uint8_t *)"Beerpong");
			BSP_LCD_DisplayStringAtLine(8,(uint8_t *)"pritisni start");
			BSP_LCD_DisplayStringAtLine(9,(uint8_t *)">");
			break;

		case 1:

		default:
			break;

	}
}

void LCD_Handler(void){


	if(state==0){
		if(zeleni_button==1){
			state=1;
			change_LCD_state(state);
		}
	}
	if(state==1){

		if(zeleni_button==1){
			state=2;
			change_LCD_state(state);
		}
	}
	if(state==2){
		change_LCD_state(state);
		if(reset_button==1){
			state=3;
			change_LCD_state(state);
		}
	}
	change_LCD_state(0);
}


