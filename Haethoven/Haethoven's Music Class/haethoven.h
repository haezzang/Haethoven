#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")



//키보드 정의
#define UP  0
#define DOWN  1
#define RIGHT  3
#define LEFT  4
#define SPACE 5
#define ESC 6


//색깔 정의
enum Color
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};



//함수 정의
void Rank(); //랭킹회면
void Info(); //정보화면
void Title(); //게임제목
int Menu(); //메뉴선택
void Check(int); //게임점수 판단
void StartGame(); //게임화면
void Record(); //게임 점수 기록판
int keyControl(); //입력값 
void Stage1(int); //맵1 
void Stage2(int); //맵2
void Stage3(int); //맵2
void Stage4(int); //맵2
void Stage5(int); //맵2
void GameClear();
void GameOver(); //게임오버
int main(); //메인

//좌표함수
void gotoxy(int x, int y);

