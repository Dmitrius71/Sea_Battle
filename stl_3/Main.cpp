#include <iostream>
#include <Windows.h>
#include"Game.h"
#include "HumanPlayer.h"
#include <mmsystem.h>
#include"Board.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");                                // ������� ����
	system("mode con cols=140 lines=65");                    // ��������� ������� �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);       // ��������� ����� �������
	system("color 1F");

	
	Game my;
	my.Init();
	my.Play();
	my.Win();
	my.Print();
   // my.Print_Sea_Board();


	return 0;

	cout << "c";


	return 0;
}