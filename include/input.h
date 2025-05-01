#pragma once

// Abstração das teclas do teclado.
enum KeyCode
{
	UpArrow = 0x26,
	DownArrow = 0x28,
	LeftArrow = 0x25,
	RightArrow = 0x27,
	Esc = 0x1b,
	Enter = 0x0d
};

const unsigned char keyFlagsSize = 41;

// Flags
char keyDown[keyFlagsSize]{};
char keyUp[keyFlagsSize]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Classe para auxiliar a leitura do teclado e mouse.
class Input
{
private:
	static bool TKeyState(short _ret)
	{
		return (_ret == -127 || _ret == -128);
	}

public:
	// Retorna 'true' quando uma tecla é pressionada.
	static bool KeyDown(KeyCode key)
	{
		if (!keyDown[key] && TKeyState(GetKeyState(key)))
		{
			keyDown[key] = true;
			return true;
		}

		if (!TKeyState(GetKeyState(key)))
			keyDown[key] = false;

		return false;
	}

	// Retorna 'true' quando uma tecla é solta.
	static bool KeyUp(KeyCode key)
	{
		if (!keyUp[key] && !TKeyState(GetKeyState(key)))
		{
			keyUp[key] = true;
			return true;
		}

		if (TKeyState(GetKeyState(key)))
			keyUp[key] = false;

		return false;
	}

};