#include "haethoven.h"
#include <thread>
using namespace std;




//��������
int tt; //Ÿ�̸�
int hcnt = 0; //�Ǽ� Ƚ��
string heart = "�� �� ��";
extern string name;
int score = 0;


int x = 5;
int y = 5; //�ʱ� ��ġ
int rn; //���� ����

int clr[6] = { 9,10,11,12,13,14 }; //�÷� ����
int clrRn;//�÷� ���� �ε���
int h; //��Ʈ ��ǥ �� 
int over =1; //���ӿ���
int clear = 1; //����Ŭ����

string str[5] = { "��","��","��","��","��" };





//���� ����
void Save() {
    ofstream fout("rank.txt", ios::app);
    fout <<name<<"\t"<<score<< endl;
    fout.close();
}


void DeleteHeart() { //��Ʈ����
    if (hcnt == 0) { heart = "�� �� ��";  h = 6; }
    else if (hcnt == 1) { heart = "�� ��"; h = 5; }
    else if (hcnt == 2) { heart = " ��"; h = 4; }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
    gotoxy(4, 3);   cout << heart << endl;

}

int DeleteHeartX() { //��Ʈ���� X��ǥ
    if (hcnt == 0) { h = 6; }
    else if (hcnt == 1) { h = 5; }
    else if (hcnt == 2) { h = 4; }
    return h;

}

void timer() {
    tt = 100;
    while (1) {
        if (tt == 0 || hcnt == 3 || clear==0) break;
        gotoxy(37, 13); cout << tt << "��  ";
        Sleep(1000);
        --tt;
    }
    over = 0;
}

//��������
void Reset() {
    Save();
    x = 5; y = 5; //�ʱ���ǥ �ٽ� ����
    score = 0;
    hcnt = 0;  //����, �Ǽ� �ʱ�ȭ
    over = 1;
    int h = DeleteHeartX(); //��Ʈ ��ǥ �� ����
}
//�����ǰ� ���ѽð�
void Record() {

    gotoxy(31, 6);
    cout << "> " << name << " < ������" << endl;
    gotoxy(31, 7);
    cout << "������������������������������������������������������������" << endl;
    gotoxy(36, 9);
    cout << "S C O R E" << endl;
    gotoxy(37, 10);
    cout << score << "��" << endl;
    gotoxy(36, 12);
    cout << "���� �ð�" << endl;
  
    gotoxy(31, 15);
    cout << "������������������������������������������������������������" << endl;

}

//���ӽ���ȭ��
void StartGame() {
     thread t1(timer);
    system("cls");
    srand((int)time(0));
   
    //�ܰ�
        Stage1(40);
        Stage2(40);
        Stage3(50);
        Stage4(55);
        Stage5(60);
        GameClear();
       
    system("pause>null");
    t1.join();
}

//����Ŭ����
void GameClear() {
    clear = 0;

    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    gotoxy(9, 3); cout << " _____   ___  ___  ___ _____   _____  _      _____   ___  ______ " << endl;
    gotoxy(9, 4);  cout << "|  __ \\ / _ \\ |  \\/  ||  ___| /  __ \\| |    |  ___| / _ \\ | ___ \\" << endl;
    gotoxy(9, 5); cout << "| |  \\// /_\\ \\| .  . || |__   | /  \\/| |    | |__  / /_\\ \\| |_/ /" << endl;
    gotoxy(9, 6); cout << "| | __ |  _  || |\\/| ||  __|  | |    | |    |  __| |  _  ||    /  " << endl;
    gotoxy(9, 7); cout << "| |_\\ \\| | | || |  | || |___  | \\__/\\| |____| |___ | | | || |\\ \\   " << endl;
    gotoxy(9, 8); cout << " \\____/\\_| |_/\\_|  |_/\\____/   \\____/\\_____/\\____/ \\_| |_/\\_| \\_| " << endl;
    gotoxy(18, 16);  cout << "��� ���������� �����ϼ̽��ϴ�!" << endl;
    gotoxy(22, 11);  cout << "���� ���� : " << score << endl;
    gotoxy(15, 18);  cout << "����ȭ������ ���ư����� SPACEŰ�� �����ּ���" << endl;
    system("pause>null");
    Reset();
    main();

}
//���ӿ���
void GameOver() {
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
    gotoxy(15, 18);  cout << "����ȭ������ ���ư����� SPACEŰ�� �����ּ���" << endl;
    // t1.detach();
    system("pause>null");
    Reset();
    main();
}


