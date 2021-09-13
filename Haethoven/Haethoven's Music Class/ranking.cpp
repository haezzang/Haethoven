#include "haethoven.h"
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
//디코딩 폰트 32

//전역변수
extern string name;
string user[100];
int user_score[100];
int cnt = 0;



void Rank() {
	//게임이 끝나면 점수를 저장 >성공
	//파일 입력하기 >랭킹 들어갈때마다 데이터가 추가됌 고칠것
	//게임유저만큼 반복문 돌려 순위 구하기 >유저이름만 하면 끝
	//5위까지만 파일 출력하기 >성공
	

	
	//데이터 갯수 세기
	ifstream fin;
	fin.open("rank.txt");
	string line; 
	while (!fin.eof()) 
	{
		if (getline(fin, line)) cnt++;
	} 
	cout << "데이터 갯수 : " << cnt << endl;
	fin.close();


	//파일 읽어오기, 배열에 저장하기
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
			cout << "파일을 찾을 수 없습니다!" <<endl;
		}
		f.close();

		//오름차순 정렬하기
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

		//순위 print
		int y = 8;
		int num = 1;
		
		for (int i = 0; i <5; i++) {
			gotoxy(22, y+=2);
			cout <<num++<<"위 "<< user[i] << "  " << user_score[i] << "점" << endl;
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





