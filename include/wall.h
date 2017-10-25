#pragma once

#include "rectangle.h"

//!This class is used to construct a wall.
class Wall : public Rectangle
{
public:
	/*!Initializer.*/
	Wall(){};

	/*!Constructor.*/
	/**@param position = Position of the wall.
	@param dimensions = Size of the wall.
	@param texture = Texture to load.*/
	Wall(sf::Vector2f& position, sf::Vector2f& dimensions, sf::Texture& texture);
};