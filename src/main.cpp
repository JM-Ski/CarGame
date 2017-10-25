#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Car game");

	//Creating a game
	Game game;

	//Clock for updating
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else game.processEvent(event, window);		
		}

		// Find out how much time has elapsed
		float fElapsedTime = clock.getElapsedTime().asSeconds();

		// If a frame has past the update the physics
		if (fElapsedTime > 0.01)
		{
			game.update(fElapsedTime);
			clock.restart();
		}

		window.clear();
		window.draw(game);
		window.display();
	}
	return 0;
}