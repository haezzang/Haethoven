#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>



//키보드 정의
#define UP  0
#define DOWN  1
#define RIGHT  3
#define LEFT  4
#define SPACE 5
#define ESC 6






//함수 정의
void Info();
void Title();
int Menu();
void Check(int);
void StartGame();
void Record();
int keyControl();
void Stage1(int);
void Stage2(int);
void GameOver();
int main();

//좌표함수
void gotoxy(int x, int y);

