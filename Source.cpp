#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "MainFunctions.hpp"

int main()
{
	Shape* shapeArray[20]{ nullptr };
	sf::RenderWindow window(sf::VideoMode(800, 600), "IT rocks");
	sf::Event event;

	// it cant be separated to function with reference because no. fuck you sfml
	sf::Text instructions;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf")) { throw("Couldn't load font"); }
	instructions.setFillColor(sf::Color::Black);
	instructions.setFont(font);
	instructions.setCharacterSize(25);
	instructions.setString("Press 1 to add a new shape\nPress 2 to remove a shape\nPress 3 to exit");
	instructions.setOutlineThickness(2);
	instructions.setOutlineColor(sf::Color::White);

	while (window.isOpen())
	{
		window.clear(sf::Color(46,46,46));
		while (window.pollEvent(event)) { MenuEvents(event, shapeArray, window); }
		for (int i = 0; i < 20; ++i) { if (shapeArray[i]) { shapeArray[i]->Draw(window); } }
		window.draw(instructions);
		window.display();
	}
	for (int i = 0; i < 20; ++i) { delete shapeArray[i]; }
	return 0;
}