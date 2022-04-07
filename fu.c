//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//
//#define ROW 9
//#define COL 9
//#define ROWS ROW+2
//#define COLS COL+2
//#define DiLei 10//地雷数量
//
//void menu()
//{
//	printf("扫雷游戏\n");
//	printf("****************************\n");
//	printf("********  1、开始  *********\n");
//	printf("********  0、结束  *********\n");
//	printf("****************************\n");
//}
//
//void IntBoard(char board[ROWS][COLS], int rows, int cols, char sat)//初始化棋盘
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = sat;
//		}
//	}
//}
//
//void CBoard(char board[ROWS][COLS], int row, int col)//打印棋盘
//{
//	printf("------扫雷游戏------\n");
//
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i <= col; i++)//打印第一排的数字
//	{
//		printf("%d|", i);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d|", i);//打印第一列的数字
//
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c", board[i][j]);
//			if (j < col)
//			{
//				printf(" ");
//			}
//			if (j == col)
//			{
//				printf("|");
//			}
//		}
//		printf("\n");
//	}
//
//	printf("------扫雷游戏------\n");
//}
//
//void SetBoard(char board[ROWS][COLS], int row, int col)//设置雷
//{
//	int count = DiLei;
//
//	while(count)//当count=0时停止循环
//	{
//		int	x = rand() % ROW + 1;//生成1~9的随机数，注意要+1
//		int	y = rand() % COL + 1;
//
//		if (board[x][y] == '0')//防止把雷放在同一个地方
//		{
//			board[x][y] = '1';
//			count--;
//		}
//	}
//}
//
//int get_mine_count(char board[ROWS][COLS], int x, int y)//计算坐标八方的雷数
//{
//	return (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +		//第一行
//		board[x][y - 1] + board[x][y + 1] +										//第二行
//		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]) - (8 * '0');//第三行
//						//注意board里面的是字符
//}
//
//void OpenBoard(char my_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y)
//{
//	int n = get_mine_count(my_board, x, y);
//	int i = 0;
//	int j = 0;
//	if (n != 0)
//	{
//		show_board[x][y] = '0' + n;
//	}
//	else if (show_board[x][y] != ' ')
//	{
//		show_board[x][y] = ' ';
//		for (i = x - 1; i <= x + 1; i++)
//		{
//			for (j = y - 1; j <= y + 1; j++)
//			{
//				OpenBoard(my_board, show_board, i, j);
//			}
//		}
//	}
//	else
//	{
//		return;
//	}
//}
//
//void FindBoard(char my_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)//排查雷
//{
//	int x = 0;
//	int y = 0;
//	while (1)//判断是否扫完了雷
//	{
//		printf("请输入坐标：>");
//		scanf("%d %d", &x, &y);
//
//		system("cls");//清屏
//		Sleep(200);//此函数可以起到延时的功能，提高用户体验。单位ms
//
//		if (x <= 9 && x >= 1 && y <= 9 && y >= 1)
//		{
//			if (my_board[x][y] == '1')
//			{
//				printf("*_*游戏结束，你被炸死了*_*\n");
//				CBoard(my_board, ROW, COL);
//				printf("刚刚的坐标是%d %d\n", x, y);
//				break;
//			}
//			else
//			{
//				OpenBoard(my_board, show_board, x, y);
//				CBoard(show_board, ROW, COL);
//			}
//		}
//		else
//		{
//			CBoard(show_board, ROW, COL);
//			printf("坐标输入错误，重新输入\n");
//		}
//	}
//	int i = 0;
//	int j = 0;
//	int t = 0;
//	for (i = 1; i <= row; i++)
//	{
//		for (j = 1; j <= col; j++)
//		{
//			if (show_board[i][j] == '*')
//			{
//				x++;
//			}
//		}
//
//		if (t == DiLei)//表示扫完所有空地
//		{
//			CBoard(show_board, ROW, COL);
//			printf("扫雷成功！！，你获胜啦！！！\n");
//			break;
//		}
//	}
//}
//
//void game()
//{
//	char my_board[ROWS][COLS] = { 0 };
//	char show_board[ROWS][COLS] = { 0 };
//
//	//初始化棋盘
//	IntBoard(my_board, ROWS, COLS, '0');
//	IntBoard(show_board, ROWS, COLS, '*');
//
//	//打印棋盘
//	CBoard(show_board, ROW, COL);
//	//CBoard(my_board, ROW, COL);
//
//	//设置雷
//	SetBoard(my_board, ROW, COL);
//
//	//排查雷
//	FindBoard(my_board,show_board, ROWS, COL);
//}
//
//int main()
//{
//	//扫雷项目
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		system("cls");
//		switch (input)
//		{
//		case 1:
//		{
//			game();
//			break;
//		}
//		case 0:
//		{
//			printf("退出游戏\n");
//			break;
//		}
//		default:
//		{
//			printf("选择错误，重新选择\n");
//			break;
//		}
//		}
//	} while (input);
//	return 0;
//}