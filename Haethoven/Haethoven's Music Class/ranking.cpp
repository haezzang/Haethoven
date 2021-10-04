#include "haethoven.h"

using namespace std;
//디코딩 폰트 32

//전역변수
extern string name;
string user[100];
int user_score[100];
int cnt = 0;



void Rank_Calc() {

	//데이터 갯수 세기
	ifstream fin;
	fin.open("rank.txt");
	string line; 
	while (!fin.eof()) 
	{
		if (getline(fin, line)) cnt++;
	} 
	cout << "참여자 수:"<<cnt << endl;
	fin.close();


	//파일 읽어오기, 배열에 저장하기
		ifstream f;
		f.open("rank.txt");
		if (f.is_open()) {
			for (int i = 0; i <cnt; i++) {
				f >> user[i];
				f >> user_score[i];
			}
		}
		else {
			cout << "파일을 찾을 수 없습니다!" <<endl;
		}
		f.close();

		//오름차순 정렬하기
		for (int i = 0; i <cnt; i++) {
			for (int j = 0; j < cnt- i; j++) {
				if (user_score[j] < user_score[j + 1]) {
					int temp = user_score[j];
					user_score[j] = user_score[j + 1];
					user_score[j + 1] = temp;
					string temp2 = user[j];
					user[j] = user[j + 1];
					user[j + 1] = temp2;
				}
			}
			
		}
		cnt = 0;

		//순위 print
		int y = 7;
		int num = 1;
		
		//5위까지 출력
		for (int i = 0; i <5; i++) {
			gotoxy(20, y+=2);
			cout <<num++<<"위 "<< user[i] << "  " << user_score[i] << "점" << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		gotoxy(19, 19); cout << "스페이스 눌러 돌아가기" << endl;
}




void Rank() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	gotoxy(13, 2); cout << "______   ___   _   _  _   __ _____  _   _  _____ " << endl;
	gotoxy(13, 3); cout << "| ___ \\ / _ \\ | \\ | || | / /|_   _|| \\ | ||  __ \\ " << endl;
	gotoxy(13, 4); cout << "| |_/ // /_\\ \\|  \\| || |/ /   | |  |  \\| || |  \\/" << endl;
	gotoxy(13, 5); cout << "|    / |  _  || . ` ||    \\   | |  | . ` || | __ " << endl;
	gotoxy(13, 6); cout << "| |\\ \\ | | | || |\\  || |\\  \\ _| |_ | |\\  || |_\\ \\ " << endl;
	gotoxy(13, 7); cout << "\\_| \\_|\\_| |_/\\_| \\_/\\_| \\_/ \\___/ \\_| \\_/ \\____/" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	
	Rank_Calc();
	system("pause>null");
}





