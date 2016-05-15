#pragma once

#include <SFML/Graphics.hpp>

typedef sf::Uint32 Pixel;

static inline Pixel RGBA_to_Pixel(int red, int green, int blue, int alpha = 255)
{
	return (sf::Uint32)(((alpha & 0xff) << 24) | ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff));
}

unsigned int get_msec(void);