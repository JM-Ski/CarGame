#pragma once

#include "rectangle.h"

//!This class is used to create immovable cars.
class StaticCar : public Rectangle
{
public:
	/*!Initializer.*/
	StaticCar(){};

	/*!Constructor.*/
	/**@param position = Position of the rectangle.
	@param dimensions = Size of the rectangle.
	@param texture = Texture to load.
	@param fAngle = An orientation of the car*/
	StaticCar(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Texture& texture, const float fAngle);
};