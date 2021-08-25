#include "haethoven.h"
using namespace std;




//��������
extern string name;
 int score = 0;
 string str[5] = { "��","��","��","��","��" };
 int answer[40] = { 0, }; //��üũ
 int x = 5; 
 int y = 5; //�ʱ� ��ġ
 int rn; //���� ����
 int hcnt = 0; //�Ǽ� Ƚ��
 int clr[6] = { 9,10,11,12,13,14 }; //�÷� ����


 //�ð�
 time_t startTime = 0, endTime = 0; // ���� �ð� ����
 double user_time; // ���� �ð�

//�����ǰ� ���ѽð�
void Record() {
    gotoxy(35, 4);
    cout << name << "���� �����" << endl;
    gotoxy(35, 5);
    cout << " ____________________________" << endl;
    gotoxy(40, 8);
    cout << "S C O R E" << endl;
    gotoxy(40, 9);
    cout << score << "��" << endl;
    gotoxy(40, 11);
    cout << "���ѽð�" << endl;


    gotoxy(35, 20);
    cout << " ____________________________" << endl;
}


//���ӽ���ȭ��
void StartGame() {
    system("cls");
    srand((int)time(0));     //���� �ߺ�����

    Record();
    //���
    gotoxy(4, 2);   cout << "������ �����Ϸ��� �����̽��� �����ּ���!" << endl;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
    gotoxy(4, 3);   cout << "�� �� ��" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    //��������

    int c = keyControl(); //�Է°�

    //��������
    Stage1(40);
    Stage2(40);

    system("pause>null");
}

clock_t old_time, cur_time;

//���� �Ǵ�
void Check(int max) {

    old_time = clock();    //���� �ð�

    int i = 0;
    x = 5; y = 5; //�ʱ���ǥ �ٽ� ����
    int h = 4; //��Ʈ ��ǥ �� ����

    while (i < max) {


        cur_time = clock();  //����  �ð�
        if (((double)(cur_time - old_time) / CLOCKS_PER_SEC) > 25) {
            GameOver();  break;
        }

        if (hcnt == 3) { GameOver(); break; }
        
        gotoxy(40, 9);
        cout << score << "��" << endl;
        int n = keyControl();


        if (max == 40) {
            if (i < 20) {
                gotoxy(x++, y);  cout << "  "; //������ �����
            }

            else if (i < 32) {
                gotoxy(x--, y++);  cout << "  "; //������ �����
            }

            else if (i >= 32) {
                gotoxy(x++, y);  cout << "  "; //������ �����
            }
        }
        switch (n) {
        case LEFT:
            if (answer[i] == 0) score += 10;
            else { hcnt++;  gotoxy(h++, 3);  cout << " "; } break;
        case RIGHT:
            if (answer[i] == 1) score += 10;
            else { hcnt++;  gotoxy(h++, 3);  cout << " "; } break;
        case UP:
            if (answer[i] == 2) score += 10;
            else { hcnt++;  gotoxy(h++, 3);  cout << " "; } break;
        case DOWN:
            if (answer[i] == 3) score += 10;
            else { hcnt++;  gotoxy(h++, 3);  cout << " "; } break;
        case SPACE:
            if (answer[i] == 4) score += 10;
            else { hcnt++;  gotoxy(h++, 3);  cout << " "; } break;

        }
        i++;
    }

}

void GameOver() {
    x = 5; y = 5; //�ʱ���ǥ �ٽ� ����
    int h = 4; //��Ʈ ��ǥ �� ����

    score = 0;
    hcnt = 0;
    system("cls");
    cout << "���� ����~~~";
    system("pause>null");
    main();
}


void Stage1(int max) {

    int clrRn;
    gotoxy(x - 1, y - 1);
    cout << "Start" << endl;
    gotoxy(4, 2);   cout << "STAGE 1                                        " << endl; //���۹��� ����
    for (int j = 0; j < max; j++) {  //���� ����
        clrRn = rand() % 6;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� ����

        if (j < 20) {
            gotoxy(x++, y);  cout << str[rn];
        }

        else if (j < 32) {
            gotoxy(x--, y++);  cout << str[rn];
        }

        else if (j >= 32) {
            gotoxy(x++, y); cout << str[rn];
        }

        //�� ����
        if (j == 39) { gotoxy(x, y);  cout << "GOAL" << endl; }
    }
    Check(40);
    system("cls");
}

void Stage2(int max) {
  
    x = 5;
    y = 5; //�ʱ� ��ġ
    int h = 4; //��Ʈ ��ǥ �� 

    gotoxy(x - 1, y - 1);
    cout << "Start" << endl;
    gotoxy(4, 2);   cout << "STAGE 1                                        " << endl; //���۹��� ����
    for (int j = 0; j < max; j++) {  //���� ����

        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� ����

        if (j < 20) {
            gotoxy(x++, y);  cout << str[rn];
        }

        else if (j < 32) {
            gotoxy(x--, y++);  cout << str[rn];
        }

        else if (j >= 32) {
            gotoxy(x++, y); cout << str[rn];

            //�� ����
            if (j == 39) { gotoxy(x, y);  cout << "GOAL" << endl; }
        }
    }
    Check(40);
    system("cls");
}
