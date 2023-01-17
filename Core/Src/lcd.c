/*
 * lcd.c
 *
 *  Created on: Jan 9, 2023
 *      Author: User02
 */


#include "lcd.h"

#define BGCOLOR LCD_COLOR_LIGHTCYAN


uint8_t num_of_players;
char num_of_players_print[2];
char mLs_of_players_print[7];

LCD_Player Players[4];
LCD_Player Players_prev[4];
LCD_Game_States game_state;
uint32_t winner;



//updates game state based on button press
void MDL_LCD_Bttn_Pressed(bttns bttn){
	switch(game_state){
		case WELCOME:
			if (bttn == START){
				game_state=NUM_OF_PLAYERS;
				change_LCD_screenstate();
			}
			break;

		case NUM_OF_PLAYERS:

			if (bttn == PLUS){
				if(num_of_players==4) num_of_players = 1;
				num_of_players++;
				game_state = NUM_OF_PLAYERS;
				change_LCD_screenstate();
			}
			else if(bttn == MINUS){
				if(num_of_players==2) num_of_players = 5;
				num_of_players--;
				game_state = NUM_OF_PLAYERS;
				change_LCD_screenstate();
			}
			else if(bttn == START){
				LCD_Add_Player();
				game_state = PLAYER1;
				change_LCD_screenstate();
			}
			break;

		case PLAYER1:
			if(bttn == TOCI){
				game_state= PLAYER2;
				change_LCD_screenstate();
			}
			break;

		case PLAYER2:
			if(bttn == TOCI){
				if(num_of_players == 2){
					game_state= PLAYER1;
					change_LCD_screenstate();
				} else {
					game_state= PLAYER3;
					change_LCD_screenstate();
				}
			}
			break;
		case PLAYER3:
			if(bttn == TOCI){
				if(num_of_players ==3){
					game_state= PLAYER1;
					change_LCD_screenstate();
				} else {
					game_state= PLAYER4;
					change_LCD_screenstate();
				}
			}
			break;

		case PLAYER4:
			if(bttn == TOCI){
				game_state= PLAYER1;
				change_LCD_screenstate();
			}
			break;

		default:
			break;
	}

}


//updates game state based on sensor hits
void MDL_LCD_Hit_Update(uint32_t mLs){
	switch(game_state){
			case PLAYER1:
				Players[0].mL += mLs;
				change_LCD_screenstate();

				if(Players[0].mL >= 1000){
					game_state = WIN;
					winner = 1;
					change_LCD_screenstate();
				}

				break;

			case PLAYER2:
				Players[1].mL += mLs;
				change_LCD_screenstate();

				if(Players[1].mL >= 1000){
					game_state = WIN;
					winner = 2;
					change_LCD_screenstate();
				}

				break;

			case PLAYER3:
				Players[2].mL += mLs;
				change_LCD_screenstate();

				if(Players[2].mL >= 1000){
					game_state = WIN;
					winner = 3;
					change_LCD_screenstate();
				}

				break;

			case PLAYER4:
				Players[3].mL += mLs;
				change_LCD_screenstate();

				if(Players[0].mL >= 1000){
					game_state = WIN;
					winner = 4;
					change_LCD_screenstate();
				}

				break;

			default:
				break;
	}
}



//initializes new game
void LCD_Init(){
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(LCD_BACKGROUND_LAYER, LCD_FRAME_BUFFER);
	BSP_LCD_LayerDefaultInit(LCD_FOREGROUND_LAYER, LCD_FRAME_BUFFER);
	BSP_LCD_SelectLayer(LCD_FOREGROUND_LAYER);
	BSP_LCD_DisplayOn();
	BSP_LCD_Clear(BGCOLOR);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

	num_of_players=2;
	sprintf(num_of_players_print, "%d", num_of_players);

	game_state=WELCOME;
	winner = 0;
	change_LCD_screenstate();
}


//updates number of players based on player choice
void LCD_Add_Player(void){

	sprintf(num_of_players_print, "%d", num_of_players);

	for(uint32_t i=0; i<num_of_players; i++){
		LCD_Player player = {i, 0};
		Players[i]=player;
		Players_prev[i]=player;
	}
}


