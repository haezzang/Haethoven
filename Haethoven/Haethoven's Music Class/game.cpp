#include "haethoven.h"
using namespace std;




//전역변수
extern string name;
 int score = 0;
 string str[5] = { "←","→","↑","↓","●" };
 int answer[40] = { 0, }; //답체크
 int x = 5; 
 int y = 5; //초기 위치
 int rn; //문제 랜덤
 int hcnt = 0; //실수 횟수


//점수판과 제한시간
void Record() {
    gotoxy(35, 4);
    cout << name << "님의 기록판" << endl;
    gotoxy(35, 5);
    cout << " ____________________________" << endl;
    gotoxy(40, 8);
    cout << "S C O R E" << endl;
    gotoxy(40, 9);
    cout << score << "점" << endl;
    gotoxy(40, 11);
    cout << "제한시간" << endl;


    gotoxy(35, 20);
    cout << " ____________________________" << endl;
}


//게임실행화면
void StartGame() {
    system("cls");
    srand((int)time(0));     //문제 중복방지

    Record();
    //목숨
    gotoxy(4, 2);   cout << "게임을 시작하려면 스페이스를 눌러주세요!" << endl;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    gotoxy(4, 3);   cout << "♥ ♥ ♥" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    //문제설정

    int c = keyControl(); //입력값

    //시작지점
    Stage1(40);
    Stage2(40);

    system("pause>null");
}


//정답 판단
void Check(int max) {

    int i = 0;
    x = 5; y = 5; //초기좌표 다시 설정
    int h = 4; //하트 좌표 값 설정

    while (i < max) {

        if (hcnt == 3) { GameOver(); break; }

        gotoxy(40, 9);
        cout << score << "점" << endl;
        int n = keyControl();
        if (max == 40) {
            if (i < 20) {
                gotoxy(x++, y);  cout << " "; //누르면 사라짐
            }

            else if (i < 32) {
                gotoxy(x--, y++);  cout << " "; //누르면 사라짐
            }

            else if (i >= 32) {
                gotoxy(x++, y);  cout << " "; //누르면 사라짐
            }
        }
        switch (n) {
        case LEFT:
            if (answer[i] == 0) score += 10;
            else { hcnt++;  gotoxy(h++, 3); cout << " "; } break;
        case RIGHT:
            if (answer[i] == 1) score += 10;
            else { hcnt++;  gotoxy(h++, 3); cout << " "; } break;
        case UP:
            if (answer[i] == 2) score += 10;
            else { hcnt++;  gotoxy(h++, 3); cout << " "; } break;
        case DOWN:
            if (answer[i] == 3) score += 10;
            else { hcnt++;  gotoxy(h++, 3); cout << " "; } break;
        case SPACE:
            if (answer[i] == 4) score += 10;
            else { hcnt++;  gotoxy(h++, 3); cout << " "; } break;

        }
        i++;
    }

}

void GameOver() {
    x = 5; y = 5; //초기좌표 다시 설정
    int h = 4; //하트 좌표 값 설정

    score = 0;
    hcnt = 0;
    system("cls");
    cout << "게임 오버~~~";
    system("pause>null");
    main();
}


void Stage1(int max) {


    gotoxy(x - 1, y - 1);
    cout << "Start" << endl;
    gotoxy(4, 2);   cout << "STAGE 1                                        " << endl; //시작문구 삭제
    for (int j = 0; j < max; j++) {  //문제 실행

        rn = (rand() % 5); //문제 랜덤
        answer[j] = rn; //문제 저장

        if (j < 20) {
            gotoxy(x++, y);  cout << str[rn] << endl;
        }

        else if (j < 32) {
            gotoxy(x--, y++);  cout << str[rn] << endl;
        }

        else if (j >= 32) {
            gotoxy(x++, y); cout << str[rn] << endl;
        }

        //골 지점
        if (j == 39) { gotoxy(x, y);  cout << "GOAL" << endl; }
    }
    Check(40);
    system("cls");
}

void Stage2(int max) {
    x = 5;
    y = 5; //초기 위치
    int h = 4; //하트 좌표 값 

    gotoxy(x - 1, y - 1);
    cout << "Start" << endl;
    gotoxy(4, 2);   cout << "STAGE 1                                        " << endl; //시작문구 삭제
    for (int j = 0; j < max; j++) {  //문제 실행

        rn = (rand() % 5); //문제 랜덤
        answer[j] = rn; //문제 저장

        if (j < 20) {
            gotoxy(x++, y);  cout << str[rn] << endl;
        }

        else if (j < 32) {
            gotoxy(x--, y++);  cout << str[rn] << endl;
        }

        else if (j >= 32) {
            gotoxy(x++, y); cout << str[rn] << endl;
        }

        //골 지점
        if (j == 39) { gotoxy(x, y);  cout << "GOAL" << endl; }
    }
    Check(40);
    system("cls");
}
