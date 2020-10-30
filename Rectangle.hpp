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

void Rectangle::Draw(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle;
	rectangle.setFillColor(fillColor);
	rectangle.setPosition(Corners[0].x, Corners[0].y);
	rectangle.setSize(sf::Vector2f(Corners[1].x - Corners[0].x, Corners[1].y - Corners[0].y));
	window.draw(rectangle);
}