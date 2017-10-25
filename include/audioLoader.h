#pragma once

#include <SFML\Audio.hpp>
#include <array>

//!This class is used to manage audio.
class AudioLoader
{
private:
	/*!Vector of buffers.*/
	std::vector<sf::SoundBuffer> buffers;

	/*!Vector of musics.*/
	std::array<sf::Music, 2> musics;

	/*!Our base directory with fonts.*/
	std::string baseDirectory;
public:
	/*!An initializer.*/
	AudioLoader();

	/*!Sets our base directory.*/
	/**@param dir = Our base directory.*/
	void setBaseDirectory(std::string dir);

	/*!Loads sounds based on the string input.*/
	/**@param fileNames = String vector with file names.*/
	void load(std::vector<std::string> fileNames);

	/*!Opens music based on the string input.*/
	/**@param fileNames = String vector with file names.*/
	void open(std::vector<std::string> fileNames);

	/*!Returns a buffer with said index.*/
	/**@param fIndex = Index of the font.
	@return *it = Retruns pointer to the buffer with matching index.*/
	sf::SoundBuffer& getSoundBuffer(int fIndex);

	/*!Returns a music with said index.*/
	/**@param fIndex = Index of the font.
	@return *it = Retruns pointer to the music with matching index.*/
	sf::Music& getMusic(int fIndex);
};