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
}


// get center of triangle 
// https://www.geeksforgeeks.org/equation-of-circle-when-three-points-on-the-circle-are-given/#:~:text=Equation%20of%20circle%20in%20general,and%20r%20is%20the%20radius.&text=Radius%20%3D%201-,The%20equation%20of%20the%20circle,2%20%2B%20y2%20%3D%201.
#include <cmath>
Vec2 GetCenterOfTriangle(std::array<Vec2, 3>& vecArray)
{
	// replace variables with mine
	int& x1 = vecArray[0].x;
	int& x2 = vecArray[1].x;
	int& x3 = vecArray[2].x;
	int& y1 = vecArray[0].y;
	int& y2 = vecArray[1].y;
	int& y3 = vecArray[2].y;

	int x12 = vecArray[0].x - x2;
	int x13 = x1 - x3;

	int y12 = y1 - y2;
	int y13 = y1 - y3;

	int y31 = y3 - y1;
	int y21 = y2 - y1;

	int x31 = x3 - x1;
	int x21 = x2 - x1;

	// x1^2 - x3^2 
	int sx13 = pow(x1, 2) - pow(x3, 2);

	// y1^2 - y3^2 
	int sy13 = pow(y1, 2) - pow(y3, 2);

	int sx21 = pow(x2, 2) - pow(x1, 2);
	int sy21 = pow(y2, 2) - pow(y1, 2);

	int f = ((sx13) * (x12)
		+(sy13) * (x12)
		+(sx21) * (x13)
		+(sy21) * (x13))
		/ (2 * ((y31) * (x12)-(y21) * (x13)));
	int g = ((sx13) * (y12)
		+(sy13) * (y12)
		+(sx21) * (y13)
		+(sy21) * (y13))
		/ (2 * ((x31) * (y12)-(x21) * (y13)));

	int c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;

	// eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0 
	// where centre is (h = -g, k = -f) and radius r 
	// as r^2 = h^2 + k^2 - c 
	int h = -g;
	int k = -f;
	int sqr_of_r = h * h + k * k - c;

	// r is the radius 
	float r = sqrt(sqr_of_r);
	return Vec2(h, k);
}