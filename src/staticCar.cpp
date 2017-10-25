#include "staticCar.h"

StaticCar::StaticCar(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Texture& texture, const float fAngle) : Rectangle(position, dimensions, texture)
{
	//Rotate
	rotate(fAngle);
	
	//Performing necessary setup of the vertices and normals
	setupLocalVertices();
	updateGlobalVertices(getRotation());
	updateNormals(getRotation());
}