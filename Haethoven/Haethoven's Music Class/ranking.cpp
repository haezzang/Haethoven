#include "haethoven.h"
using namespace std;
//���ڵ� ��Ʈ 32





//��������
extern string name;


void Num() {
	gotoxy(7, 11); cout << " __             _____            _____              ___            _____ " << endl;
	gotoxy(7, 12); cout << "/  |           / __  \\          |____ |            /   |          |  ___|" << endl;
	gotoxy(7, 13); cout << "`| |           `' / /'              / /           / /| |          |___ \\ " << endl;
	gotoxy(7, 14); cout << " | |             / /                \\ \\          / /_| |              \\ \\ " << endl;
	gotoxy(7, 15); cout << "_| |_          ./ /___          .___/ /          \\___  |          /\\__/ /" << endl;
	gotoxy(7, 16); cout << "\\___/          \\_____/          \\____/               |_/          \\____/ " << endl;

	gotoxy(6, 18); cout << "����������" << endl;
	gotoxy(6, 19); cout << "1500��" << endl;

}

void Rank() {
	system("cls");
	Num();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	gotoxy(13, 2); cout << "______   ___   _   _  _   __ _____  _   _  _____ " << endl;
	gotoxy(13, 3); cout << "| ___ \\ / _ \\ | \\ | || | / /|_   _|| \\ | ||  __ \\ " << endl;
	gotoxy(13, 4); cout << "| |_/ // /_\\ \\|  \\| || |/ /   | |  |  \\| || |  \\/" << endl;
	gotoxy(13, 5); cout << "|    / |  _  || . ` ||    \\   | |  | . ` || | __ " << endl;
	gotoxy(13, 6); cout << "| |\\ \\ | | | || |\\  || |\\  \\ _| |_ | |\\  || |_\\ \\ " << endl;
	gotoxy(13, 7); cout << "\\_| \\_|\\_| |_/\\_| \\_/\\_| \\_/ \\___/ \\_| \\_/ \\____/" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	gotoxy(13, 9); cout << "������ ��� �����ð��� ���� ������ ������ �����ϴ�" << endl;
	system("pause>null");
}

