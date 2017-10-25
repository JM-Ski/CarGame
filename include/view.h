#pragma once

#include <SFML\Graphics.hpp>

//!This class is used to manage a scene.
class View : public sf::View
{
public:
	/*!Initializer.*/
	View(){};
	/*!Constructor.*/
	/**@param dimensions = Size of the view.
	@param centre = Centre of the view.
	@param fZoom = Zoom in or out from the centre of the view.*/
	View(const sf::Vector2f& dimensions, const sf::Vector2f& centre, const float& fZoom);
};