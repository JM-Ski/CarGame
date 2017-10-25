#pragma once

#include "rectangle.h"

//!This class is used to do create a simple checkpoint.
class Checkpoint : public Rectangle
{
public:
	/*!Initializer.*/
	Checkpoint(){};

	/*!Constructor.*/
	/**@param position = Position of the rectangle.
	@param dimensions = Size of the rectangle.
	@param texture = Texture to load.
	@param fAngle = An orientation of the checkpoint*/
	Checkpoint(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Texture& texture, const float fAngle);
};