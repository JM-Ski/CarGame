#include "rectangle.h"

//<! Constructor of the rectangle

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& dimensions)
{
	//Set all prroperties
	setPosition(position);
	setSize(dimensions);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	halfExtents = getOrigin();
	fDegToRad = (float)M_PI / 180.f;

	//Populating vectors
	localVertices.resize(4);
	globalVertices.resize(4);
	normals.resize(4);

	//Performing necessary setup of the vertices and normals
	setupLocalVertices();
	updateGlobalVertices(getRotation());
	updateNormals(getRotation());
}

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Texture& texture)
{
	//Set all prroperties
	setPosition(position);
	setSize(dimensions);
	setOrigin(dimensions.x / 2.f, dimensions.y / 2.f);
	setTexture(&texture);
	halfExtents = getOrigin();
	fDegToRad = (float)M_PI / 180.f;

	//Populating vectors
	localVertices.resize(4);
	globalVertices.resize(4);
	normals.resize(4);

	//Performing necessary setup of the vertices and normals
	setupLocalVertices();
	updateGlobalVertices(getRotation());
	updateNormals(getRotation());
}

//<! One time setup of the local vertices
void Rectangle::setupLocalVertices()
{
	localVertices[0].position.x = -halfExtents.x;
	localVertices[0].position.y = -halfExtents.y;
	localVertices[1].position.x = -halfExtents.x;
	localVertices[1].position.y = halfExtents.y;
	localVertices[2].position.x = halfExtents.x;
	localVertices[2].position.y = halfExtents.y;
	localVertices[3].position.x = halfExtents.x;
	localVertices[3].position.y = -halfExtents.y;
} 

//<! One time setup of the global vertices including rotation
void Rectangle::updateGlobalVertices(float rotation)
{
	float fRotationAngle = 1.f * rotation * fDegToRad;

	for (int i = 0; i < 4; i++)
	{
		//Calculate rotation of the global vertices
		globalVertices[i].position.x = localVertices[i].position.x * std::cos(fRotationAngle) + localVertices[i].position.y * std::sin(-fRotationAngle);
		globalVertices[i].position.y = localVertices[i].position.x * std::sin(fRotationAngle) + localVertices[i].position.y * std::cos(fRotationAngle);

		//Also we should move them if object moves as well
		globalVertices[i].position += getPosition();
	}
}

//!< Updates face normals based on the given rotation
void Rectangle::updateNormals(float rotation)
{
	float fRotationAngle = 1.f * rotation * fDegToRad;

	//Apply normals
	normals[0].x = cos(fRotationAngle);
	normals[0].y = sin(fRotationAngle);
	normals[1].x = -sin(fRotationAngle);
	normals[1].y = cos(fRotationAngle);
}

//<! Gets normals of said rectangle
std::vector<sf::Vector2f> Rectangle::getNormals() const
{
	return normals;
}

//<! Gets global vertices of said rectangle
std::vector<sf::Vertex> Rectangle::getGlobalVertices() const
{
	return globalVertices;
}