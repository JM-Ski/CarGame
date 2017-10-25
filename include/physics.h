#pragma once

#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "vectorMaths.h"

//!This class is used to create a simulation of movement.
class Physics
{
private:
	/*!A position.*/
	sf::Vector2f position;

	/*!A velocity.*/
	sf::Vector2f velocity;

	/*!A friction.*/
	sf::Vector2f friction;

	/*!A direction.*/
	sf::Vector2f direction;

	/*!A direction and rotation combined.*/
	sf::Vector2f rotationAndDirection;

	/*!A speed.*/
	float fSpeed;

	/*!A mass.*/
	float fMass;

	/*!An angle.*/
	float fAngle;

	/*!A conversion from degrees to radians.*/
	/**@brief(float)M_PI / 180.f;*/
	float fDegToRad;

	/*!A variable which deals with vector maths.*/
	VectorMaths m_vectMaths;

public:
	/*!An initializer.*/
	Physics();

	/*!Physics update.*/
	/**@param timeStep = Time which updates most of the functions and variables, for example velocity.*/
	void updatePhysics(float timeStep);

	/*!The direction that our object faces.*/
	enum Direction 
	{ 
		Positive, /*!< Positive direction = We are going down.*/
		Negative, /*!< Negative direction = We are going up.*/
		None  /*!< None = We are not moving.*/
	};

	/*!Our current direction.*/
	Direction eCurrentDirection;

	/*!Sets a position for physics simulation.*/
	/**@param position = New position vector.*/
	void setPosition(sf::Vector2f position);

	/*!Sets a velocity for physics simulation.*/
	/**@param newVel = New velocity vector.*/
	void setVelocity(sf::Vector2f newVel);

	/*!Sets a speed for physics simulation.*/
	/**@param fNewSpeed = New speed.*/
	void setSpeed(float fNewSpeed);

	/*!Sets a mass for physics simulation.*/
	/**@param fNewMass = New mass.*/
	void setMass(float fNewMass);

	/*!Sets a direction for physics simulation.*/
	/**@param newDir = New direction vector.*/
	void setDirection(sf::Vector2f newDir);

	/*!Sets a friction for physics simulation.*/
	/**@param newFri = New friction vector.*/
	void setFriction(sf::Vector2f newFri);

	/*!Sets an angle for physics simulation.*/
	/**@param fNewAngle = New angle.*/
	void setAngle(float fNewAngle);

	/*!Returns a position.*/
	/**@return position = Returns a current position.*/
	sf::Vector2f getPosition() const;

	/*!Returns a velocity.*/
	/**@return velocity = Returns a current velocity.*/
	sf::Vector2f getVelocity() const;

	/*!Sets a direction for the object.*/
	/**@param eDirection = New direction.*/
	void setDirection(Direction eDirection);
};