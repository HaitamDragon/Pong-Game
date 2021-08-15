#pragma once
#include <SFML/Graphics.hpp>

class MovingShapes
{
public:

	int speed;
	int width, height;

	MovingShapes(sf::CircleShape &shape, int _speed, float radius, bool movingForwardAndBack = true);
	MovingShapes(sf::RectangleShape& shape, int _speed, int _width, int _height);
	MovingShapes(sf::ConvexShape& shape, int _speed, int _width, int _height);


	void Update(sf::Shape &shape);


};

