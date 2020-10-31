#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Shape.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

int GetFirstFreeField(Shape** arrayRef)
{
	for (int i = 0; i < 20; ++i)
	{
		if (arrayRef[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}


void AddANewShape(Shape** arrayRef)
{
	system("cls");
	short int userDecision = 0;
	std::cout << "Which shape do you want to add?" << std::endl <<
		"1. Triangle" << std::endl <<
		"2. Circle" << std::endl <<
		"3. Rectangle" << std::endl;
	std::cin >> userDecision;
	switch (userDecision)
	{
	case 1:
	{
		int freeShapeIndex = GetFirstFreeField(arrayRef);
		if (freeShapeIndex >= 0 && freeShapeIndex <= 19)
		{
			int x[3];
			int y[3];
			std::cout << "Enter 3 triangle corner vectors (X Y X Y X Y) for ex. 500 40 120 50 1 1" << std::endl;
			std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
			arrayRef[freeShapeIndex] = new Triangle(std::array<Vec2, 3>{Vec2(x[0], y[0]), Vec2(x[1], y[1]), Vec2(x[2], y[2])}, freeShapeIndex);

		}
		else
		{
			std::cout << "There is no space for shape" << std::endl;
		}
	}
	break;
	case 2:
	{
		int freeShapeIndex = GetFirstFreeField(arrayRef);
		if (freeShapeIndex >= 0 && freeShapeIndex <= 19)
		{
			int x, y, radius;
			std::cout << "Enter X, Y and radius. for ex 400 300 5" << std::endl;
			std::cin >> x >> y >> radius;
			arrayRef[freeShapeIndex] = new Circle(Vec2(x, y), radius, freeShapeIndex);
		}
		else
		{
			std::cout << "There is no space for shape" << std::endl;
		}
	}
	break;
	case 3:
	{
		int freeShapeIndex = GetFirstFreeField(arrayRef);
		if (freeShapeIndex >= 0 && freeShapeIndex <= 19)
		{
			int x[2];
			int y[2];
			std::cout << "Enter 2 points (x,y) that will be corners. for ex 400 300 5 15" << std::endl;
			std::cin >> x[0] >> y[0] >> x[1] >> y[1];
			arrayRef[freeShapeIndex] = new Rectangle(Vec2(x[0], y[0]), Vec2(x[1], y[1]), freeShapeIndex);
		}
		else
		{
			std::cout << "There is no space for shape" << std::endl;
		}
	}
	break;
	default:
		break;
	}
}

void DeleteAShape(Shape** arrayRef)
{
	system("cls");
	short int index = 0;
	std::cout << "Which shape do you want remove?" << std::endl;
	std::cin >> index;
	if (index >= 0 && index <= 19)
	{
		if (arrayRef[index])
		{
			delete arrayRef[index];
			arrayRef[index] = nullptr;
		}
		else
		{
			std::cout << "its already eapty";
		}
	}
}

#include <SFML/Audio.hpp>
#include <chrono>
#include <random>
#include <ctime>
void EasterEgg(sf::RenderWindow& window, sf::Event& event)
{
	sf::Text instructions;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf")) { throw("Couldn't load font"); }
	instructions.setFillColor(sf::Color::Black);
	instructions.setFont(font);
	instructions.setCharacterSize(25);
	instructions.setString("Press N to break");
	instructions.setOutlineThickness(2);
	instructions.setOutlineColor(sf::Color::White);
	instructions.setPosition(10, 10);

	sf::Music music;
	if (!music.openFromFile("music.ogg"))	// 31s
	{
		std::cerr << "Error with loading music file" << std::endl;
		return;
	}
	system("cls");
	music.setVolume(70);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;
	music.play();
	sf::Sprite graph;
	sf::Texture graphText;
	if (!graphText.loadFromFile("wykres.png"))
	{
	}
	else
	{
		graph.setTexture(graphText);
		graph.setPosition(100, 100);
		graph.setScale(sf::Vector2f(1.3,1.3));
	}
	while (std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() <= 31)
	{
		end = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() >= 6500)
		{
			static int seed = 0;
			seed++;
			std::mt19937 engine;
			std::uniform_int_distribution<int> distributor(-7, 7);
			engine.seed(seed);
			int x = distributor(engine);
			int y = distributor(engine);
			graph.setPosition(100 + x, 100 + y);
			sf::Color recColor = sf::Color(255, 0,0);
			window.clear(recColor);
			window.draw(instructions);
			window.draw(graph);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			break;
		}
		while (window.pollEvent(event))
		{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
				{
					break;
				}
		};
		
		window.display();
	}

}

void MenuEvents(sf::Event& event, Shape** shapeArray, sf::RenderWindow& window, sf::Text& text)
{
	if (event.type == event.Closed) { window.close(); }
	if (event.type == event.KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) { AddANewShape(shapeArray); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) { DeleteAShape(shapeArray); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) { window.close(); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { EasterEgg(window, event); }
	}
	text.setString("Press 1 to add a new shape\nPress 2 to remove a shape\nPress 3 to exit\nPress M to ?");
}