#include "haethoven.h"
#include <thread>
using namespace std;




//��������
//int tt; //Ÿ�̸�
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



//void timer() {
//    tt = 102;
//    while (1) {
//        if (tt == 0 || hcnt == 3 || clear == 0) break;
//
//        gotoxy(37, 13); cout << tt << "��  ";
//        Sleep(1000);
//        --tt;
//        if (tt == 0) { GameOver(); break; }
//    }
//
//    //over = 0;
//}





//���ӽ���ȭ��
void StartBonus() {
    //thread t1(timer);

    system("cls");
    gotoxy(20, 10);  cout << "2���� ����" << endl;
    Sleep(1000);
    system("cls");
    srand((int)time(0));

    //�ܰ�
     BonusStage(40);
    GameClear();

    system("pause>null");
   // t1.join();
}

//����Ŭ����
void GameClear() {
    score += 50;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(9, 3); cout << " _____   ___  ___  ___ _____   _____  _      _____   ___  ______ " << endl;
    gotoxy(9, 4);  cout << "|  __ \\ / _ \\ |  \\/  ||  ___| /  __ \\| |    |  ___| / _ \\ | ___ \\" << endl;
    gotoxy(9, 5); cout << "| |  \\// /_\\ \\| .  . || |__   | /  \\/| |    | |__  / /_\\ \\| |_/ /" << endl;
    gotoxy(9, 6); cout << "| | __ |  _  || |\\/| ||  __|  | |    | |    |  __| |  _  ||    /  " << endl;
    gotoxy(9, 7); cout << "| |_\\ \\| | | || |  | || |___  | \\__/\\| |____| |___ | | | || |\\ \\   " << endl;
    gotoxy(9, 8); cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\____/\\_____/\\____/ \\_| |_/\\_| \\_| " << endl;
    gotoxy(18, 16);  cout << "���ʽ� �������� ����!" << endl;
    gotoxy(18, 17);  cout << "���ʽ� ���� +50 ȹ��!" << endl;
    gotoxy(22, 11);  cout << "���� ���� : " << score<< endl;
    gotoxy(15, 18);  cout << "����ȭ������ ���ư����� SPACEŰ�� �����ּ���" << endl;
    system("pause>null");
    Reset();
    main();
}



//���� �Ǵ�
// �ܰ�/�Է°�/������/������ǥ
void Check(int step, int answer[], int max, int x, int y) {

    int i = 0;
    while (i < max) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(37, 10);
        cout << score << "��" << endl;
        //�Ǽ�3�� Ÿ�ӿ���
        if (hcnt == 3) {
            B_GameOver();
        }

        int n = keyControl(); //���� �Է�

        //����Ű ����
       if (step == 2) { //2�ܰ�
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
    Check(2, answer, 40, 5, 5);
    system("cls");
}

//���ӿ���
void B_GameOver() {
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(11, 3); cout << " _____   ___  ___  ___ _____   _____  _   _  _____ ______ " << endl;
    gotoxy(11, 4);  cout << "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | ||  ___|| ___ \\" << endl;
    gotoxy(11, 5); cout << "| |  \\// /_\\ \\| .  . || |__   | | | || | | || |__  | |_/ /" << endl;
    gotoxy(11, 6); cout << "| | __ |  _  || |\\/| ||  __|  | | | || | | ||  __| |    / " << endl;
    gotoxy(11, 7); cout << "| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ /| |___ | |\\ \\  " << endl;
    gotoxy(11, 8); cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/ \\____/ \\_| \\_| " << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(22, 13);  cout << "���� ���� : " << score << endl;
    gotoxy(22, 14);  cout << "���ʽ� ���� ȹ�� ���Ф̤�"<< endl;
    gotoxy(15, 18);  cout << "����ȭ������ ���ư����� SPACEŰ�� �����ּ���" << endl;
    // t1.detach();
    system("pause>null");
    Reset();
    main();
}


