#pragma once
#include "Shape.hpp"

class Rectangle : public virtual Shape
{
private:
	Vec2 Corners[2];
public:
	Rectangle() = default;
	Rectangle(Vec2 point1, Vec2 point2, int index);
	virtual void Draw(sf::RenderWindow& window);
	virtual ~Rectangle() { fillColor = deleteColor; }
};

Rectangle::Rectangle(Vec2 point1, Vec2 point2, int index)
{
	shapeIndex = index;
	Corners[0] = point1;
	Corners[1] = point2;
}

Vec2 GetCenter(Vec2 Corner1, Vec2 Corner2)
{
	if (Corner1.x > Corner2.x)
	{
		std::swap(Corner1.x,Corner2.x);
	}

	if (Corner1.y > Corner2.y)
	{
		std::swap(Corner1.y, Corner2.y);
	}

	int x = (Corner2.x - Corner1.x)/2+Corner1.x;
	int y = (Corner2.y - Corner1.y)/2+Corner1.y;
	return Vec2(x, y);
}

void Rectangle::Draw(sf::RenderWindow& window)
{
	sf::Text number;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf")) { throw("Couldn't load font"); }
	number.setFillColor(sf::Color::Red);
	number.setFont(font);
	number.setCharacterSize(25);
	number.setString(std::to_string(shapeIndex));
	number.setOutlineThickness(2);
	number.setOutlineColor(sf::Color::Black);
	Vec2 center = GetCenter(Corners[0],Corners[1]);
	number.setPosition(center.x, center.y);
	
	sf::RectangleShape rectangle;
	rectangle.setFillColor(fillColor);
	rectangle.setPosition(Corners[0].x, Corners[0].y);
	rectangle.setSize(sf::Vector2f(Corners[1].x - Corners[0].x, Corners[1].y - Corners[0].y));
	window.draw(rectangle);
	window.draw(number);
}