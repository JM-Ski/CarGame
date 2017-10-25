#pragma once

#include "rectangle.h"
#include "physics.h"

//!This class is used to create and control a player.
class Player : public Rectangle
{
private:
	/*!Confirmation to rotate right.*/
	bool bRotateRight;

	/*!Confirmation to rotate left.*/
	bool bRotateLeft;

	/*!Confirmation to go up.*/
	bool bPressedUp;

	/*!Confirmation to go down.*/
	bool bPressedDown;

	/*!Physics for the player.*/
	Physics m_rectPhysics;
public:
	/*!Initializer.*/
	Player(){};
	/*!Constructor.*/
	/**@param position = Position of the player.
	@param dimensions = Size of the player.
	@param texture = Texture to load.*/
	Player(sf::Vector2f& position, sf::Vector2f& dimensions, sf::Texture& texture);

	/*!Process any key events.*/
	/**@param e = Event variable needed to capture any key presses.*/
	void processEvent(sf::Event& e);

	/*!Updates the player.*/
	/**@param timeStep = Time which updates most of the functions and variables, for example velocity.*/
	void update(float timeStep);

	/*!Sets a position of the player for physics.*/
	/**@param other = New position vector.*/
	void setPositionPhys(sf::Vector2f other);

	/*!Sets a velocity of the player for physics.*/
	/**@param other = New velocity vector.*/
	void setVelocityPhys(sf::Vector2f other);

	/*!Returns a velocity vector.*/
	/**@return m_rectPhysics.getVelocity() = Returns a current velocity vector.*/
	sf::Vector2f getVelocityPhys();

	/*!Resets player's variables.*/
	void resetPlayer();
};