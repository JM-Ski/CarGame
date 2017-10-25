#pragma once

#include <SFML\Graphics.hpp>

//!This class is used to manage textures.
class TextureLoader
{
private:
	/*!Vector of textures.*/
	std::vector<sf::Texture> textures;

	/*!Our base directory with textures.*/
	std::string baseDirectory;

public:
	/*!Initializer.*/
	TextureLoader();

	/*!Sets our base directory.*/
	/**@param dir = Our base directory.*/
	void setBaseDirectory(std::string dir);
	
	/*!Loads textures based on the string input.*/
	/**@param fileNames = String vector with file names.*/
	void load(std::vector<std::string> fileNames);

	/*!Returns texture with said index.*/
	/**@param fIndex = Index of the texture.
	@return *it = Retruns pointer to the texture with matching index.*/
	sf::Texture& getTexture(int fIndex);
};