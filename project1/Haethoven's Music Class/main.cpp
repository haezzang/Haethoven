#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;
//���ڵ� ��Ʈ 32

//���� ����
#define UP = 0
#define DOWN = 1
#define RIGHT = 2
#define LEFT = 3


//�Լ�������
void ReadyGame();
void StartGame();


//��ǥ�Լ�
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//�غ�ȭ��
void ReadyGame() {

    //�ƽ�Ű��Ʈ
    gotoxy(13,4);
    cout << " _   _   ___   _____  _____  _____  _   _  _____  _   _ " << endl;
    gotoxy(13, 5);
    cout << "| | | | / _ \\ |  ___||_   _||  _  || | | ||  ___|| \\ | |" << endl;
    gotoxy(13, 6);
    cout << "| |_| |/ /_\\ \\| |__    | |  | | | || | | || |__  |  \\| |" << endl;
    gotoxy(13, 7);
    cout << "|  _  ||  _  ||  __|   | |  | | | || | | ||  __| | . ` |" << endl;
    gotoxy(13, 8);
    cout << "| | | || | | || |___   | |  \\ \\_/ /\\ \\_/ /| |___ | |\\  |" << endl;
    gotoxy(13,9);
    cout << "\\_| |_/\\_| |_/\\____/   \\_/   \\___/  \\___/ \\____/ \\_| \\_/" << endl;
    gotoxy(32, 10);
    cout << "���亥�� ���Ǳ���" << endl;
    gotoxy(13, 13);
    cout << " _____________________________________________________" << endl;
    gotoxy(13, 14);
    cout << "|                                                     |" << endl;
    gotoxy(13, 15);
    cout << "|                     �� �� �� ��                     |" << endl;
    gotoxy(13, 16);
    cout << "|                                                     |" << endl;
    gotoxy(13, 17);
    cout << "|                     �� ŷ �� ��                     |" << endl;
    gotoxy(13, 18);
    cout << "|                                                     |" << endl;
    gotoxy(13, 19);
    cout << "|                     �� �� �� ��                     |" << endl;
    gotoxy(13, 20);
    cout << "|                                                     |" << endl;
    gotoxy(13, 21);
    cout << "|_____________________________________________________|" << endl;

}

//���ӽ���ȭ��
void StartGame() {
    system("cls"); 
    srand((int)time(0));     //���� �ߺ�����

    string str[5] = { "��","��","��","��" };

    int x = 5; int y = 5; //���� ��ġ


    for (int j = 1; j <= 20; j++) {  //���� ����
        int rn = (rand() % 4);
        gotoxy(x++, y);

        cout << str[rn] << endl;
    }
}
    int main(void) {
        ReadyGame();

    }