#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
using namespace std;
//디코딩 폰트 32

//방향 정의
#define UP = 0
#define DOWN = 1
#define RIGHT = 2
#define LEFT = 3


//함수프로토
void ReadyGame();
void StartGame();


//좌표함수
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//준비화면
void ReadyGame() {

    //아스키아트
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
    cout << "해토벤의 음악교실" << endl;
    gotoxy(13, 13);
    cout << " _____________________________________________________" << endl;
    gotoxy(13, 14);
    cout << "|                                                     |" << endl;
    gotoxy(13, 15);
    cout << "|                     게 임 시 작                     |" << endl;
    gotoxy(13, 16);
    cout << "|                                                     |" << endl;
    gotoxy(13, 17);
    cout << "|                     랭 킹 보 기                     |" << endl;
    gotoxy(13, 18);
    cout << "|                                                     |" << endl;
    gotoxy(13, 19);
    cout << "|                     게 임 종 료                     |" << endl;
    gotoxy(13, 20);
    cout << "|                                                     |" << endl;
    gotoxy(13, 21);
    cout << "|_____________________________________________________|" << endl;

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
    int main(void) {
        ReadyGame();

    }