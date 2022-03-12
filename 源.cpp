#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>

using namespace std;


#define N 3

char arr[N][N] = { 0 };

void initBoard();
void printBoard();
void play();
void game();
void playerMove();
void computerMove();
bool isWin();

int main() {
	
	srand((unsigned int)time(NULL));

	initBoard();
	printBoard();

	play();

	return 0;
}

void initBoard() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			arr[i][j] = ' ';
		}
	}
}

void printBoard() {
	printf("        ");
	for (int i = 1; i <= N; i++)
	{
		printf("    %d   ", i);
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			printf("        ");
			for (int m = 0; m < N; m++)
				printf(" _______");
			printf(" \n        ");
		}

		else {
			//printf("        ");
			for (int j1 = 0; j1 < N; j1++) printf("|_______");
			cout << "|" << "\n" << "        ";
		}
		for (int j2 = 0; j2 < N; j2++) printf("|       ");
		cout << "|" << endl << "    " << (i + 1) << "   " ;
		for (int j3 = 0; j3 < N; j3++) printf("|   %c   ", arr[i][j3]);
		cout << "|" << endl << "        ";
		for (int j4 = 0; j4 < N; j4++) printf("|       ");
		cout << "|" << endl << "        ";
	}
	for (int n = 0; n < N; n++) {
		printf("|_______");
	}
	printf("|\n");
}

void play() {
	int input;
	printf("*****************************\n");
	printf("****** 1.play   0.exit ******\n");
	printf("*********   请选择:   ******\n");
	
	do {
		input = (int)_getch() - 48;
		switch (input) {
		case 1:
			printf("start...\n");
			Sleep(1000);
			game();
			break;
		case 0:
			printf("exit...\n");
			Sleep(1000);
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);
	
}

void game() {
	int num = 0;
	void(*p)();
	while (isWin() == false) {
		num++;
		p = (num % 2 == 1) ? playerMove : computerMove;
		(*p)();
		printBoard();
		Sleep(2000);
	}
	printf((num % 2 == 1) ? "玩家胜利!\n" : "电脑胜利!\n");
}

void playerMove() {
	printf("玩家下 ,请输入坐标：\n");
	int x;
	int y;
	again:
	scanf_s("%d %d", &x, &y);
	x--; y--;
	if (arr[x][y] == ' ')
		arr[x][y] = '*';
	else {
		printf("请重新输入：");
		goto again;
	}
}

void computerMove() {
	printf("电脑下...\n");

	again2:
	int x = rand() % 3;
	int y = rand() % 3;

	if (arr[x][y] != '* ' && arr[x][y] != '#')
		arr[x][y] = '#';
	else {
		printf("请重新输入：");
		goto again2;
	}
}

bool isWin() {

	return false;
}