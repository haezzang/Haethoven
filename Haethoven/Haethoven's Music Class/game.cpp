#include "haethoven.h"
#include <thread>
#include <mutex>
using namespace std;
std::mutex mu1, mu2,mu3;
//전역변수
int ct; //타이머
int hcnt = 0; //실수 횟수
int scnt = 1; //스테이지 단계
string heart = "♥ ♥ ♥";
extern string name; //유저 네임
int score = 0; //점수
int n = -1; //입력값
int res; //정답 판단 위치
string SongName = ""; //노래 이름
int x = 5;
int y = 5; //초기 위치
int rn; //문제 랜덤
int songRn;//노래 랜덤
int clr[6] = { 9,10,11,12,13,14 }; //컬러 랜덤
int clrRn;//컬러 랜덤 인덱스
string str[5] = { "←","→","↑","↓","●" };
int h = 0;//하트좌표
bool nchk;
bool fin = 1;
//점수 저장
void Save() {

    ofstream fout("rank.txt", ios::app);
    fout << name << "\t" << score << endl;
    fout.close();
}


void DeleteHeart() { //하트제거
    if (hcnt == 0) { heart = "♥ ♥ ♥";  }
    else if (hcnt == 1) { heart = "♥ ♥  "; }
    else if (hcnt == 2) { heart = " ♥     "; }
    else if (hcnt >=3) { heart = "       "; }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
    gotoxy(5, 4);   cout << heart << endl;

}



//정보리셋
void Reset() {
    Save();
    x = 5; y = 5; //초기좌표 다시 설정
    score = 0;
    hcnt = 0;  //점수, 실수 초기화
    main();
}

//점수판과 제한시간
void Record(int chk) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(31, 6); cout << "> " << name << " < 게임중" << endl;
    gotoxy(31, 7); cout << "┌────────────────────────────┐" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
    gotoxy(36, 9); cout << "S C O R E" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

  
    if (chk == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
        gotoxy(36, 12); cout << "남은 시간"<< endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

    gotoxy(31, 15); cout << "└────────────────────────────┘" << endl;

}



