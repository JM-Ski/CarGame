#include "physics.h"
#include <iostream>

//!< Initializer
Physics::Physics()
{
	//Initialize all variables
	position = m_vectMaths.zero();
	velocity = m_vectMaths.zero();
	friction = m_vectMaths.zero();
	direction = m_vectMaths.zero();
	rotationAndDirection = m_vectMaths.zero();
	fSpeed = 0.f;
	fMass = 0.f;
	fAngle = 0.f;
	eCurrentDirection = Direction::None;

	//DegToRad
	fDegToRad = (float)M_PI / 180;
}

//!< Physics update
void Physics::updatePhysics(float timeStep)
{
	//Setup rotation
	rotationAndDirection = m_vectMaths.rotationMatrix(direction, fAngle * fDegToRad);

	//Change direction
	if (eCurrentDirection == Direction::Positive) velocity += rotationAndDirection * fSpeed;
	if (eCurrentDirection == Direction::Negative) velocity -= rotationAndDirection * fSpeed;
	
	//Apply friction
	velocity.x *= friction.x;
	velocity.y *= friction.y;
	
	//Set position
	position += velocity * timeStep;
}

//!< Sets the position
void Physics::setPosition(sf::Vector2f newPos)
{
	position = newPos;
}

//!< Sets the velocity
void Physics::setVelocity(sf::Vector2f newVel)
{
	velocity = newVel;
}

//!< Sets the mass
void Physics::setMass(float fNewMass)
{
	fMass = fNewMass;
}

//!< Sets the speed
void Physics::setSpeed(float fNewSpeed)
{
	fSpeed = fNewSpeed;
}

//!< Sets the direction
void Physics::setDirection(sf::Vector2f newDir)
{
	direction = newDir;
}

//!< Sets the friction
void Physics::setFriction(sf::Vector2f newFri)
{
	friction = newFri;
}

//!< Sets the angle
void Physics::setAngle(float fNewAngle)
{
	fAngle = fNewAngle;
}

//!< Returns the position
sf::Vector2f Physics::getPosition() const
{
	return position;
}

//!< Returns the velocity
sf::Vector2f Physics::getVelocity() const
{
	return velocity;
}

/*!Sets a direction for the object.*/
/**@param eDirection = New direction.*/
void Physics::setDirection(Direction eDirection)
{
	eCurrentDirection = eDirection;
}


