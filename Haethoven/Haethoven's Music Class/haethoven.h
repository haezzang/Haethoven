#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <time.h>



//Ű���� ����
#define UP  0
#define DOWN  1
#define RIGHT  3
#define LEFT  4
#define SPACE 5
#define ESC 6


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
void Check(int); //�������� �Ǵ�
void StartGame(); //����ȭ��
void Record(); //���� ���� �����
int keyControl(); //�Է°� 
void Stage1(int); //��1 
void Stage2(int); //��2
void GameOver(); //���ӿ���
int main(); //����

//��ǥ�Լ�
void gotoxy(int x, int y);

