#include <iostream>
#include <conio.h>
#include <locale.h>
#include "fstream"
#include <windows.h>
#include <string>


using namespace std;

DWORD WINAPI GameThread(void *arg);
DWORD WINAPI GameThread2(void *arg);
void getNewLifeField();
void LoadField();
void Exit();

int life[20][20], nextlife[20][20];

HANDLE hConsole, hStdin;
COORD coord, mouseCoord;

DWORD thr, thr2, NumRead, fdwMode;
HANDLE hThread, hThread2;


char *menu[7] = 
	{ "* Фигуры:    *",
	  "* Квадрат    *",
	  "* Восьмерка  *",
	  "* Пульсар    *",
	  "* Светофоры  *",
	  "* Улей       *",
	  "* Флип-флопы *"
	};

///Процесс
STARTUPINFO si;
PROCESS_INFORMATION pi;

LPWSTR STR, STR2;

int main() {
	setlocale(.1251, "rus");
	//Для процесса
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	
	///Для мыши
	INPUT_RECORD ir;
	coord.X = 0;
	coord.Y = 0;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE), hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//hThread = CreateThread(NULL, 0, GameThread,NULL, CREATE_SUSPENDED, &thr);
	
	
	
	coord.Y = 0;
		for(int i = 0; i < 7; i++) {
			SetConsoleTextAttribute(hConsole,0x0f);
		SetConsoleCursorPosition(hConsole, coord);
		printf("%s", menu[i]);
		coord.Y += 1;
		}
		

	while(true) {
		
	if(!ReadConsoleInput(hStdin, &ir, 1, &NumRead))
		{
			cout << "Error!!!" << endl;
			
		}
	 
	//Для выбора фигуры
	if(ir.EventType == MOUSE_EVENT && ir.Event.MouseEvent.dwMousePosition.X >= 1 && ir.Event.MouseEvent.dwMousePosition.X <= 15) {
		if(ir.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK){
			switch(ir.Event.MouseEvent.dwMousePosition.Y) {
		case 1: 
			hThread2 = CreateThread(NULL, 0, GameThread2,NULL, CREATE_SUSPENDED, &thr2);
			STR = L"GameOfLife_Normal.exe 1 1";
			STR2 = L"GameOfLife_Normal.exe 1 2";
			ResumeThread(hThread2);
			break;
		case 2:
			hThread2 = CreateThread(NULL, 0, GameThread2,NULL, CREATE_SUSPENDED, &thr2);
			STR = L"GameOfLife_Normal.exe 2 1";
			STR2 = L"GameOfLife_Normal.exe 2 2";
			ResumeThread(hThread2);
			break;
		case 3:
			hThread2 = CreateThread(NULL, 0, GameThread2,NULL, CREATE_SUSPENDED, &thr2);
			STR = L"GameOfLife_Normal.exe 3 1";
			STR2 = L"GameOfLife_Normal.exe 3 2";
			ResumeThread(hThread2);
			break;
		case 4:
			hThread2 = CreateThread(NULL, 0, GameThread2,NULL, CREATE_SUSPENDED, &thr2);
			STR = L"GameOfLife_Normal.exe 4 1";
			STR2 = L"GameOfLife_Normal.exe 4 2";
			ResumeThread(hThread2);
			break;
		case 5:
			hThread2 = CreateThread(NULL, 0, GameThread2,NULL, CREATE_SUSPENDED, &thr2);
			STR = L"GameOfLife_Normal.exe 5 1";
			STR2 = L"GameOfLife_Normal.exe 5 2";
			ResumeThread(hThread2);
			break;
		case 6:
			hThread2 = CreateThread(NULL, 0, GameThread2,NULL, CREATE_SUSPENDED, &thr2);
			STR = L"GameOfLife_Normal.exe 6 1";
			STR2 = L"GameOfLife_Normal.exe 6 2";
			ResumeThread(hThread2);
			break;
			}
		}
	}
	
	}
	getch();
return 0;
}


DWORD WINAPI GameThread2(void *arg) {
	
	if(!CreateProcess(L"C:\\Users\\Тимофей\\Documents\\Visual Studio 2010\\Projects\\Задания из книги\\4 семестр\\Курсовая работа (исходники)\\GameOfLife_Normal\\Debug\\GameOfLife_Normal.exe", STR,
		NULL, NULL, FALSE, CREATE_NEW_CONSOLE|NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi)) {
		cout << "Ошибка в создании процесса!!! " << GetLastError();
	return 0;
	}
	if(!CreateProcess(L"C:\\Users\\Тимофей\\Documents\\Visual Studio 2010\\Projects\\Задания из книги\\4 семестр\\Курсовая работа (исходники)\\GameOfLife_Normal\\Debug\\GameOfLife_Normal.exe", STR2,
		NULL, NULL, FALSE, CREATE_NEW_CONSOLE|NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi)) {
		cout << "Ошибка в создании процесса!!! " << GetLastError();
	return 0;
	}
}




void Exit() {
	SuspendThread(hThread);
	CloseHandle(hConsole);
	CloseHandle(hStdin);
	CloseHandle(hThread);
	ExitProcess(0);
}