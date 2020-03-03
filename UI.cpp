#include "Header.h"
void centerstring(char* s)
{
	int l = strlen(s);
	int pos = (int)((250 - l) / 2);
	for (int i = 0; i<pos; i++)
		cout << " ";
	cout << s;
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Console_Window_Set()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 500, TRUE);
	Sleep(1000000000);
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD    result = { 1,1 };
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result = { 1,1 };
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}
void window(int x, int y)
{
	int color = 0;
	textcolor(color + 4);
	int w = 10;
	int h = 2;
	gotoxy(x, y);
	cout << char(201);
	for (int i = 2; i < w * 2 + 20; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	//
	for (int j = 1; j <= h; j++)
	{
		gotoxy(x, y + j);
		cout << char(186);
		for (int i = 1; i <= w * 2 - 2 + 20; i++)
		{
			cout << " ";
		}
		cout << char(186);
	}
	//
	cout << endl;
	gotoxy(x, y + h);
	cout << char(200);
	for (int i = 2; i < w * 2 + 20; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	gotoxy(x + 1, y + 1);
}
void Paint(int x, int y, char *a, int color)
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

