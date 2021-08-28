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
 int clr[6] = { 9,10,11,12,13,14 }; //컬러 랜덤
 int clrRn;//컬러 랜덤 인덱스
 int h; //하트 좌표 값 
 string heart = "♥ ♥ ♥";


 void DeleteHeart() { //하트제거
     if (hcnt == 0) { heart = "♥ ♥ ♥";  h = 6; }
     else if (hcnt == 1) {heart = "♥ ♥"; h = 5; }
     else if (hcnt == 2) {heart = " ♥"; h = 4;}
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
     gotoxy(4, 3);   cout << heart << endl;
 
 }

 int DeleteHeartX() { //하트제거 X좌표
     if (hcnt == 0) {h = 6; }
     else if(hcnt == 1) { h = 5; }
     else if (hcnt == 2){  h = 4; }
     return h;

 }

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
    srand((int)time(0));     

    Record(); //점수 기록판

    gotoxy(4, 2);   cout << "게임을 시작하려면 스페이스를 눌러주세요!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

    int c = keyControl(); //입력값

    //단계
   Stage1(40);
    Stage2(50);

    system("pause>null");
}



clock_t old_time, cur_time; //시간체크

//정답 판단
void Check(int max) {

    old_time = clock();    //시작 시간

    int i = 0;
    x = 5; y = 5; //초기좌표 다시 설정
    int h = DeleteHeartX(); //하트 좌표 값 설정

    while (i < max) {


        cur_time = clock();  //현재  시간
        if (((double)(cur_time - old_time) / CLOCKS_PER_SEC) > 25) {
            GameOver();  break;   } //시간초과되면 게임오버

        if (hcnt == 3) { GameOver(); break; } //실수가 3번이면 게임오버
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(40, 9); cout << score << "점" << endl;

        int n = keyControl(); //입력값


        //방향키 제거
        if (max == 40) { //1단계
            switch (i / 5)
            {
            case 0: gotoxy(x, y++);  cout <<" "; break;
            case 1:  gotoxy(x++, y);  cout << " "; break;
            case 2:  gotoxy(x, y++);  cout << " "; break;
            case 3: gotoxy(x++, y);  cout << " "; break;
            case 4: gotoxy(x, y--);  cout << " "; break;
            case 5: gotoxy(x++, y);  cout << " "; break;
            case 6:  gotoxy(x, y++);  cout << " "; break;
            case 7:  gotoxy(x++, y);  cout << " "; break;
            }
        }

        //답 판단
        switch (n) {
        case 27: main(); break;
        case LEFT:
            if (answer[i] == 0) score += 10;
            else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
        case RIGHT:
            if (answer[i] == 1) score += 10;
            else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
        case UP:
            if (answer[i] == 2) score += 10;
            else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
        case DOWN:
            if (answer[i] == 3) score += 10;
            else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
        case SPACE:
            if (answer[i] == 4) score += 10;
            else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;

        }
        i++;
    }

}


//게임오버
void GameOver() {
    x = 5; y = 5; //초기좌표 다시 설정
    score = 0;
    hcnt = 0;  //점수, 실수 초기화
    int h = DeleteHeartX(); //하트 좌표 값 설정

    system("cls");
    cout << "게임 오버~~~";
    system("pause>null");
    main();
}


void Stage1(int max) {
    DeleteHeart(); //하트수 판단

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1);  cout << "Start" << endl;
    gotoxy(4, 2);   cout << "STAGE 1                                        " << endl; //시작문구 삭제


    for (int j = 0; j < max; j++) {  //문제 실행
        clrRn = rand() % 6;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //문제 랜덤
        answer[j] = rn; //문제 저장

        switch (j/5)
        {
        case 0: gotoxy(x, y++);  cout << str[rn]; break;
        case 1:  gotoxy(x++, y);  cout << str[rn];  break;
        case 2:  gotoxy(x, y++);  cout << str[rn];  break;
        case 3: gotoxy(x++, y);  cout << str[rn]; break;
        case 4: gotoxy(x, y--);  cout << str[rn];  break;
        case 5: gotoxy(x++, y);  cout << str[rn]; break;
        case 6:  gotoxy(x, y++);  cout << str[rn]; break;
        case 7:  gotoxy(x++, y);  cout << str[rn]; break;
        } 
        //골 지점
        if (j == 39) { 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            gotoxy(x, y);  cout << "GOAL" << endl; }
    }
    Check(40);
    system("cls");
}

void Stage2(int max) {
    DeleteHeart();
    x = 5;  y = 5; //초기 위치
  
    gotoxy(x - 1, y - 1);
    cout << "Start" << endl; //시작위치

    gotoxy(4, 2);   cout << "STAGE 2" << endl; 
    for (int j = 0; j < max; j++) {  //문제 실행

        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //문제 랜덤
        answer[j] = rn; //문제 답 저장

        if (j < 20) {
            gotoxy(x++, y);  cout << str[rn];
        }

        else if (j < 32) {
            gotoxy(x--, y++);  cout << str[rn];
        }

        else if (j >= 32) {
            gotoxy(x++, y); cout << str[rn];

            //골 지점
            if (j == 39) { gotoxy(x, y);  cout << "GOAL" << endl; }
        }
    }
    Check(50);
    system("cls");
}
