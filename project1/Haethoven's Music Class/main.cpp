#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;
//디코딩 폰트 32

//키보드 정의
#define UP  0
#define DOWN  1
#define RIGHT  3
#define LEFT  4
#define SPACE 5
#define ESC 6


//함수 정의
void ReadyGame();
void StartGame();
int keyControl();


//좌표함수
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//커서 제어
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


//타이틀
void Title() {
    //아스키아트
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
    cout << "해토벤의 음악교실" << endl;
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
        cout << "> 게 임 시 작" << endl;
        gotoxy(x, y+2);
        cout << "랭 킹 보 기" << endl;
        gotoxy(x, y+4);
        cout << "게 임 종 료" << endl;
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


//게임실행화면
void StartGame() {
    system("cls"); 
    srand((int)time(0));     //문제 중복방지

    string str[5] = { "←","→","↑","↓" };

    int x = 5; int y = 5; //문제 위치


    for (int j = 1; j <= 20; j++) {  //문제 실행
        int rn = (rand() % 4);
        gotoxy(x++, y);

        cout << str[rn] << endl;
    }
}
//메인함수
int main(void) {
    Title();
    menu();

}
