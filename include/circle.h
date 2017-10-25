#pragma once

#include <SFML/Graphics.hpp>

//!This class is used to create an abstract base class of the circle.
class Circle : public sf::CircleShape
{
public:
	/*!Initializer.*/
	Circle(){};

	/*!Constructor.*/
	/**@param position = Position of the circle.
	@param fRadius = Radius of the circle.*/
	Circle(const sf::Vector2f& position, float fRadius);

	/*!Constructor.*/
	/**@param position = Position of the circle.
	@param fRadius = Radius of the circle.
	@param texture = Texture to load.*/
	Circle(sf::Vector2f& position, float fRadius, sf::Texture& texture);
};