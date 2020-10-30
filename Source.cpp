#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainFunctions.hpp"
#include <memory>
int main()
{
	std::array<std::unique_ptr<Shape>, 20> shapeArray;
	short int userDecision = 0;
	PrintMenu();
	std::cout << "What do you want? " << std::endl;
	std::cin >> userDecision;
	switch (userDecision)
	{
	case 1:
		AddANewShape(shapeArray);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
		//gergeer
	}
	sf::RenderWindow window(sf::VideoMode(800, 600), "sfml");
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}
		}
		for (auto& shape : shapeArray)
		{
			shape->Draw(window);
		}
		window.display();
	}
	return 0;
}