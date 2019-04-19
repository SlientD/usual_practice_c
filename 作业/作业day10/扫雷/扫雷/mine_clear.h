#ifndef   _MINE_CLEAR_
#define   _MINE_CLEAR_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define ROW 12
#define COL 12
#define MINE_NUM 20
#define TOTAL 100

void ShowUI();
void Game();
void Set_mine();
void Show_Board();
int Calculat_Mine_Number();




#endif