#pragma once

#include "circle.h"

//!This class is used to construct a tire.
class Tire : public Circle
{
public:
	/*!Initializer.*/
	Tire(){};

	/*!Constructor.*/
	/**@param position = Position of the tire.
	@param fRadius = Radius of the tire.
	@param texture = Texture to load.*/
	Tire(sf::Vector2f& position, float fRadius, sf::Texture& texture);
};