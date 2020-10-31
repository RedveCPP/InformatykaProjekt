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
	sf::Text number;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf")) { throw("Couldn't load font"); }
	number.setFillColor(sf::Color::Red);
	number.setFont(font);
	number.setCharacterSize(25);
	number.setString(std::to_string(shapeIndex));
	number.setOutlineThickness(2);
	number.setOutlineColor(sf::Color::Black);
	number.setPosition(_position.x+_radius-12, _position.y+ _radius-12);
	
	sf::CircleShape circle(_radius);
	circle.setFillColor(fillColor);
	circle.setPosition(_position.x, _position.y);
	window.draw(circle);
	window.draw(number);
}