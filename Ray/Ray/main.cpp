#include <iostream>
#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Surface.h"

using namespace std;

Surface *surface = nullptr;
Pixel *buffer = nullptr;
Engine *tracer = nullptr;

#define SCRWIDTH 800
#define SCRHEIGHT 600

int main()
{
	surface = new Surface(SCRWIDTH, SCRHEIGHT);
	buffer = surface->getBuffer();
	surface->clear(0);
	surface->initCharset();
	surface->print("timings:", 2, 2, 0xffffffff);

	tracer = new Engine();
	tracer->getScene().initScene();
	tracer->setTarget(surface->getBuffer(), SCRWIDTH, SCRHEIGHT);
	int tpos = 60;

	tracer->initRender();
	tracer->render();

	// image -> texture -> sprite
	sf::Image image;
	image.create(SCRWIDTH, SCRHEIGHT, (sf::Uint8 *)buffer);

	sf::Texture tex;
	tex.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(tex, true);
	
	sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "SFML works!");
	
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