// ----------------------------------------------------------------
// surface.cpp
// Original author:
//     2004 - Jacco Bikker - jacco@bik5.com - www.bik5.com -   <><
// Modified by:
//     2016 - Vincent Siles - vincent.siles@gmail.com
// ----------------------------------------------------------------
#include <locale>
#include "Surface.h"

Surface::Surface(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;

	buffer = new Pixel[width*height];
}

Surface::~Surface()
{
	delete[] buffer;
}

void Surface::clear(Pixel color)
{
	int s = width * height;
	for (int i = 0; i < s; i++)
		buffer[i] = color;
}

void Surface::print(std::string str, unsigned int x1, unsigned int y1, Pixel color)
{
	Pixel *t = buffer + x1 + y1 * width;
	size_t i;
	for (i = 0; i < str.length(); i++)
	{
		int pos = 0;
		if (isalpha(str[i]))
			pos = transl[tolower(str[i])];
		Pixel *a = t;
		char *c = (char *)font[pos];
		unsigned int h, v;
		for (v = 0; v < 5; v++)
		{
			for (h = 0; h < 5; h++)
				if (*c++ == 'o') 
					*(a + h) = color;
			a += width;
		}
		t += 6;
	}
}

void Surface::setChar(int c, char *c1, char *c2, char *c3, char *c4, char *c5)
{
	strcpy_s(font[c][0], 5, c1);
	strcpy_s(font[c][1], 5, c2);
	strcpy_s(font[c][2], 5, c3);
	strcpy_s(font[c][3], 5, c4);
	strcpy_s(font[c][4], 5, c5);
}

void Surface::initCharset()
{
	setChar(0, ":ooo:", "o:::o", "ooooo", "o:::o", "o:::o");
	setChar(1, "oooo:", "o:::o", "oooo:", "o:::o", "oooo:");
	setChar(2, ":oooo", "o::::", "o::::", "o::::", ":oooo");
	setChar(3, "oooo:", "o:::o", "o:::o", "o:::o", "oooo:");
	setChar(4, "ooooo", "o::::", "oooo:", "o::::", "ooooo");
	setChar(5, "ooooo", "o::::", "ooo::", "o::::", "o::::");
	setChar(6, ":oooo", "o::::", "o:ooo", "o:::o", ":ooo:");
	setChar(7, "o:::o", "o:::o", "ooooo", "o:::o", "o:::o");
	setChar(8, "::o::", "::o::", "::o::", "::o::", "::o::");
	setChar(9, ":::o:", ":::o:", ":::o:", ":::o:", "ooo::");
	setChar(10, "o::o:", "o:o::", "oo:::", "o:o::", "o::o:");
	setChar(11, "o::::", "o::::", "o::::", "o::::", "ooooo");
	setChar(12, "oo:o:", "o:o:o", "o:o:o", "o:::o", "o:::o");
	setChar(13, "o:::o", "oo::o", "o:o:o", "o::oo", "o:::o");
	setChar(14, ":ooo:", "o:::o", "o:::o", "o:::o", ":ooo:");
	setChar(15, "oooo:", "o:::o", "oooo:", "o::::", "o::::");
	setChar(16, ":ooo:", "o:::o", "o:::o", "o::oo", ":oooo");
	setChar(17, "oooo:", "o:::o", "oooo:", "o:o::", "o::o:");
	setChar(18, ":oooo", "o::::", ":ooo:", "::::o", "oooo:");
	setChar(19, "ooooo", "::o::", "::o::", "::o::", "::o::");
	setChar(20, "o:::o", "o:::o", "o:::o", "o:::o", ":oooo");
	setChar(21, "o:::o", "o:::o", ":o:o:", ":o:o:", "::o::");
	setChar(22, "o:::o", "o:::o", "o:o:o", "o:o:o", ":o:o:");
	setChar(23, "o:::o", ":o:o:", "::o::", ":o:o:", "o:::o");
	setChar(24, "o:::o", "o:::o", ":oooo", "::::o", ":ooo:");
	setChar(25, "ooooo", ":::o:", "::o::", ":o:::", "ooooo");
	setChar(26, ":ooo:", "o::oo", "o:o:o", "oo::o", ":ooo:");
	setChar(27, "::o::", ":oo::", "::o::", "::o::", ":ooo:");
	setChar(28, ":ooo:", "o:::o", "::oo:", ":o:::", "ooooo");
	setChar(29, "oooo:", "::::o", "::oo:", "::::o", "oooo:");
	setChar(30, "o::::", "o::o:", "ooooo", ":::o:", ":::o:");
	setChar(31, "ooooo", "o::::", "oooo:", "::::o", "oooo:");
	setChar(32, ":oooo", "o::::", "oooo:", "o:::o", ":ooo:");
	setChar(33, "ooooo", "::::o", ":::o:", "::o::", "::o::");
	setChar(34, ":ooo:", "o:::o", ":ooo:", "o:::o", ":ooo:");
	setChar(35, ":ooo:", "o:::o", ":oooo", "::::o", ":ooo:");
	setChar(36, "::o::", "::o::", "::o::", ":::::", "::o::");
	setChar(37, ":ooo:", "::::o", ":::o:", ":::::", "::o::");
	setChar(38, ":::::", ":::::", "::o::", ":::::", "::o::");
	setChar(39, ":::::", ":::::", ":ooo:", ":::::", ":ooo:");
	setChar(40, ":::::", ":::::", ":::::", ":::o:", "::o::");
	setChar(41, ":::::", ":::::", ":::::", ":::::", "::o::");
	setChar(42, ":::::", ":::::", ":ooo:", ":::::", ":::::");
	setChar(43, ":::o:", "::o::", "::o::", "::o::", ":::o:");
	setChar(44, "::o::", ":::o:", ":::o:", ":::o:", "::o::");
	setChar(45, ":::::", ":::::", ":::::", ":::::", ":::::");
	setChar(46, "ooooo", "ooooo", "ooooo", "ooooo", "ooooo");
	setChar(47, "::o::", "::o::", ":::::", ":::::", ":::::");
	setChar(48, "o:o:o", ":ooo:", "ooooo", ":ooo:", "o:o:o");
	setChar(49, "::::o", ":::o:", "::o::", ":o:::", "o::::");
	char c[] = "abcdefghijklmnopqrstuvwxyz0123456789!?:=,.-() #'*/";
	int i;
	for (i = 0; i < 256; i++)
		transl[i] = 45;
	for (i = 0; i < 50; i++)
		transl[c[i]] = i;
}

Pixel *Surface::getBuffer()
{
	return buffer;
}

unsigned int Surface::getWidth()
{
	return width;
}

unsigned int Surface::getHeight()
{
	return height;
}