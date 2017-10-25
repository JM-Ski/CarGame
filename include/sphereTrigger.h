#pragma once

#include "circle.h"

//!This class is used to create a trigger.
class SphereTrigger : public Circle
{
private:
	bool bCollision;
public:
	/*!Initializer.*/
	SphereTrigger(){};

	/*!Constructor.*/
	/**@param position = Position of the circle.
	@param fRadius = Radius of the circle.*/
	SphereTrigger(const sf::Vector2f& position, float fRadius);

	/*!Sphere update.*/
	/**@param position = Position that needs updating.*/
	void upate(sf::Vector2f position);
};