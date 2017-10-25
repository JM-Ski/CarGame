#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>

//!This class is used to create an abstract base class of the rectangle.
class Rectangle : public sf::RectangleShape
{
protected:
	/*!Formula converting degrees to radians.*/
	/**@brief (float)M_PI / 180.f; */
	float fDegToRad;

	/*!Half extents needed to declare vertices.*/
	sf::Vector2f halfExtents;

	/*!Local vertices of the rectangle.*/
	std::vector<sf::Vertex> localVertices;

	/*!Global vertices of the rectangle.*/
	std::vector<sf::Vertex> globalVertices;

	/*!Face normals of the rectangle.*/
	std::vector<sf::Vector2f> normals;

	/*!One time setup of the local vertices.*/
	void setupLocalVertices();

	/*!One time setup of the global vertices including rotation.*/
	void updateGlobalVertices(float rotation);

public:
	/*!Initializer.*/
	Rectangle(){};

	/*!Constructor.*/
	/**@param position = Position of the rectangle.
	@param dimensions = Size of the rectangle*/
	Rectangle(const sf::Vector2f& position, const sf::Vector2f& dimensions);

	/*!Constructor.*/
	/**@param position = Position of the rectangle.
	@param dimensions = Size of the rectangle.
	@param texture = Texture to load.*/
	Rectangle(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Texture& texture);

	/*!Returns normals of said rectangle.*/
	/**@return normals = Returns face normals of the rectangle.*/
	std::vector<sf::Vector2f> getNormals() const;

	/*!Returns global vertices of said rectangle.*/
	/**@return globalVertices  = Returns global vertices of the rectangle.*/
	std::vector<sf::Vertex> getGlobalVertices() const;

	/*!Updates face normals based on the given rotation.*/
	/**@param rotation = Rotation needed so that normals can be updated whenever the rectangle rotates.*/
	void updateNormals(float rotation); //!< 
};