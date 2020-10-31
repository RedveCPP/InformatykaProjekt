#pragma once
#include "Shape.hpp"

Vec2 GetCenterOfTriangle(std::array<Vec2, 3>& vecArray);

#include <array>
class Triangle :public virtual Shape
{
private:
	std::array<Vec2, 3> triangleVectors;
	Vec2 center;
public:
	Triangle() = default;
	Triangle(const std::array<Vec2, 3>& vecArray, int index);
	virtual void Draw(sf::RenderWindow& window);
	~Triangle() { fillColor = deleteColor; }
};

Triangle::Triangle(const std::array<Vec2, 3>& vecArray, int index)
{
	shapeIndex = index;
	for (int i = 0; i < 3; ++i) { triangleVectors[i] = vecArray[i]; }
	center = GetCenterOfTriangle(triangleVectors);
}

#include <string>
void Triangle::Draw(sf::RenderWindow& window)
{
	sf::Vertex Line1[]{
		sf::Vertex(sf::Vector2f(triangleVectors[0].x,triangleVectors[0].y),fillColor),
		sf::Vertex(sf::Vector2f(triangleVectors[1].x,triangleVectors[1].y),fillColor),
	};
	sf::Vertex Line2[]{
		sf::Vertex(sf::Vector2f(triangleVectors[1].x,triangleVectors[1].y),fillColor),
		sf::Vertex(sf::Vector2f(triangleVectors[2].x,triangleVectors[2].y),fillColor),
	};
	sf::Vertex Line3[]{
		sf::Vertex(sf::Vector2f(triangleVectors[2].x,triangleVectors[2].y),fillColor),
		sf::Vertex(sf::Vector2f(triangleVectors[0].x,triangleVectors[0].y),fillColor),
	};
	window.draw(Line1, 2, sf::Lines);
	window.draw(Line2, 2, sf::Lines);
	window.draw(Line3, 2, sf::Lines);

	// it cant be separated to function with reference because no. fuck you sfml
	sf::Text number;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf")) { throw("Couldn't load font"); }
	number.setFillColor(sf::Color::Red);
	number.setFont(font);
	number.setCharacterSize(25);
	number.setString(std::to_string(shapeIndex));
	number.setOutlineThickness(2);
	number.setOutlineColor(sf::Color::White);
	number.setPosition(center.x-12, center.y-12);
	window.draw(number);
}

#include <cmath>
Vec2 GetCenterOfTriangle(std::array<Vec2, 3>& vecArray)
{
	int x=(vecArray[0].x+vecArray[1].x+vecArray[2].x)/3;
	int y=(vecArray[0].y+vecArray[1].y+vecArray[2].y)/3;
	return Vec2(x, y);
}