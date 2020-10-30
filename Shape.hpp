#pragma once
#include <SFML/Graphics.hpp>
struct Vec2
{
	int x, y;
	Vec2(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
};

class Shape
{
protected:
	int shapeIndex{};
	const sf::Color deleteColor{ 46,46,46 };
	const sf::Color createColor{ sf::Color::White };
	sf::Color fillColor{ createColor };
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual ~Shape() {}
};
