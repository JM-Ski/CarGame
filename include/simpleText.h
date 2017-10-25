#pragma once

#include <SFML\Graphics.hpp>
#include <sstream>

//!This class is used to create a simple text on the screen.
class SimpleText : public sf::Text
{
private:
	/*!A string type from sfml.*/
	sf::String sString;
public:
	/*!Initializer.*/
	SimpleText(){};
	/*!Constructor.*/
	/**@param position = A position on the screen.
	   @param font = A font to load in.
	   @param iSize = Size of the characters.
	   @param string = A string to display.
	   @param colour = Colour of the text.
	   */
	SimpleText(sf::Vector2f& position, sf::Font& font, int iSize, sf::String string, sf::Color colour);

	/*!Updates the text.*/
	/**@param view = A view that we will use to update our text position.
	@param fPosX = X position. You can add or subtract from the view.getCenter().x.
	@param fPosY = Y position. You can add or subtract from the view.getCenter().y.*/
	void update(sf::View& view, float fPosX, float fPosY);
	/*!Returns a sfml string type.*/
	/**@return sString */
	sf::String getSFString();
	
};
