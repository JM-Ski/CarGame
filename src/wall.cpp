#include "wall.h"

//!< Default constructor
Wall::Wall(sf::Vector2f& position, sf::Vector2f& dimensions, sf::Texture& texture) : Rectangle(position, dimensions, texture)
{
	//Set all prroperties
	setupLocalVertices();
	updateGlobalVertices(getRotation());
	updateNormals(getRotation());
}