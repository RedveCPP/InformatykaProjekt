#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "MainFunctions.hpp"

int main()
{
	Shape* shapeArray[20]{ nullptr };

	sf::RenderWindow window(sf::VideoMode(800, 600), "IT rocks");
	sf::Event event;

	// it just cant be separated to function with reference because no. fuck you sfml
	sf::Text instructions;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf")) { throw("Couldn't load font"); }
	instructions.setFillColor(sf::Color::Black);
	instructions.setFont(font);
	instructions.setCharacterSize(25);
	instructions.setString("Press 1 to add a new shape\nPress 2 to remove a shape\nPress 3 to exit");
	instructions.setOutlineThickness(2);
	instructions.setOutlineColor(sf::Color::White);

	const sf::Color backgroundColor(46, 46, 46);
	while (window.isOpen())
	{
		window.clear(backgroundColor);
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed) { window.close(); }
			MenuEvents(event, shapeArray);
		}

		for (int i = 0; i < 20; ++i)
		{
			if (shapeArray[i]) { shapeArray[i]->Draw(window); }
		}
		window.draw(instructions);
		window.display();
	}
	FreeMemory(shapeArray);
	return 0;
}