//calls functions to change LCD screen based on game state
void change_LCD_screenstate(){

	switch (game_state){
		case WELCOME:
			LCD_State_WELCOME();
			break;

		case NUM_OF_PLAYERS:
			LCD_State_NUM_OF_PLAYERS();
			break;

		case PLAYER1:
		case PLAYER2:
		case PLAYER3:
		case PLAYER4:
			LCD_State_PLAYERS();
			break;

		case WIN:
			LCD_State_WIN();
			break;

		default:
			break;

	}
}



//displays the WELCOME screen on the LCD
void LCD_State_WELCOME(void){
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAtLine(5,(uint8_t *)"Beerpong");
	BSP_LCD_DisplayStringAtLine(8,(uint8_t *)"pritisni start");
	BSP_LCD_DisplayStringAtLine(9,(uint8_t *)">");
}


//displays the NUM_OF_PLAYERS screen on the LCD
void LCD_State_NUM_OF_PLAYERS(void){
	sprintf(num_of_players_print, "%d", num_of_players);

	BSP_LCD_Clear(BGCOLOR);

	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAtLine(2,(uint8_t *)"odabir igraca");


	BSP_LCD_SetFont(&Font24);
	BSP_LCD_DisplayStringAtLine(5,(uint8_t *)num_of_players_print);

	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAtLine(17,(uint8_t *)"pritisni + za dodavanje igraca");
	BSP_LCD_DisplayStringAtLine(18,(uint8_t *)"pritisni - za uklanjanje igraca");
	BSP_LCD_DisplayStringAtLine(20,(uint8_t *)"max broj igraca je 4");

	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAtLine(17,(uint8_t *)"pritisni start ");
	BSP_LCD_DisplayStringAtLine(18,(uint8_t *)"za pocetak igre");
}



//displays the WIN screen on the LCD
void LCD_State_WIN(void){
	BSP_LCD_Clear(LCD_COLOR_GREEN);
	char wintext[25];
	sprintf(wintext,"igrac %ld!", winner);

	BSP_LCD_SetFont(&Font24);
	for(uint32_t i=0; i<10; i++){
		BSP_LCD_Clear(LCD_COLOR_GREEN);
		BSP_LCD_DisplayStringAt(0, 150,(uint8_t *)"pobjednik je", CENTER_MODE);
		BSP_LCD_DisplayStringAt(0, 180,(uint8_t *)wintext, CENTER_MODE);
		HAL_Delay(500);
		BSP_LCD_Clear(LCD_COLOR_LIGHTBLUE);
		BSP_LCD_DisplayStringAt(0, 150,(uint8_t *)"pobjednik je", CENTER_MODE);
		BSP_LCD_DisplayStringAt(0, 180,(uint8_t *)wintext, CENTER_MODE);
		HAL_Delay(500);
	}
	LCD_Init();
}



