#include "MovingShapes.h"

MovingShapes::MovingShapes(sf::CircleShape& shape, int _speed, float radius, bool movingFowardAndBack){
	shape.setRadius(radius + speed);
}

/*
void MovingShapes::Update(sf::Shape &shape)
{

}
*/