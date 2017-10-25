#include "simpleText.h"


SimpleText::SimpleText(sf::Vector2f& position, sf::Font& font, int iSize, sf::String string, sf::Color colour)
{
	//Set all prroperties
	setPosition(position);
	setFont(font);
	setCharacterSize(iSize);
	sString = string;
	setColor(colour);
	//setColor(sf::Color(233, 255, 0));
}

void SimpleText::update(sf::View& view, float fPosX, float fPosY) 
{
	setPosition(sf::Vector2f(view.getCenter().x + fPosX, view.getCenter().y + fPosY));
}

sf::String SimpleText::getSFString() 
{
	return sString;
}

