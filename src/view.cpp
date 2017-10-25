#include "view.h"

//<! Default constructor
View::View(const sf::Vector2f& dimensions, const sf::Vector2f& centre, const float &fZoom)
{
	//Set all prroperties
	setSize(dimensions);
	setCenter(centre);
	zoom(fZoom);
}


