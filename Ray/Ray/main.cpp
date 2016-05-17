#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Surface.h"

#ifdef LINUX
#include <time.h>
#include <math.h>
unsigned int get_msec(void) {
    struct timespec spec;
    unsigned int ms;
    time_t s;
    clock_gettime(CLOCK_REALTIME, &spec);
    s = spec.tv_sec;
    ms = round(spec.tv_nsec / 1.0e6);
    ms += s*1000;
    return ms;
}
#else
#include <windows.h>
unsigned int get_msec(void) {
	return (unsigned int)GetTickCount();
}
#endif

using namespace std;

Surface *surface = nullptr;
Pixel *buffer = nullptr;
Engine *tracer = nullptr;

#define SCRWIDTH 800
#define SCRHEIGHT 600

int main()
{
	Pixel white = (Pixel)0xffffffff;
	Pixel black = (Pixel)0xff000000;

	surface = new Surface(SCRWIDTH, SCRHEIGHT);
	buffer = surface->getBuffer();
	surface->clear(black);
	surface->initCharset();
	surface->print("timings:", 2, 2, white);

	tracer = new Engine();
	tracer->getScene().initScene();
	tracer->setTarget(surface->getBuffer(), SCRWIDTH, SCRHEIGHT);
	int tpos = 60;

	// image -> texture -> sprite
	sf::Image image;
	sf::Texture tex;
	sf::Sprite sprite;

	sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "SFML works!");

	tracer->initRender();

	int fstart = get_msec();

	while (!tracer->render()) {}

	int ftime = get_msec() - fstart;
	/* TODO time to string*/
	char t[] = "00:00.000";
	t[6] = (ftime / 100) % 10 + '0';
	t[7] = (ftime / 10) % 10 + '0';
	t[8] = (ftime % 10) + '0';
	int secs = (ftime / 1000) % 60;
	int mins = (ftime / 60000) % 100;
	t[3] = ((secs / 10) % 10) + '0';
	t[4] = (secs % 10) + '0';
	t[1] = (mins % 10) + '0';
	t[0] = ((mins / 10) % 10) + '0';
	surface->print(t, tpos, 2, white);
	tpos += 100;

	image.create(SCRWIDTH, SCRHEIGHT, (sf::Uint8 *)buffer);
	tex.loadFromImage(image);
	sprite.setTexture(tex, true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}
