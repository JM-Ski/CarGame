#include "player.h"
#include <iostream>

//!< Initializer
Player::Player(sf::Vector2f& position, sf::Vector2f& dimensions, sf::Texture& texture): Rectangle(position, dimensions, texture)
{
	//Set all prroperties and init variables
	m_rectPhysics.setPosition(position);
	m_rectPhysics.setMass(20.f);
	m_rectPhysics.setSpeed(2.f);
	m_rectPhysics.setDirection(sf::Vector2f(0.f, 1.f));
	m_rectPhysics.setFriction(sf::Vector2f(.98f, .98f));

	bPressedUp = false;
	bPressedDown = false;
	bRotateLeft = false;
	bRotateRight = false;

	setupLocalVertices();
	updateGlobalVertices(getRotation());
	updateNormals(getRotation());
}

//!< Process any key events
void Player::processEvent(sf::Event &e)
{
	//If pressed
	if (e.type == sf::Event::KeyPressed)
	{
		//Confirm
		if (e.key.code == sf::Keyboard::Up) bPressedUp = true;
		if (e.key.code == sf::Keyboard::Down) bPressedDown = true;
		if (e.key.code == sf::Keyboard::Left) bRotateLeft = true;
		if (e.key.code == sf::Keyboard::Right) bRotateRight = true;
	}

	//If released
	if (e.type == sf::Event::KeyReleased)
	{
		//Confirm
		if (e.key.code == sf::Keyboard::Up) bPressedUp = false;
		if (e.key.code == sf::Keyboard::Down) bPressedDown = false;
		if (e.key.code == sf::Keyboard::Left) bRotateLeft = false;
		if (e.key.code == sf::Keyboard::Right) bRotateRight = false;
	}
}

//!< Update the player
void Player::update(float timeStep)
{
	//Update vertices and normal as we move
	updateGlobalVertices(getRotation());
	updateNormals(getRotation());

	//Set position and angle as we move
	float fAngle = getRotation();
	sf::Vector2f position = m_rectPhysics.getPosition();
	m_rectPhysics.setAngle(fAngle);

	//Do something when we press an appropiate key
	if (bPressedUp) m_rectPhysics.eCurrentDirection = Physics::Direction::Negative; // Changes directon to go up
	if (bPressedDown) m_rectPhysics.eCurrentDirection = Physics::Direction::Positive; // Changes direction to go down
	if (!bPressedDown && !bPressedUp) m_rectPhysics.eCurrentDirection = Physics::Direction::None; // Else we don't do anything
	
	//Rotates us
	if (bRotateRight && bPressedUp || bRotateRight && bPressedDown) rotate(.5f);
	if (bRotateLeft && bPressedUp || bRotateLeft && bPressedDown) rotate(-.5f);

	//Apply position and update physics
	setPosition(position);
	m_rectPhysics.updatePhysics(timeStep);
}

//!< Sets position of the player for physcis
void Player::setPositionPhys(sf::Vector2f other)
{
	m_rectPhysics.setPosition(other);
}

//!< Sets veloctiy of the player for physcis
void Player::setVelocityPhys(sf::Vector2f other)
{
	m_rectPhysics.setVelocity(other);
}

//!< Returns velocity vector
sf::Vector2f Player::getVelocityPhys()
{
	return m_rectPhysics.getVelocity();
}

void Player::resetPlayer()
{
	setRotation(0.f);
	m_rectPhysics.eCurrentDirection = Physics::Direction::None;
	bPressedUp = false;
	bPressedDown = false;
	bRotateLeft = false;
	bRotateRight = false;
	setVelocityPhys(sf::Vector2f(0.f, 0.f));
}