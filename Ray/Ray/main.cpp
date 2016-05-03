#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector3.h"

using namespace std;

#if 1
int main(int argc, char **argv)
{
	(void)argc; /* UNUSED */
	(void)argv; /* UNUSED */

	cout << "HelloWorld !" << endl;

	Vector3 v;

	cout << "First vector: " << v << endl;

	Vector3 w(1.0, 2.0, 3.0);

	cout << "Second vector: " << w + v << endl;

	return 0;
}
#else
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
#endif