#include "checkpoint.h"

Checkpoint::Checkpoint(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Texture& texture, const float fAngle) : Rectangle(position, dimensions, texture)
{
	//Rotate
	rotate(fAngle);
}