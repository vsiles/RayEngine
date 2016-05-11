// ----------------------------------------------------------------
// surface.cpp
// Original author:
//     2004 - Jacco Bikker - jacco@bik5.com - www.bik5.com -   <><
// Modified by:
//     2016 - Vincent Siles - vincent.siles@gmail.com
// ----------------------------------------------------------------

#pragma once
#include <string>
#include "common.h"

class Surface
{
public:
	// constructor / destructors
	Surface(unsigned int width, unsigned int height);
	virtual ~Surface();

	// member data access
	Pixel *getBuffer();
	unsigned int getWidth();
	unsigned int getHeight();

	// Special operations
	void initCharset();
	void print(std::string str, unsigned int x1, unsigned int y1, Pixel color);
	void clear(Pixel color);

private:
	// Attributes
	Pixel *buffer;
	unsigned int width, height;

	// Static attributes for the buildin font
	char font[51][5][5];
	int transl[256];

	void setChar(int c, char *c1, char *c2, char *c3, char *c4, char *c5);
};

