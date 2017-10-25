#include "vectorMaths.h"

//Gets magnitude
float VectorMaths::getMagnitude(sf::Vector2f someVector)
{
	fMag = someVector.x * someVector.x + someVector.y * someVector.y;
	return fMag;
}

//Get normalised vector
sf::Vector2f VectorMaths::getNormalisedVector(sf::Vector2f someVector)
{
	fMag = getMagnitude(someVector);
	fNormVector.x = someVector.x / fMag;
	fNormVector.y = someVector.y / fMag;
	return fNormVector;
}

//Rotation matrix
sf::Vector2f VectorMaths::rotationMatrix(sf::Vector2f someVector, float fAngle)
{
	rotationMat.x = someVector.x * cos(fAngle) + someVector.y * sin(-fAngle);
	rotationMat.y = someVector.x * sin(fAngle) + someVector.y * cos(fAngle);

	return rotationMat;
}

//Dot product
float VectorMaths::dotProduct(sf::Vector2f first, sf::Vector2f second)
{
	fDot = first.x * second.x + first.y * second.y;
	return fDot;
}

//Reset positon
sf::Vector2f VectorMaths::setPosition(sf::Vector2f position, sf::Vector2f collisionNormal, float fOverlap)
{
	newPos = position + collisionNormal * fOverlap;
	return newPos;
}

//Collision response
sf::Vector2f VectorMaths::setResponse(sf::Vector2f velocity, sf::Vector2f collisionNormal, float fRestitution)
{
	newVel = velocity - (1.f + fRestitution) * collisionNormal * (dotProduct(velocity, collisionNormal));
	return newVel;
}

//Vector zero
sf::Vector2f VectorMaths::zero()
{
	emptyVector = sf::Vector2f(0.f, 0.f);
	return emptyVector;
}