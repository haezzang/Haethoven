#include "haethoven.h"
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
//���ڵ� ��Ʈ 32

//��������
extern string name;
string user[100];
int user_score[100];
int cnt = 0;



void Rank() {
	//������ ������ ������ ���� >����
	//���� �Է��ϱ� >��ŷ �������� �����Ͱ� �߰��� ��ĥ��
	//����������ŭ �ݺ��� ���� ���� ���ϱ� >�����̸��� �ϸ� ��
	//5�������� ���� ����ϱ� >����
	

	
	//������ ���� ����
	ifstream fin;
	fin.open("rank.txt");
	string line; 
	while (!fin.eof()) 
	{
		if (getline(fin, line)) cnt++;
	} 
	cout << "������ ���� : " << cnt << endl;
	fin.close();


	//���� �о����, �迭�� �����ϱ�
		ifstream f;
		f.open("rank.txt");
		if (f.is_open()) {
			for (int i = 0; i <cnt-1; i++) {
				f >> user[i];
				f >> user_score[i];
			cout << user[i] << user_score[i] << endl;
			}
		}
		else {
			cout << "������ ã�� �� �����ϴ�!" <<endl;
		}
		f.close();

		//�������� �����ϱ�
		int key;
		for (int i = 0; i <cnt-1; i++) {
			for (int j = 0; j < cnt-1- i; j++) {
				if (user_score[j] < user_score[j + 1]) {
					int temp = user_score[j];
					user_score[j] = user_score[j + 1];
					user_score[j + 1] = temp;
					key = j + 1;
					user[key];
				}
			}
		}

		//���� print
		int y = 8;
		int num = 1;
		
		for (int i = 0; i <5; i++) {
			gotoxy(22, y+=2);
			cout <<num++<<"�� "<< user[i] << "  " << user_score[i] << "��" << endl;
		}
}




void PrintRankTitle() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	gotoxy(13, 2); cout << "______   ___   _   _  _   __ _____  _   _  _____ " << endl;
	gotoxy(13, 3); cout << "| ___ \\ / _ \\ | \\ | || | / /|_   _|| \\ | ||  __ \\ " << endl;
	gotoxy(13, 4); cout << "| |_/ // /_\\ \\|  \\| || |/ /   | |  |  \\| || |  \\/" << endl;
	gotoxy(13, 5); cout << "|    / |  _  || . ` ||    \\   | |  | . ` || | __ " << endl;
	gotoxy(13, 6); cout << "| |\\ \\ | | | || |\\  || |\\  \\ _| |_ | |\\  || |_\\ \\ " << endl;
	gotoxy(13, 7); cout << "\\_| \\_|\\_| |_/\\_| \\_/\\_| \\_/ \\___/ \\_| \\_/ \\____/" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	Rank();
	system("pause>null");
}





