#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;
//���ڵ� ��Ʈ 32

//Ű���� ����
#define UP  0
#define DOWN  1
#define RIGHT  3
#define LEFT  4
#define SPACE 5
#define ESC 6


//�Լ� ����
void ReadyGame();
void StartGame();
int keyControl();


//��ǥ�Լ�
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//Ŀ�� ����
int keyControl() {
    char c;
    while (1) {
        if (_kbhit()) {               
            c = _getch();          
            if (c == -32) {         
                c = _getch();        
                switch (c) {
                case 72:
                    return UP; break;
                case 80:
                    return DOWN;  break;
                case 75:
                    return LEFT; break;
                case 77:
                    return RIGHT; break;
                }
            }
        }
    }
}


//Ÿ��Ʋ
void Title() {
    //�ƽ�Ű��Ʈ
    gotoxy(13, 4);
    cout << " _   _   ___   _____  _____  _____  _   _  _____  _   _ " << endl;
    gotoxy(13, 5);
    cout << "| | | | / _ \\ |  ___||_   _||  _  || | | ||  ___|| \\ | |" << endl;
    gotoxy(13, 6);
    cout << "| |_| |/ /_\\ \\| |__    | |  | | | || | | || |__  |  \\| |" << endl;
    gotoxy(13, 7);
    cout << "|  _  ||  _  ||  __|   | |  | | | || | | ||  __| | . ` |" << endl;
    gotoxy(13, 8);
    cout << "| | | || | | || |___   | |  \\ \\_/ /\\ \\_/ /| |___ | |\\  |" << endl;
    gotoxy(13, 9);
    cout << "\\_| |_/\\_| |_/\\____/   \\_/   \\___/  \\___/ \\____/ \\_| \\_/" << endl;
    gotoxy(32, 10);
    cout << "���亥�� ���Ǳ���" << endl;
    gotoxy(13, 13);
    cout << " _____________________________________________________" << endl;
    gotoxy(13, 14);
    cout << "|                                                     |" << endl;
    gotoxy(13, 15);
    cout << "|                                                     |" << endl;
    gotoxy(13, 16);
    cout << "|                                                     |" << endl;
    gotoxy(13, 17);
    cout << "|                                                     |" << endl;
    gotoxy(13, 18);
    cout << "|                                                     |" << endl;
    gotoxy(13, 19);
    cout << "|                                                     |" << endl;
    gotoxy(13, 20);
    cout << "|                                                     |" << endl;
    gotoxy(13, 21);
    cout << "|_____________________________________________________|" << endl;


    // system("pause>null");
}

    int menu() {
      
        int x = 24;
        int y = 15;
        gotoxy(x-1, y);
        cout << "> �� �� �� ��" << endl;
        gotoxy(x, y+2);
        cout << "�� ŷ �� ��" << endl;
        gotoxy(x, y+4);
        cout << "�� �� �� ��" << endl;
        while (1) {
            int n = keyControl();
            switch (n)
            {
            case UP: {
                if (y > 15) {
                    gotoxy(x - 1, y); printf("  ");
                    gotoxy(x - 1, y-=2); printf(">");
                }
                break;
            }
            case DOWN : {
                if (y < 19) {
                    gotoxy(x - 1, y); printf("  ");
                    gotoxy(x - 1, y+=2); printf(">");
                }
                break;
            }
              
            }
        }
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
//�����Լ�
int main(void) {
    Title();
    menu();

}
