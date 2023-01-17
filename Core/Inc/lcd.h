/*
 * lcd.h
 *
 *  Created on: 12. sij 2023.
 *      Author: User02
 */



#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f429i_discovery_lcd.h"
#include "stdio.h"

typedef struct LCD_Player{
	uint32_t redni_broj;
	uint32_t mL;
}LCD_Player;

//typedef struct LCD_Players{
//	LCD_Player *Players;
//}LCD_Players;

typedef enum LCD_Game_States{
	WELCOME,
	NUM_OF_PLAYERS,
	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
	WIN
}LCD_Game_States;

typedef enum bttns{
	START,
	PLUS,
	MINUS,
	TOCI
}bttns;

void LCD_Add_Player(void);
void LCD_Init(void);
void MDL_LCD_Hit_Update(uint32_t mLs);
void MDL_LCD_Bttn_Pressed(bttns bttn);
void change_LCD_screenstate();




#endif /* INC_LCD_H_ */
