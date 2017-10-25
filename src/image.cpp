#include "image.h"

//<! Default constructor
Image::Image(sf::Vector2f& position, sf::Vector2f& dimensions, sf::Texture& texture)
{
	//Set all prroperties
	setPosition(position);
	setScale(dimensions.x / texture.getSize().x, dimensions.y / texture.getSize().y);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	setTexture(texture);
}