void input() {
    //하트 좌표 값 설정


        while (fin) {
       

            if (hcnt == 3) break;
      
            n = keyControl(); //정답 입력


            switch (n) {
                ;
            case LEFT: nchk = 1;
                if (rn == 0 && res > 17 && res < 22) { score += 10; }
                else { hcnt++;    DeleteHeart(); } break;
            case RIGHT: nchk = 1;
                if (rn == 1 && res > 17 && res < 22) { score += 10; }
                else { hcnt++;     DeleteHeart(); } break;
            case UP: nchk = 1;
                if (rn == 2 && res > 17 && res < 22) { score += 10; }
                else { hcnt++;   DeleteHeart(); } break;
            case DOWN:
                if (rn == 3 && res > 17 && res < 22) { score += 10; }
                else { hcnt++;     DeleteHeart(); } break;
            case SPACE: nchk = 1;
                if (rn == 4 && res > 17 && res < 22) { score += 10; }
                else { hcnt++;     DeleteHeart(); } break;

            }

     
    }



}
//2초 대기
void Wait() {
    srand((int)time(0));
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(18, 3); cout << "  /\\";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << "      지금 무슨 곡??" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(18, 4); cout << "  /\\" << endl;
    gotoxy(18, 5); cout << ".o＿o" << endl;
    gotoxy(18, 6);  cout << "( >3<)つ━☆♪*。" << endl;
    gotoxy(18, 7); cout << "⊂　 ノ 　　　♪♪+." << endl;
    gotoxy(18, 8); cout << "しㅡＪ　　　°。+ *" << endl;
    int songRn = rand() % 5;
    string desc = " 를 연주 해보자 !";
    //노래 랜덤
    switch (songRn)
    {
    case 0:   SongName = "더보이즈-D.D.D"; PlaySound(TEXT("ddd.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
    case 1:   SongName = "방탄소년단-Dynamite";  PlaySound(TEXT("dynamite.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
    case 2:  SongName = "엔시티드림-고래";  PlaySound(TEXT("diveintoyou.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
    case 3:   SongName = "블랙핑크-Lovesick Girls"; PlaySound(TEXT("lovesickgirls.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
    case 4:   SongName = "트와이스-What is love";  PlaySound(TEXT("whatislove.wav"), NULL, SND_FILENAME | SND_ASYNC); break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTCYAN);
    gotoxy(18, 11);  cout << SongName << desc << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
    gotoxy(23, 13);  cout << "1초후 시작합니다." << endl;
    Sleep(2000);
    system("cls");
}


//게임실행화면
void StartGame() {
    system("cls");

    fin = 1;
    thread input(input);

    Wait();
    Stage();      
    input.join();
    system("pause>null");
  

}


//게임오버
void GameOver() {
    nchk = 1;
    fin = 0;
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(11, 3); cout << " _____   ___  ___  ___ _____   _____  _   _  _____ ______ " << endl;
    gotoxy(11, 4);  cout << "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | ||  ___|| ___ \\" << endl;
    gotoxy(11, 5); cout << "| |  \\// /_\\ \\| .  . || |__   | | | || | | || |__  | |_/ /" << endl;
    gotoxy(11, 6); cout << "| | __ |  _  || |\\/| ||  __|  | | | || | | ||  __| |    / " << endl;
    gotoxy(11, 7); cout << "| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ /| |___ | |\\ \\  " << endl;
    gotoxy(11, 8); cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/ \\____/ \\_| \\_| " << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(22, 13);  cout << "최종 점수 : " << score << endl;
    gotoxy(15, 18);  cout << "메인화면으로 돌아가려면 SPACE키를 눌러주세요" << endl;

    system("pause>null");


    //보너스게임 랜덤
    int b_rnd;
    
    b_rnd= (rand() % 2);

    if(b_rnd==0) StartBonus();
    else Reset();
}


void note() {
    srand((int)time(0));
    int index[4] = { 8,10,12,14 }; //노트 떨어지는 위치


    int speed=100;

    while (true) {
        int irn = (rand() % 4); //인덱스 랜덤
        mu1.lock();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(37, 10); cout << score << "점" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
        gotoxy(36, 12); cout << "스테이지 "; 
        gotoxy(37, 13); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE); cout<< scnt <<"단계"<< endl;
        mu1.unlock();
        if (hcnt == 3) break;
        int i = 5;
  
        rn = (rand() % 5);  //방향키 랜덤

        //속도 조정
        if (score<100) { speed = 80; }
        else if (score>=100 && score<200) { speed = 65; scnt=2; }
        else if (score >= 200 && score <300) { speed = 50; scnt=3;  }
        else if (score >= 300 && score <400) { speed = 40; scnt=4;  }
        else if (score >= 400 && score <500) { speed = 30; scnt=5;  }
        else if (score >= 500 && score < 600) { speed = 20; scnt = 6; }
        else if (score >= 600 && score < 700) { speed = 10; scnt = 7; }
        nchk = 0;
        for (i = 5; i < 23; i++) {
            if (nchk == 1) break;
            else if (hcnt == 3) break;    
            else if (res == 22 && nchk==0) { hcnt++; DeleteHeart(); }
            res = i;
            clrRn = rand() % 6;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
            mu2.lock();

            gotoxy(i, index[irn]); cout << str[rn] << endl;
            Sleep(speed);
            gotoxy(i, index[irn]);  cout << "  " << endl;
      
            mu2.unlock();

        }

    }
    GameOver();

}

void printMap() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTCYAN);
    gotoxy(5, 2);
    cout << SongName << " 연주중 ♪";
    gotoxy(19, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << "PUSH!";
    for (int i = 7; i <= 15; i += 2) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(5, i);
        cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
    }
    for (int i = 7; i <= 15; i += 2) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        gotoxy(18, i);
        cout << "■■■■■■■";
    }
    for (int i = 8; i <= 14; i += 2) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
        if (i == 8 || i == 10 || i == 12 || i == 14) {
            gotoxy(23, i);
            cout << "■";
        }
    }



}

void Stage() {
    DeleteHeart();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    Record(1); //점수 기록판
    printMap();//맵 
    note(); //노트 떨어지기



}
