#pragma once

class Console
{
public:
	// Define se o cursor do console do Windows estará visível ou não.
	static void SetCursorVisibility(bool visible)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = visible;
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	// Diz se o cursor do console do Windows está visível ou não.
	static bool IsCursorVisible()
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);

		return cursorInfo.bVisible;
	}

	// Prepara o console do Windows para a aplicação.
	static void Init()
	{
		SetConsoleOutputCP(65001);
		SetCursorVisibility(false);
	}

	// Define a cor do texto do console.
	static void SetTextColor(Color color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color.code);
	}

	static void ClearConsoleSmooth() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos = { 0, 0 };
		SetConsoleCursorPosition(hConsole, cursorPos);
	}
};