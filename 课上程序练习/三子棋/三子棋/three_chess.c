#define _CRT_SECURE_NO_WARNINGS 1
#include "three_chess.h"


void ShowUI()
{
	printf("##########################\n");
	printf("##1.PLAY          0.EXIT##\n");
	printf("##########################\n");
	printf("select number: \n");

}
void Game()
{
	printf("Game bigin\n");
	char board[ROW][COL];
	char result = 'N';
	srand((unsigned long)time(NULL));
	int test = rand() % 2;
	int test1,pos;
	//printf("%d\n", test);
	printf("请猜0或1来决定谁先走 ：");
	
	scanf("%d", &test1);
	if (test == test1)
	{
		pos = 1;
	}
	else pos = 0;
	memset(board, ' ', sizeof(board));    //按字节初始化
	while (1)
	{
		ShowBoard(board, ROW, COL);
		if (pos == 0)
		{
			ComputerMove(board, ROW, COL);
			pos = 1;
		}
		else{ 
			PlayerMove(board, ROW, COL);
			pos = 0;
		}
		
		result = Judge(board, ROW, COL);
		if (result != 'N')     //结果‘X' 'O' 'E' 'N'
		{
			ShowBoard(board, ROW, COL);
			break;
		}

	}
	switch (result){
	case 'X':
		printf("congratulation!!!you win...");
		break;
	case 'O':
		printf("oh no~~~~~you lose");
		break;
	case 'E':
		printf("平局");
		break;
	default:
		break;

	}
}


void ComputerMove(char board[][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}





}
void PlayerMove(char board[][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("Please Enter Your Pose:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else printf("Your pose has been filled , try agin");

		}
		else printf("Enter error , try agin");



	}


}
char Judge(char board[ROW][COL], int row, int col)
{
	int i ,j;

	for (i=0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&        //续行符
			board[i][0] != ' ')
			return board[i][0];
	}
	for (j=0; j <col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] &&     //续行符
			board[0][j] != ' ')
			return board[0][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&     //续行符
		board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&     //续行符
		board[0][2] != ' ')
		return board[0][2];
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'N';
		}
	}
	return 'E';
}
void ShowBoard(char board[][COL], int row, int col)
{
	int i, j;
	printf("  1  2  3 \n");
	printf("----------\n");

	for (i = 0; i <row; i++)
	{
		printf("%d|", i+1);
		for (j = 0; j < col; j++)
		{
			printf("%c|", board[i][j]);
		}

		printf("\n");
	}




}

