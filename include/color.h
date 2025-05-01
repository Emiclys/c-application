#pragma once

struct Color
{
	unsigned short code;

	static unsigned short white;
	static unsigned short gray;

	Color() : code(0) {};
	Color(unsigned short c) : code(c) {};
};

unsigned short Color::white = 15;
unsigned short Color::gray = 8;