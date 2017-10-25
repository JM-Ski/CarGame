#include "sphereTrigger.h"

SphereTrigger::SphereTrigger(const sf::Vector2f& position, float fRadius) : Circle(position, fRadius)
{
}

void SphereTrigger::upate(sf::Vector2f position)
{
	//This will set position to whatever is set in the update
	setPosition(position);
}