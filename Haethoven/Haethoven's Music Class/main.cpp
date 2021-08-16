#include<iostream>
#include <stdlib.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
#include <ctime>
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
void Info();
void Title();
int Menu();
void StartGame();
void Record();
int keyControl();



//전역변수
string name;
int score = 0;

//좌표함수
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//글자색
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


void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



//키보드 입력 제어
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
            else if (c == ' ')
                return SPACE;
        }
    }
}



//타이틀
void Title() {
    //아스키아트
    textcolor(YELLOW, BLACK);
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
    
    textcolor(WHITE, BLACK);
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

//메뉴제어
int Menu() {
    int x = 24;
    int y = 15;
    gotoxy(x - 1, y);
    cout << "> 게 임 시 작" << endl;
    gotoxy(x, y + 2);
    cout << "랭 킹 보 기" << endl;
    gotoxy(x, y + 4);
    cout << "게 임 종 료" << endl;
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 1, y); printf("  ");
                gotoxy(x - 1, y -= 2); printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 19) {
                gotoxy(x - 1, y); printf("  ");
                gotoxy(x - 1, y += 2); printf(">");
            }
            break;
        }
        case SPACE: {
            return y - 15;
        }
        }
    }
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
    gotoxy(40, 12);
    cout << "TIME" << endl;
    gotoxy(35, 20);
    cout << " ____________________________" << endl;
}
//게임실행화면
void StartGame() {
    system("cls");
    srand((int)time(0));     //문제 중복방지

    Record();
    //목숨

    textcolor(LIGHTRED, BLACK);
    gotoxy(4, 3);   cout << "♥ ♥ ♥" << endl;

    textcolor(WHITE, BLACK);
    //방향
    string str[5] = { "←","→","↑","↓","●" };
    int answer[40] = { 0, };
    int c = keyControl(); //입력값
    int x = 5; int y = 5; //초기 위치
    int rn;
    //시작지점
    gotoxy(x - 1, y - 1);
    cout << "Start" << endl;


  
    // int map = (rand() % 3) + 1;//맵 랜덤
    for (int j = 1; j <= 40; j++) {  //문제 실행
        rn = (rand() % 5); //문제 랜덤
        answer[j - 1] = rn; //문제 저장

        //map 1
      //  if (map == 1) {
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
        if (j == 40) { gotoxy(x, y);  cout << "GOAL" << endl; }

    }
 



 
    //정답 판단
    int a = 0;
    clock_t start = clock();
    for (;;) {
        clock_t end = clock();
        double time = double(end - start) / CLOCKS_PER_SEC; //초단위 변환
        gotoxy(40, 13);
        printf("경과시간 : %0.3lf\n", time); //소수점 셋째 자리까지
        while (a < 40) {

            gotoxy(40, 9);
            cout << score << "점" << endl;
            int n = keyControl();
            switch (n) {
            case LEFT:
                if (answer[a] == 0) score += 50;  break;
            case RIGHT:
                if (answer[a] == 1) score += 50;  break;
            case UP:
                if (answer[a] == 2) score += 50;  break;
            case DOWN:
                if (answer[a] == 3) score += 50;  break;
            case SPACE:
                if (answer[a] == 4) score += 50;  break;
            }
            a++;
        }
    }
       system("pause>null");
    }


//게임설명
void Info() {
    system("cls");
    /*  gotoxy(15, 3);
      cout << "18세기에 베토벤이 있다면 21세기엔 해토벤이 있다?" << endl;*/
    gotoxy(25, 5);
    cout << "<게 임 설 명>" << endl;
    gotoxy(16, 7);
    cout << "키보드 방향키 → ← ↑ ↓ 를 사용하여 점수를 올리세요! " << endl;
    gotoxy(17, 9);
    cout << "기회는 3번! 100초 안에 많은 점수를 획득하세요!" << endl;
    gotoxy(17, 11);
    cout << "ESC를 누르면 메인화면으로 이동 할 수있습니다!" << endl;
    gotoxy(16, 13);
    cout << "해토벤이 될 수있는 기회! 지금 랭킹 올리러 가볼까요?" << endl;

    //이름받기
    gotoxy(24, 15);
    cout << "이름을 입력하세요!" << endl;
    gotoxy(24, 17);
    cout << ">";
    cin >> name;
    StartGame();
    system("pause>null");
}

//메인함수
int main(void) {
    // system("mode con: cols=80 lines=20"); //가로 세로 콘솔크기 추가
    while (true) {
        Title();
        switch (Menu()) {
        case 0: Info(); break; //게임시작
        case 2: Info(); break; //랭킹보기
        case 4: return 0; //게임종료
        }
        system("cls");
    }

}
