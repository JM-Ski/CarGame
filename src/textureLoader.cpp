#include "textureLoader.h"
#include <iostream>

//<! Initializer
TextureLoader::TextureLoader()
{
	setBaseDirectory(".\\assets\\textures\\");
}

//<! Sets our base directory
void TextureLoader::setBaseDirectory(std::string dir)
{
	baseDirectory = dir;
}

//<! Loads textures based on the string input 
void TextureLoader::load(std::vector<std::string> fileNames)
{
	//Loop throug hthe input
	for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
	{	
		sf::Texture text; // Create an empty texture
		text.loadFromFile(baseDirectory + *it); //Apply the textture so it's no longer empty
		textures.push_back(text); // Add it to our vector of textures
	}
}

//<! Returns texture with said index
sf::Texture& TextureLoader::getTexture(int fIndex)
{
	int num = 0; //Our index number
	for (auto it = textures.begin(); it != textures.end(); ++it)
	{
		if (num == fIndex) return *it; //Return the said texture if it matches our index
		num++; //Increment the number
	}
}