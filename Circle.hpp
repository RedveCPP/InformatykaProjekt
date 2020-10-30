#pragma once
#include "Shape.hpp"

class Circle : public virtual Shape
{
private:
	Vec2 _position;
	int _radius;
public:
	Circle() = default;
	Circle(const Vec2& position, int radius, int index) :_position{ position }, _radius{ radius }{shapeIndex = index; }
	virtual void Draw(sf::RenderWindow& window);
	virtual ~Circle() { fillColor = deleteColor; }
};

void Circle::Draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(_radius);
	circle.setFillColor(fillColor);
	circle.setPosition(_position.x, _position.y);
	window.draw(circle);
}