//���� �Ǵ�
// �ܰ�/�Է°�/������/������ǥ
void Check(int step, int answer[], int max, int x, int y) {
 
    int i = 0;
    int h = DeleteHeartX(); //��Ʈ ��ǥ �� ����
    while (i < max) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        gotoxy(37, 10);
        cout << score << "��" << endl;
        //�Ǽ�3�� Ÿ�ӿ���
        if (hcnt == 3 || over == 0) {
            GameOver();
        }
 
        int n = keyControl(); //���� �Է�
        //����Ű ����
        if (step == 1) { //1�ܰ�
            if (i < 19) { gotoxy(x--, y);   cout << " "; }
            else  if (i < 21) { gotoxy(x, y++);   cout << " "; }
            else if (i < 50) { gotoxy(x++, y);   cout << " "; }
        }
        else  if (step == 2) { //2�ܰ�
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
        else  if (step == 3) {
            if (i < 2) { gotoxy(x, y++);   cout << " "; }
            else if (i < 8) { gotoxy(x--, y);   cout << " ";; }
            else if (i < 13) { gotoxy(x, y--);   cout << " "; }
            else if (i < 22) { gotoxy(x++, y);   cout << " "; }
            else if (i < 29) { gotoxy(x, y++);   cout << " "; }
            else if (i < 40) { gotoxy(x--, y);   cout << " "; }
            else if (i < 50) { gotoxy(x, y--);   cout << " "; }
        }
        else if (step == 4) {
            if (i < 10) { gotoxy(x--, y++);  cout << " "; }
            else if (i < 12) { gotoxy(x++, y);  cout << " "; }
            else if (i < 22) { gotoxy(x++, y--);  cout << " "; }
            else if (i < 24) { gotoxy(x++, y);  cout << " "; }
            else if (i < 34) { gotoxy(x--, y++);  cout << " "; }
            else if (i < 36) { gotoxy(x++, y); cout << " "; }
            else if (i < 46) { gotoxy(x++, y--); cout << " "; }
            else if (i < 48) { gotoxy(x++, y);  cout << " "; }
            else if (i < 55) { gotoxy(x++, y++);  cout << " "; }
        }
        else if (step == 5) {

            if (i < 8) { gotoxy(x++, y--);  cout << " "; }
            else if (i < 25) { gotoxy(x++, y);   cout << " "; }
            else if (i < 37) { gotoxy(x--, y++);  cout << " "; }
            else if (i < 52) { gotoxy(x--, y);   cout << " "; }
            else if (i < 54) { gotoxy(x, y--);   cout << " "; }
            else if (i < 60) { gotoxy(x++, y);   cout << " "; }

        }

        //�� �Ǵ�

            switch (n) {
           // case 27: GameOver(); break; ������ �ϱ� ����!
            case LEFT:
                if (answer[i] == 0) { score += 10; }
                else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
            case RIGHT:
                if (answer[i] == 1) { score += 10; }
                else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
            case UP:
                if (answer[i] == 2) { score += 10; }
                else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
            case DOWN:
                if (answer[i] == 3) { score += 10; }
                else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;
            case SPACE:
                if (answer[i] == 4) { score += 10; }
                else { hcnt++;  gotoxy(h--, 3);  cout << " "; } break;  
        }
        i++;
    }
}




