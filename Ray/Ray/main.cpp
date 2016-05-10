#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace std;

static Scene scene;

static void dummy(std::vector<std::unique_ptr<Primitive>> &prims, size_t n)
{
	unsigned int i;

	for (i = 0; i < n; i++) {
		Primitive &curr = *scene.getPrimitive(i);
		cout << "Current primitive is " << curr.getName() << endl;
	}
}

#if 1
int main(int argc, char **argv)
{
	(void)argc; /* UNUSED */
	(void)argv; /* UNUSED */

	cout << "HelloWorld !" << endl;
	
	scene.initScene();

	cout << "Good Bye World !" << endl;

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