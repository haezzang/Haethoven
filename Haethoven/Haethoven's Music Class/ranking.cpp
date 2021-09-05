#include "haethoven.h"
using namespace std;
//디코딩 폰트 32





//전역변수
extern string name;


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
	gotoxy(13, 10); cout << "가장 높은 점수를 획득한 순입니다 점수가 같을 경우 누적초가 적은 사람이 순위가 높습니다" << endl;
	system("pause>null");
}