//displays the PLAYERx screen on the LCD
void LCD_State_PLAYERS(void){
	BSP_LCD_Clear(BGCOLOR);
	switch(num_of_players){
		case 2:
			switch(game_state){
				case PLAYER1:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_RED);
					BSP_LCD_FillRect(0,0,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				case PLAYER2:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
					BSP_LCD_FillRect(BSP_LCD_GetXSize()/2,0,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				default:
					break;
			}
			BSP_LCD_SetFont(&Font20);
			BSP_LCD_DisplayStringAt(10, 10, (uint8_t *)"igrac 1", LEFT_MODE);
			BSP_LCD_DisplayStringAt(-10, 10, (uint8_t *)"igrac 2", RIGHT_MODE);

			BSP_LCD_SetFont(&Font24);

			sprintf(mLs_of_players_print, "%ld mL", Players[0].mL);
			BSP_LCD_DisplayStringAt(10, 60,(uint8_t *)mLs_of_players_print,LEFT_MODE);

			sprintf(mLs_of_players_print, "%ld mL", Players[1].mL);
			BSP_LCD_DisplayStringAt(-10, 60,(uint8_t *)mLs_of_players_print, RIGHT_MODE);

			BSP_LCD_SetFont(&Font16);
			BSP_LCD_DisplayStringAt(0, 280,(uint8_t *)"pritisni toci", CENTER_MODE);
			BSP_LCD_DisplayStringAt(0, 295,(uint8_t *)"za kraj bacanja", CENTER_MODE);

			break;

		case 3:
			switch(game_state){
				case PLAYER1:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_RED);
					BSP_LCD_FillRect(0,0,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-20);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				case PLAYER2:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
					BSP_LCD_FillRect(BSP_LCD_GetXSize()/2,0,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-20);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				case PLAYER3:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
					BSP_LCD_FillRect(BSP_LCD_GetXSize()/2-60,BSP_LCD_GetYSize()/2-20,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-25);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				default:
					break;

			}
			BSP_LCD_SetFont(&Font20);
			BSP_LCD_DisplayStringAt(10, 10, (uint8_t *)"igrac 1", LEFT_MODE);
			BSP_LCD_DisplayStringAt(-10, 10, (uint8_t *)"igrac 2", RIGHT_MODE);
			BSP_LCD_DisplayStringAt(0, 150, (uint8_t *)"igrac 3", CENTER_MODE);

			BSP_LCD_SetFont(&Font24);

			sprintf(mLs_of_players_print, "%ld mL", Players[0].mL);
			BSP_LCD_DisplayStringAt(10, 60,(uint8_t *)mLs_of_players_print,LEFT_MODE);

			sprintf(mLs_of_players_print, "%ld mL", Players[1].mL);
			BSP_LCD_DisplayStringAt(-10, 60,(uint8_t *)mLs_of_players_print, RIGHT_MODE);

			sprintf(mLs_of_players_print, "%ld mL", Players[2].mL);
			BSP_LCD_DisplayStringAt(0, 200,(uint8_t *)mLs_of_players_print, CENTER_MODE);

			BSP_LCD_SetFont(&Font16);
			BSP_LCD_DisplayStringAt(0, 280,(uint8_t *)"pritisni toci", CENTER_MODE);
			BSP_LCD_DisplayStringAt(0, 295,(uint8_t *)"za kraj bacanja", CENTER_MODE);

			break;

		case 4:
			switch(game_state){
				case PLAYER1:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_RED);
					BSP_LCD_FillRect(0,0,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-20);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				case PLAYER2:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
					BSP_LCD_FillRect(BSP_LCD_GetXSize()/2,0,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-20);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				case PLAYER3:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
					BSP_LCD_FillRect(0,BSP_LCD_GetYSize()/2-20,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-20);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;
				case PLAYER4:
					BSP_LCD_Clear(BGCOLOR);
					BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);
					BSP_LCD_FillRect(BSP_LCD_GetXSize()/2,BSP_LCD_GetYSize()/2-20,BSP_LCD_GetXSize()/2, BSP_LCD_GetYSize()/2-20);
					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					break;

				default:
					break;
			}

			BSP_LCD_SetFont(&Font20);
			BSP_LCD_DisplayStringAt(10, 10, (uint8_t *)"igrac 1", LEFT_MODE);
			BSP_LCD_DisplayStringAt(-10, 10, (uint8_t *)"igrac 2", RIGHT_MODE);
			BSP_LCD_DisplayStringAt(10, 150, (uint8_t *)"igrac 3", LEFT_MODE);
			BSP_LCD_DisplayStringAt(-10, 150, (uint8_t *)"igrac 4", RIGHT_MODE);

			BSP_LCD_SetFont(&Font24);

			sprintf(mLs_of_players_print, "%ld mL", Players[0].mL);
			BSP_LCD_DisplayStringAt(10, 60,(uint8_t *)mLs_of_players_print,LEFT_MODE);

			sprintf(mLs_of_players_print, "%ld mL", Players[1].mL);
			BSP_LCD_DisplayStringAt(-10, 60,(uint8_t *)mLs_of_players_print, RIGHT_MODE);

			sprintf(mLs_of_players_print, "%ld mL", Players[2].mL);
			BSP_LCD_DisplayStringAt(10, 200,(uint8_t *)mLs_of_players_print, RIGHT_MODE);

			sprintf(mLs_of_players_print, "%ld mL", Players[3].mL);
			BSP_LCD_DisplayStringAt(-10, 200,(uint8_t *)mLs_of_players_print, LEFT_MODE);

			BSP_LCD_SetFont(&Font16);
			BSP_LCD_DisplayStringAt(0, 280,(uint8_t *)"pritisni toci", CENTER_MODE);
			BSP_LCD_DisplayStringAt(0, 295,(uint8_t *)"za kraj bacanja", CENTER_MODE);

}
}


