#include "audioLoader.h"

//!< Initializer
AudioLoader::AudioLoader()
{
	setBaseDirectory(".\\assets\\audio\\");
}

//<! Sets our base directory
void AudioLoader::setBaseDirectory(std::string dir)
{
	baseDirectory = dir;
}

//<! Loads buffers based on the string input 
void AudioLoader::load(std::vector<std::string> fileNames)
{
	for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
	{
		sf::SoundBuffer buffer; // Create an empty buffer
		buffer.loadFromFile(baseDirectory + *it); //Apply the sound so it's no longer empty
		buffers.push_back(buffer); // Add it to our vector of buffers
	}
}

//<! Opens music based on the string input 
void AudioLoader::open(std::vector<std::string> fileNames)
{
	int num = 0;
	for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
	{
		musics.at(num).openFromFile(baseDirectory + *it); //Apply the music so it's no longer empty
		num++;
	}
}

//<! Returns a buffer with said index
sf::SoundBuffer& AudioLoader::getSoundBuffer(int fIndex)
{
	int num = 0; //Our index number
	for (auto it = buffers.begin(); it != buffers.end(); ++it)
	{
		if (num == fIndex) return *it; //Return the said buffer if it matches our index
		num++; //Increment the number
	}
}

//Returns a music ith said index
sf::Music& AudioLoader::getMusic(int fIndex)
{
	int num = 0; //Our index number
	for (auto it = musics.begin(); it != musics.end(); ++it)
	{
		if (num == fIndex) return *it; //Return the said music if it matches our index
		num++; //Increment the number
	}
}