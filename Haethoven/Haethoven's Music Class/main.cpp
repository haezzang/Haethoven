#include "haethoven.h"
using namespace std;
//디코딩 폰트 32





//전역변수
string name;


//좌표함수
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2*x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//커서없애기
void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
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
    PlaySound(TEXT("tt.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //아스키아트
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(11, 4);
    cout << " _   _   ___   _____  _____  _____  _   _  _____  _   _ " << endl;
    gotoxy(11, 5);
    cout << "| | | | / _ \\ |  ___||_   _||  _  || | | ||  ___|| \\ | |" << endl;
    gotoxy(11, 6);
    cout << "| |_| |/ /_\\ \\| |__    | |  | | | || | | || |__  |  \\| |" << endl;
    gotoxy(11, 7);
    cout << "|  _  ||  _  ||  __|   | |  | | | || | | ||  __| | . ` |" << endl;
    gotoxy(11, 8);
    cout << "| | | || | | || |___   | |  \\ \\_/ /\\ \\_/ /| |___ | |\\  |" << endl;
    gotoxy(11, 9);
    cout << "\\_| |_/\\_| |_/\\____/   \\_/   \\___/  \\___/ \\____/ \\_| \\_/" << endl;
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(31, 10);
    cout << "해토벤의 음악교실" << endl;
    gotoxy(11, 13);
    cout << "┌─────────────────────────────────────────────────────┐" << endl; 
    gotoxy(11, 14);
    cout << "│                                                     │"<< endl;
    gotoxy(11, 15);
    cout << "│                                                     │" << endl;
    gotoxy(11, 16);
    cout << "│                                                     │" << endl;
    gotoxy(11, 17);
    cout << "│                                                     │" << endl;
    gotoxy(11, 18);
    cout << "│                                                     │" << endl;
    gotoxy(11, 19);
    cout << "│                                                     │" << endl;
    gotoxy(11, 20);
    cout << "│                                                     │" << endl;
    gotoxy(11, 21);
    cout << "└─────────────────────────────────────────────────────┘" << endl;


    // system("pause>null");
}

//메뉴제어
int Menu() {

    int x = 22;
    int y = 14;
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
            if (y > 14) {
                gotoxy(x - 1, y); printf("  ");
                gotoxy(x - 1, y -= 2); printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 18) {
                gotoxy(x - 1, y); printf("  ");
                gotoxy(x - 1, y += 2); printf(">");
            }
            break;
        }
        case SPACE: {
            return y - 14;
        }
        }
    }
}



//게임설명
void Info() {
    system("cls");
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    cout << "\"18세기에 베토벤이 있다면 21세기엔 해토벤이 있다?\"" << endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << "<게 임 설 명>" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
    cout << "→ ← ↑ ↓";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << " 는 방향키!  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
    cout<<"●" ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cout << " 는 스페이스!"<<endl;
    cout << "옳은 키를 눌러 점수를 획득하세요." <<endl<<endl;
    cout << "기회는 3번이며, 제한시간 안에 스테이지를 클리어 하세요." <<endl<< endl;
    cout << "ESC를 누르면 메인화면으로 이동할 수 있습니다." <<endl<< endl;

    cout << "해토벤이 될 수있는 기회! 즐거운 피아노 연주하러 떠나볼까요?" <<endl<< endl;

    //이름받기
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    cout << " 이름을 입력해주세요." << endl;
    cout << " >";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    cin >> name;
    StartGame();
    system("pause>null");
}


//메인함수
int main(void) {

    CursorView();
    system("mode con: cols=100 lines=22"); //가로 세로 콘솔크기 추가
    while (true) {
        Title();
        switch (Menu()) {
        case 0: Info(); break; //게임시작
        case 2: PrintRankTitle(); break; //랭킹보기
        case 4: exit(0);  break; // 게임종료
        }
       
        system("cls");
    }
}