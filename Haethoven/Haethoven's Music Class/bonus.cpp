#include "haethoven.h"
#include <thread>
using namespace std;




//전역변수

extern int hcnt; //실수 횟수
extern string heart;
extern string name;
extern int score;
extern int x;
extern int y; //초기 위치
extern int rn; //문제 랜덤
extern int clr[6]; //컬러 랜덤
extern int clrRn;//컬러 랜덤 인덱스
extern string str[5];
 int tt;
int over = 0;


void timer() {
    tt= 11;
    while (1) {
        if (tt== 0 || hcnt == 3 || tt== 0) break;
        Sleep(1000);
        gotoxy(37, 13); cout << --tt << "초  ";
    }
    over = 1;
    system("cls");

}




void B_Wait() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(9, 3); cout << " ______  _____  _   _  _   _  _____ " << endl;
    gotoxy(9, 4); cout << " | ___ \\|  _  || \\ | || | | |/  ___|" << endl;
    gotoxy(9, 5); cout << " | |_/ /| | | ||  \\| || | | |\\ `--. " << endl;
    gotoxy(9, 6); cout << " | ___ \\| | | || . ` || | | | `--. \\" << endl;
    gotoxy(9, 7); cout << " | |_/ /\\ \\_/ /| |\\  || |_| |\____/ /" << endl;
    gotoxy(9, 8); cout << " \\____/  \\___/ \\_| \\_/ \\___/ \\____/ " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(9, 11); cout << "보너스 스테이지를 통해 순위를 더 올려보세요!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
    gotoxy(9, 13); cout << "MISSION : 10초안에 클리어하면 보너스 점수가 +50!!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(9, 15); cout << "게임방법 : 조작키는 동일하며 나열된 방향키들을 빠르게 누르세요!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    gotoxy(9, 18); cout << "시작 할려면 스페이스를 눌러주세요!" << endl;
    int n = keyControl(); //화면 입력
}
//게임실행화면
void StartBonus() {
    srand((int)time(0));
  

    B_Wait();
    system("cls");
    thread timer(timer);
    //단계
    BonusStage(40);
    if (over == 1) {
        B_GameOver();
    }
    else GameClear();

    timer.join();

    

    system("pause>null");
  
}

//게임클리어
void GameClear() {

    Sleep(1000);
    score += 50;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(9, 3); cout << " _____   ___  ___  ___ _____   _____  _      _____   ___  ______ " << endl;
    gotoxy(9, 4);  cout << "|  __ \\ / _ \\ |  \\/  ||  ___| /  __ \\| |    |  ___| / _ \\ | ___ \\" << endl;
    gotoxy(9, 5); cout << "| |  \\// /_\\ \\| .  . || |__   | /  \\/| |    | |__  / /_\\ \\| |_/ /" << endl;
    gotoxy(9, 6); cout << "| | __ |  _  || |\\/| ||  __|  | |    | |    |  __| |  _  ||    /  " << endl;
    gotoxy(9, 7); cout << "| |_\\ \\| | | || |  | || |___  | \\__/\\| |____| |___ | | | || |\\ \\   " << endl;
    gotoxy(9, 8); cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\____/\\_____/\\____/ \\_| |_/\\_| \\_| " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTCYAN);
    gotoxy(22, 11);  cout << "최종 점수 : " << score<< endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(17, 14);  cout << "보너스 스테이지 성공! 점수 +50 획득" << endl;;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    gotoxy(15, 18);  cout << "메인화면으로 돌아가려면 SPACE키를 눌러주세요" << endl;
    system("pause>null");
    Reset();
    main();
}



//정답 판단
//입력값 시작좌표
void Check( int answer[],  int x, int y) {

    int i = 0;
    while (i <40){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(37, 10);
        cout << score << "점" << endl;
        //실수3번 타임오버
        if (hcnt == 3) {
            over = 1;
            break;
        }

        int n = keyControl(); //정답 입력

        //방향키 제거
   
            switch (i / 5)
            {
            case 0: gotoxy(x, y++);  cout << " "; break;
            case 1:  gotoxy(x++, y);  cout << " "; break;
            case 2:  gotoxy(x, y++);  cout << " "; break;
            case 3: gotoxy(x++, y);  cout << " "; break;
            case 4: gotoxy(x, y--);  cout << " "; break;
            case 5: gotoxy(x++, y);  cout << " "; break;
            case 6:  gotoxy(x, y++);  cout << " "; break;
            case 7:  gotoxy(x++, y);  cout << " "; break;
        }


        //답 판단

        switch (n) {
            // case 27: GameOver(); break; 먹히게 하기 수정!
        case LEFT:
            if (answer[i] == 0) { score += 1; }
            else { hcnt++; DeleteHeart();  cout << " "; } break;
        case RIGHT:
            if (answer[i] == 1) { score += 1; }
            else { hcnt++; DeleteHeart();   cout << " "; } break;
        case UP:
            if (answer[i] == 2) { score += 1; }
            else { hcnt++; DeleteHeart();   cout << " "; } break;
        case DOWN:
            if (answer[i] == 3) { score += 1; }
            else { hcnt++; DeleteHeart();  cout << " "; } break;
        case SPACE:
            if (answer[i] == 4) { score += 1; }
            else { hcnt++;  DeleteHeart(); cout << " "; } break;
        }
        i++;
    }
}

void BonusStage(int max) {
    hcnt = 0;
    Record(); //점수 기록판
    DeleteHeart(); //하트수 판단
    int answer[40] = { 0, }; //답체크
    x = 5;  y = 5; //초기 위치
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1);  cout << "START" << endl;
    gotoxy(4, 2);   cout << "BONUS STAGE                                       " << endl; //시작문구 삭제


    for (int j = 0; j < max; j++) {  //문제 실행
        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //문제 랜덤
        answer[j] = rn; //문제 저장

        switch (j / 5)
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
            gotoxy(x, y);  cout << "GOAL" << endl;
        }
    }
    Check(answer, 5, 5);
    system("cls");
}

//게임오버
void B_GameOver() {
    system("cls");

    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(11, 3); cout << " _____   ___  ___  ___ _____   _____  _   _  _____ ______ " << endl;
    gotoxy(11, 4);  cout << "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | ||  ___|| ___ \\" << endl;
    gotoxy(11, 5); cout << "| |  \\// /_\\ \\| .  . || |__   | | | || | | || |__  | |_/ /" << endl;
    gotoxy(11, 6); cout << "| | __ |  _  || |\\/| ||  __|  | | | || | | ||  __| |    / " << endl;
    gotoxy(11, 7); cout << "| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ /| |___ | |\\ \\  " << endl;
    gotoxy(11, 8); cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/ \\____/ \\_| \\_| " << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTCYAN);
    gotoxy(22, 11);  cout << "최종 점수 : " << score << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(20, 14);  cout << "보너스 스테이지 실패.." << endl;;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    gotoxy(15, 18);  cout << "메인화면으로 돌아가려면 SPACE키를 눌러주세요" << endl;

    system("pause>null");
    over = 0;
    Reset();
    main();
}


