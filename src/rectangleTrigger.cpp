#pragma once

#include "rectangleTrigger.h"

RectangleTrigger::RectangleTrigger(const sf::Vector2f& position, const sf::Vector2f& dimensions, const float fAngle) : Rectangle(position, dimensions)
{
	//Rotate
	rotate(fAngle);
}

void RectangleTrigger::update(sf::Vector2f position, bool bVertices)
{
	//This will set position to whatever is set in the update
	setPosition(position);

	//Update vertices if trigger is on the move
	if (bVertices) updateGlobalVertices(getRotation());
	
}