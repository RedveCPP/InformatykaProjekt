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
	system("cls");
}

void DeleteAShape(Shape** arrayRef)
{
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
	system("cls");
}

void FreeMemory(Shape** shapeArray)
{
	for (int i = 0; i < 20; ++i) { delete shapeArray[i]; }
	delete[]shapeArray;
}

void MenuEvents(sf::Event& event, Shape** shapeArray)
{
	if (event.type == event.KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) { AddANewShape(shapeArray); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) { DeleteAShape(shapeArray); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			FreeMemory(shapeArray);
			std::terminate();
		}
	}
}

//void setinstructions(sf::text& instructions, sf::font font)
//{
//	instructions.setfillcolor(sf::color::black);
//	instructions.setfont(font);
//	instructions.setcharactersize(25);
//	instructions.setstring("press 1 to add a new shape\npress 2 to remove a shape\npress 3 to exit");
//	instructions.setoutlinethickness(2);
//	instructions.setoutlinecolor(sf::color::white);
//}