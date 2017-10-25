#include "circle.h"

//<! Default constructor
Circle::Circle(const sf::Vector2f& position, float fRadius)
{
	//Set all properties
	setPosition(position);
	setRadius(fRadius);
	setOrigin(fRadius, fRadius);
}

//<! Default constructor
Circle::Circle(sf::Vector2f& position, float fRadius, sf::Texture& texture)
{
	setPosition(position);
	setRadius(fRadius);
	setOrigin(fRadius, fRadius);
	setTexture(&texture);
}