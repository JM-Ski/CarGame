#pragma once

#include "rectangle.h"

//!This class is used to create a trigger.
class RectangleTrigger : public Rectangle
{
private:
	bool bCollision;
public:
	/*!Initializer.*/
	RectangleTrigger(){};

	/*!Constructor.*/
	/**@param position = Position of the rectangle.
	@param dimensions = Size of the rectangle.
	@param fAngle = An orientation of the trigger*/
	RectangleTrigger(const sf::Vector2f& position, const sf::Vector2f& dimensions, const float fAngle);

	/*!Rectangle update.*/
	/**@param position = Position that needs updating.
	@param bVertices = Whether to update global vertices of the trigger  */
	void update(sf::Vector2f position, bool bVertices);
};