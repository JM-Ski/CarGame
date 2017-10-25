#pragma once

#include <SFML/Graphics.hpp>

//!This class is used to construct an image.
class Image: public sf::Sprite
{
public:
	/*!An initializer.*/
	Image(){};

	/*!Constructor.*/
	/**@param position = Position of the image.
	@param dimensions = Size of the image.
	@param texture = Texture to load.*/
	Image(sf::Vector2f& position, sf::Vector2f& dimensions, sf::Texture& texture);
};