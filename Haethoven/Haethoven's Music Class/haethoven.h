#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>
#include <mmsystem.h>
#include<fstream>
#include<iomanip>
#include<string>
#pragma comment(lib,"winmm.lib")



//Ű���� ����
#define UP  0
#define DOWN  1
#define RIGHT  3
#define LEFT  4
#define SPACE 5



//���� ����
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



//�Լ� ����
void Rank(); //��ŷȸ��
void Info(); //����ȭ��
void Title(); //��������
int Menu(); //�޴�����
void StartGame(); //����ȭ��
void Record(int); //���� ���� �����
int keyControl(); //�Է°� 
void Stage(); 
void GameOver(); //���ӿ���
void GameClear(); //���ӿ���
int main(); //����
void Reset();//�ʱ�ȭ
void StartBonus(); 
void BonusStage(int);
void DeleteHeart();
void B_GameOver(); //���ʽ� ���ӿ���

//��ǥ�Լ�
void gotoxy(int x, int y);
//Ŀ�� ���ִ� �Լ�
void CursorView();


