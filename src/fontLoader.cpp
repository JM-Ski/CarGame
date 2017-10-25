#include "fontLoader.h"

//!< Initializer
FontLoader::FontLoader()
{
	setBaseDirectory(".\\assets\\fonts\\");
}

//<! Sets our base directory
void FontLoader::setBaseDirectory(std::string dir)
{
	baseDirectory = dir;
}

//<! Loads fonts based on the string input 
void FontLoader::load(std::vector<std::string> fileNames)
{
	//Iterate though the names
	for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
	{
		sf::Font font; // Create an empty font
		font.loadFromFile(baseDirectory + *it); //Apply the font so it's no longer empty
		fonts.push_back(font); // Add it to our vector of fonts
	}
}

//<! Returns a font with said index
sf::Font& FontLoader::getFont(int fIndex)
{
	int num = 0; //Our index number
	for (auto it = fonts.begin(); it != fonts.end(); ++it)
	{
		num++; //Increment the number
		if (num == fIndex) return *it; //Return the said font if it matches our index
	}
}