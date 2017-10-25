#pragma once

#include <SFML\Graphics.hpp>

//!This class is used to do simple vector calculations.
class VectorMaths
{
private:
	/*!Magnitude.*/
	float fMag;

	/*!Normalised vector.*/
	sf::Vector2f fNormVector;

	/*!Rotation matrix.*/
	sf::Vector2f rotationMat;

	/*!Dot product.*/
	float fDot;

	/*!New position.*/
	sf::Vector2f newPos;

	/*!New velocity.*/
	sf::Vector2f newVel;

	/*!An empty vector.*/
	sf::Vector2f emptyVector;

public:
	/*!Initializer.*/
	VectorMaths(){};

	/*!Calculates a magnitude of a vector.*/
	/**@param someVector = We will calculate magnitude of that vector.
	@return fMag = Magnitude of a vector.*/
	float getMagnitude(sf::Vector2f someVector);

	/*!Calculates a normalised vector.*/
	/**@param someVector = We will calculate unit vector of that vector.
	@return fNormVector = Returns a normalised vector.*/
	sf::Vector2f getNormalisedVector(sf::Vector2f someVector);

	/*!Calculates a rotation matrix.*/
	/**@param someVector = A vector to be used in rotation.
	@param fAngle = An angle at which we will rotate the vector.
	@return temp = Vector with applied matrix.*/
	sf::Vector2f rotationMatrix(sf::Vector2f someVector, float fAngle);
	
	/*!Calculates a dot product.*/
	/**@param first = A first vector.
	@param second = A second vector.
	@return fDot = Returns a dot product of two vectors.*/
	float dotProduct(sf::Vector2f first, sf::Vector2f second);

	/*!Reposition an object.*/
	/**@param position = A position of the object we want apply new position to.
	@param collisionNormal = A collision normal from the collision test.
	@param fOverlap = The smallest overlap from the collision test.
	@return newPos = Returns  new position with applied changes.*/
	sf::Vector2f setPosition(sf::Vector2f position, sf::Vector2f collisionNormal, float fOverlap);

	/*!Collision response.*/
	/**@param velocity = A velocioty of the object we want apply response to.
	@param collisionNormal = A collision normal from the collision test.
	@param fRestitution = Coeffcient of restitution.
	@return newVel = Returns  new velocity with applied response.*/
	sf::Vector2f setResponse(sf::Vector2f velocity, sf::Vector2f collisionNormal, float fRestitution);

	/*!Vector2f (0.f, 0.f) .*/
	/**@return emptyVel = Returns an empty vector.*/
	sf::Vector2f zero();
};