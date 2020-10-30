#pragma once
#include <SFML/Graphics.hpp>

struct Vec2
{
	int x, y;
	Vec2(int _x=0, int _y=0)
	{
		x = _x;
		y = _y;
	}
};

class Shape
{
protected:
	bool isEapty;
public:
	bool isEaptyRef = false;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
private:
	Vec2 _position;
	int _radius;
public:
	Circle(const Vec2& position, int radius) :_position{ position }, _radius{ radius }{isEapty = false; }
	virtual void Draw(sf::RenderWindow& window)
	{
		if (!isEapty)
		{
			sf::CircleShape circle(_radius);
			circle.setPosition(_position.x, _position.y);
			window.draw(circle);
		}
	}
	virtual ~Circle() { isEapty = true; }
};

#include <array>
class Triangle :public Shape
{
private:
	std::array<Vec2, 3> triangleVectors;
public:
	Triangle(const std::array<Vec2, 3>& vecArray)
	{
		isEapty = false;
		int i = 0;
		for (auto& element : triangleVectors)
		{
			element = vecArray[i];
			i++;
		}
	}
	~Triangle() { isEapty = true; }
	virtual void Draw(sf::RenderWindow& window)
	{
		if (!isEapty)
		{
			sf::Vertex Line1[]{
				sf::Vertex(sf::Vector2f(triangleVectors[0].x,triangleVectors[0].y)),
				sf::Vertex(sf::Vector2f(triangleVectors[1].x,triangleVectors[1].y)),
			};
			sf::Vertex Line2[]{
				sf::Vertex(sf::Vector2f(triangleVectors[1].x,triangleVectors[1].y)),
				sf::Vertex(sf::Vector2f(triangleVectors[2].x,triangleVectors[2].y)),
			};
			sf::Vertex Line3[]{
				sf::Vertex(sf::Vector2f(triangleVectors[2].x,triangleVectors[2].y)),
				sf::Vertex(sf::Vector2f(triangleVectors[0].x,triangleVectors[0].y)),
			};
			window.draw(Line1, 2, sf::Lines);
			window.draw(Line2, 2, sf::Lines);
			window.draw(Line3, 2, sf::Lines);
		}
	}
};

void PrintMenu()
{
	std::cout << "1. Add a new shape" << std::endl;
	std::cout << "2. Remove a shape" << std::endl;
	std::cout << "3. Exit" << std::endl;
}

int GetFirstFreeShape(std::array<std::unique_ptr<Shape>, 20>& arrayRef)
{
	std::cout << arrayRef[1].get()->isEaptyRef;
	return -1;
}

void AddANewShape(std::array<std::unique_ptr<Shape>, 20>& arrayRef)
{
	short int userDecision = 0;
	std::cout << "Which shape do you want to add?" <<std::endl<<
		"1. Triangle" << std::endl <<
		"2. Circle" << std::endl <<
		"3. Rectangle" << std::endl;
	std::cin >> userDecision;
	switch (userDecision)
	{
	case 1:
	{
		int freeShapeIndex = 15;// GetFirstFreeShape(arrayRef);
		if (freeShapeIndex >= 0 && freeShapeIndex <= 19)
		{
			int x[3];
			int y[3];
			std::cout << "Enter 3 triangle corner vectors (X Y X Y X Y) for ex. 500 40 120 50 1 1" << std::endl;
			std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
			arrayRef[5] = std::make_unique<Triangle>(std::array<Vec2, 3>{Vec2(x[0], y[0]), Vec2(x[1], y[1]), Vec2(x[2], y[2])});
		}
		else
		{
			std::cout << "There is no space for shape" << std::endl;
		}
	}
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}