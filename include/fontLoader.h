#pragma once

#include <SFML\Graphics.hpp>

//!This class is used to manage fonts.
class FontLoader
{
private:
	/*!Vector of fonts.*/
	std::vector<sf::Font> fonts;

	/*!Our base directory with fonts.*/
	std::string baseDirectory; 
public:
	/*!An initializer.*/
	FontLoader();

	/*!Sets our base directory.*/
	/**@param dir = Our base directory.*/
	void setBaseDirectory(std::string dir);

	/*!Loads fonts based on the string input.*/
	/**@param fileNames = String vector with file names.*/
	void load(std::vector<std::string> fileNames);

	/*!Returns a font with said index.*/
	/**@param fIndex = Index of the font.
	@return *it = Retruns pointer to the font with matching index.*/
	sf::Font& getFont(int fIndex);
};