#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define DiLei 10//��������

void menu()
{
	printf("ɨ����Ϸ\n");
	printf("****************************\n");
	printf("********  1����ʼ  *********\n");
	printf("********  0������  *********\n");
	printf("****************************\n");
}

void IntBoard(char board[ROWS][COLS], int rows, int cols, char sat)//��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = sat;
		}
	}
}

void CBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	printf("------ɨ����Ϸ------\n");

	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)//��ӡ��һ�ŵ�����
	{
		printf("%d|", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);//��ӡ��һ�е�����

		for (j = 1; j <= col; j++)
		{
			printf("%c", board[i][j]);
			if (j < col)
			{
				printf(" ");
			}
			if (j == col)
			{
				printf("|");
			}
		}
		printf("\n");
	}

	printf("------ɨ����Ϸ------\n");
}

void SetBoard(char board[ROWS][COLS], int row, int col)//������
{
	int count = DiLei;

	while(count)//��count=0ʱֹͣѭ��
	{
		int	x = rand() % ROW + 1;//����1~9���������ע��Ҫ+1
		int	y = rand() % COL + 1;

		if (board[x][y] == '0')//��ֹ���׷���ͬһ���ط�
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)//��������˷�������
{
	return (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +		//��һ��
		board[x][y - 1] + board[x][y + 1] +										//�ڶ���
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]) - (8 * '0');//������
						//ע��board��������ַ�
}

void OpenBoard(char my_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y)
{
	int n = get_mine_count(my_board, x, y);
	int i = 0;
	int j = 0;
	if (n != 0)
	{
		show_board[x][y] = '0' + n;
	}
	else if (show_board[x][y] != ' ')
	{
		show_board[x][y] = ' ';
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				OpenBoard(my_board, show_board, i, j);
			}
		}
	}
	else
	{
		return;
	}
}

void FindBoard(char my_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)//�Ų���
{
	int x = 0;
	int y = 0;
	while (1)//�ж��Ƿ�ɨ������
	{
		printf("���������꣺>");
		scanf("%d %d", &x, &y);

		system("cls");//����
		Sleep(200);//�˺�����������ʱ�Ĺ��ܣ�����û����顣��λms

		if (x <= 9 && x >= 1 && y <= 9 && y >= 1)
		{
			if (my_board[x][y] == '1')
			{
				printf("*_*��Ϸ�������㱻ը����*_*\n");
				CBoard(my_board, ROW, COL);
				printf("�ոյ�������%d %d\n", x, y);
				break;
			}
			else
			{
				OpenBoard(my_board, show_board, x, y);
				CBoard(show_board, ROW, COL);
			}
		}
		else
		{
			CBoard(show_board, ROW, COL);
			printf("�������������������\n");
		}
	}
	int i = 0;
	int j = 0;
	int t = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show_board[i][j] == '*')
			{
				x++;
			}
		}

		if (t == DiLei)//��ʾɨ�����пյ�
		{
			CBoard(show_board, ROW, COL);
			printf("ɨ�׳ɹ����������ʤ��������\n");
			break;
		}
	}
}

void game()
{
	char my_board[ROWS][COLS] = { 0 };
	char show_board[ROWS][COLS] = { 0 };

	//��ʼ������
	IntBoard(my_board, ROWS, COLS, '0');
	IntBoard(show_board, ROWS, COLS, '*');

	//��ӡ����
	CBoard(show_board, ROW, COL);
	//CBoard(my_board, ROW, COL);

	//������
	SetBoard(my_board, ROW, COL);

	//�Ų���
	FindBoard(my_board,show_board, ROWS, COL);
}

int main()
{
	//ɨ����Ŀ
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("�˳���Ϸ\n");
			break;
		}
		default:
		{
			printf("ѡ���������ѡ��\n");
			break;
		}
		}
	} while (input);
	return 0;
}