void Stage1(int max) {
    PlaySound(TEXT("pickme.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Record(); //���� �����
    DeleteHeart(); //��Ʈ�� �Ǵ�
    int answer[40] = { 0, }; //��üũ

    x = 25;  y = 10; //�ʱ� ��ġ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1);  cout << "START" << endl;
    gotoxy(4, 2);   cout << "STAGE 1                                                       " << endl;


    for (int j = 0; j < max; j++) {  //���� ����
        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� ����

        if (j < 19) { gotoxy(x--, y);  cout << str[rn]; }
        else  if (j < 21) { gotoxy(x, y++);  cout << str[rn]; }
        else if (j < 50) { gotoxy(x++, y);  cout << str[rn]; }

        //�� ����
        if (j == 39) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            gotoxy(x, y);  cout << "GOAL" << endl;
        }
    }
    Check(1, answer, 40, 25, 10);
 
    system("cls");

}
void Stage2(int max) {
    Record(); //���� �����
    DeleteHeart(); //��Ʈ�� �Ǵ�
    int answer[40] = { 0, }; //��üũ
    x = 5;  y = 5; //�ʱ� ��ġ

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1);  cout << "START" << endl;
    gotoxy(4, 2);   cout << "STAGE 2                                        " << endl; //���۹��� ����


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
void Stage3(int max) {
    Record(); //���� �����
    int answer[50] = { 0, }; //��üũ

    DeleteHeart();
    x = 20;  y = 10; //�ʱ� ��ġ

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1); cout << "START" << endl; //������ġ

    gotoxy(4, 2);   cout << "STAGE 3" << endl;
    for (int j = 0; j < max; j++) {  //���� ����

        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� �� ����

        if (j < 2) { gotoxy(x, y++);  cout << str[rn]; }
        else if (j < 8) { gotoxy(x--, y);  cout << str[rn]; }
        else if (j < 13) { gotoxy(x, y--);  cout << str[rn]; }
        else if (j < 22) { gotoxy(x++, y);  cout << str[rn]; }
        else if (j < 29) { gotoxy(x, y++);  cout << str[rn]; }
        else if (j < 40) { gotoxy(x--, y);  cout << str[rn]; }
        else if (j < 50) { gotoxy(x, y--);  cout << str[rn]; }

    }
    //�� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x--, y--);  cout << "GOAL" << endl;
    Check(3, answer, 50, 20, 10);
    system("cls");
}
void Stage4(int max) {
    Record(); //���� �����
    int answer[55] = { 0, }; //��üũ

    DeleteHeart();
    x = 12;  y = 5; //�ʱ� ��ġ

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 1, y - 1); cout << "START" << endl; //������ġ

    gotoxy(4, 2);   cout << "STAGE 4" << endl;
    for (int j = 0; j < max; j++) {  //���� ����

        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� �� ����

        if (j < 10) { gotoxy(x--, y++);  cout << str[rn]; }
        else if (j < 12) { gotoxy(x++, y);  cout << str[rn]; }
        else if (j < 22) { gotoxy(x++, y--);  cout << str[rn]; }
        else if (j < 24) { gotoxy(x++, y);  cout << str[rn]; }
        else if (j < 34) { gotoxy(x--, y++);  cout << str[rn]; }
        else if (j < 36) { gotoxy(x++, y);  cout << str[rn]; }
        else if (j < 46) { gotoxy(x++, y--);  cout << str[rn]; }
        else if (j < 48) { gotoxy(x++, y);  cout << str[rn]; }
        else if (j < 55) { gotoxy(x++, y++);  cout << str[rn]; }

    }
    //�� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x--, y--);  cout << "GOAL" << endl;
    // �ܰ�/�����Ǵ�����/������/��������ǥ
    Check(4, answer, 55, 12, 5);
    system("cls");
}
void Stage5(int max) {
    Record(); //���� �����
    int answer[60] = { 0, }; //��üũ

    DeleteHeart();
    x = 4;  y = 13; //�ʱ� ��ġ

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x - 3, y); cout << "START" << endl; //������ġ

    gotoxy(4, 2);   cout << "STAGE 5" << endl;
    for (int j = 0; j < max; j++) {  //���� ����

        clrRn = rand() % 6;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr[clrRn]);
        rn = (rand() % 5); //���� ����
        answer[j] = rn; //���� �� ����

        if (j < 8) { gotoxy(x++, y--);  cout << str[rn]; }
        else if (j < 25) { gotoxy(x++, y);  cout << str[rn]; }
        else if (j < 37) { gotoxy(x--, y++);  cout << str[rn]; }

        else if (j < 52) { gotoxy(x--, y);  cout << str[rn]; }
        else if (j < 54) { gotoxy(x, y--);  cout << str[rn]; }
        else if (j < 60) { gotoxy(x++, y);  cout << str[rn]; }



    }
    //�� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    gotoxy(x--, y--);  cout << "GOAL" << endl;
    // �ܰ�/�����Ǵ�����/������/��������ǥ
    Check(5, answer, 60, 4, 13);
    system("cls");
}