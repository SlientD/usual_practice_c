#define _CRT_SECURE_NO_WARNINGS 1
#include "mine_clear.h"
void ShowUI()
{
	printf("#################################\n");
	printf("#### 1.PLAY           2.EXIT ####\n");
	printf("#################################\n");
	printf("Please make a choice by select a number:");
}
static int Get_Randnumber(int star,int end)
{
	return rand() % (end - star + 1) + star;
}
void Set_mine(char mine_board[][COL])
{
	srand((unsigned int)time(NULL));
	int row,col;
	int mine_number = MINE_NUM;
	while (mine_number)
	{
		row = Get_Randnumber(1, ROW - 2);
		col = Get_Randnumber(1, COL - 2);
		if ('0'==mine_board[row][col])
		{
			mine_board[row][col] = '1';
			mine_number--;
		}
	}
}

void Show_Board(char show_board[][COL])
{
	int i = 1;
	int j = 1;
	int t = 1;
	printf("   ");
	for (; i <= COL - 2; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i=1; i <= COL - 4; i++)
	{
		printf("---");
	}
	printf("\n");
	for (i = 1; i <= ROW-2; i++)
	{
		printf("%2d|", i);
		for (j = 1; j <= COL - 2; j++)
		{
			printf("%c|",show_board[i][j]);
		}
		printf("\n");
		for (t=1; t <= COL - 4; t++)
		{
			printf("---");
		}
		printf("\n");
	}
	

}

int Calculat_Mine_Number(char mine_board[][COL], int row, int col)
{
	return mine_board[row - 1][col - 1] + mine_board[row - 1][col] + mine_board[row - 1][col + 1] + mine_board[row][col - 1] + mine_board[row][col + 1]+ mine_board[row + 1][col - 1] + mine_board[row + 1][col] + mine_board[row + 1][col + 1]-8*'0';
}


void Game()
{
	char mine_board[ROW][COL];
	char show_board[ROW][COL];
	int row, col;
	int count=0;
	memset(mine_board, '0', sizeof(mine_board));
	memset(show_board, '*', sizeof(show_board));
	Set_mine(mine_board);
	while (1)
	{
		Show_Board(show_board);
		printf("plese input your pose:");
		scanf("%d%d", &row, &col);
		if ('0' == mine_board[row][col])
		{

			show_board[row][col] = Calculat_Mine_Number(mine_board,row,col)+'0';
			count++;
		}
		else if ('1' == mine_board[row][col])
		{
			printf("oh~~no,you meet a mine...\n");
			show_board[row][col] = '@';
			continue;
		}
		if (MINE_NUM == (TOTAL - count))
		{
			printf("wow~~you win!!!!\n");
			break;
		}

	}

	
}