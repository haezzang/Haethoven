#include "haethoven.h"
#include <thread>
using namespace std;




//��������

extern int hcnt; //�Ǽ� Ƚ��
extern string heart;
extern string name;
extern int score;
extern int x;
extern int y; //�ʱ� ��ġ
extern int rn; //���� ����
extern int clr[6]; //�÷� ����
extern int clrRn;//�÷� ���� �ε���
extern string str[5];
 int tt;
int over = 0;


void timer() {
    tt= 11;
    while (1) {
        if (tt== 0 || hcnt == 3 || tt== 0) break;
        Sleep(1000);
        gotoxy(37, 13); cout << --tt << "��  ";
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
    gotoxy(9, 11); cout << "���ʽ� ���������� ���� ������ �� �÷�������!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
    gotoxy(9, 13); cout << "MISSION : 10�ʾȿ� Ŭ�����ϸ� ���ʽ� ������ +50!!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(9, 15); cout << "���ӹ�� : ����Ű�� �����ϸ� ������ ����Ű���� ������ ��������!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    gotoxy(9, 18); cout << "���� �ҷ��� �����̽��� �����ּ���!" << endl;
    int n = keyControl(); //ȭ�� �Է�
}
//���ӽ���ȭ��
void StartBonus() {
    srand((int)time(0));
  

    B_Wait();
    system("cls");
    thread timer(timer);
    //�ܰ�
    BonusStage(40);
    if (over == 1) {
        B_GameOver();
    }
    else GameClear();

    timer.join();

    

    system("pause>null");
  
}

//����Ŭ����
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
    gotoxy(22, 11);  cout << "���� ���� : " << score<< endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(17, 14);  cout << "���ʽ� �������� ����! ���� +50 ȹ��" << endl;;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    gotoxy(15, 18);  cout << "����ȭ������ ���ư����� SPACEŰ�� �����ּ���" << endl;
    system("pause>null");
    Reset();
    main();
}



//���� �Ǵ�
//�Է°� ������ǥ
void Check( int answer[],  int x, int y) {

    int i = 0;
    while (i <40){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(37, 10);
        cout << score << "��" << endl;
        //�Ǽ�3�� Ÿ�ӿ���
        if (hcnt == 3) {
            over = 1;
            break;
        }

        int n = keyControl(); //���� �Է�

        //����Ű ����
   
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


        //�� �Ǵ�

        switch (n) {
            // case 27: GameOver(); break; ������ �ϱ� ����!
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
    Record(); //���� �����
    DeleteHeart(); //��Ʈ�� �Ǵ�
    int answer[40] = { 0, }; //��üũ
    x = 5;  y = 5; //�ʱ� ��ġ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1);  cout << "START" << endl;
    gotoxy(4, 2);   cout << "BONUS STAGE                                       " << endl; //���۹��� ����


    for (int j = 0; j < max; j++) {  //���� ����
        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� ����

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
        //�� ����
        if (j == 39) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            gotoxy(x, y);  cout << "GOAL" << endl;
        }
    }
    Check(answer, 5, 5);
    system("cls");
}

//���ӿ���
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
    gotoxy(22, 11);  cout << "���� ���� : " << score << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(20, 14);  cout << "���ʽ� �������� ����.." << endl;;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    gotoxy(15, 18);  cout << "����ȭ������ ���ư����� SPACEŰ�� �����ּ���" << endl;

    system("pause>null");
    over = 0;
    Reset();
    main();
}


