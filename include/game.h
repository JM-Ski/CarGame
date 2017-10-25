#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <sstream>

#include "player.h"
#include "wall.h"
#include "image.h"
#include "collision.h"
#include "view.h"
#include "textureLoader.h"
#include "fontLoader.h"
#include "audioLoader.h"
#include "simpleText.h"
#include "tire.h"
#include "vectorMaths.h"
#include "sphereTrigger.h"
#include "rectangleTrigger.h"
#include "checkpoint.h"
#include "staticCar.h"


//!This class is used to create a game window.
class Game : public sf::Drawable
{
private:
	/*!A variable which deals with vector maths.*/
	VectorMaths m_vectMaths;

	/*!An array of views.*/
	std::array<View, 3> m_aView;

	/*!A collision.*/
	Collision m_col;

	/*!A player.*/
	Player m_player;

	/*!Sphere trigger for the player*/
	RectangleTrigger m_playerTrigger;

	/*!An array of rectangle triggers for the objects*/
	std::array<RectangleTrigger, 11> m_aRectTrigger;

	/*!An array of images*/
	std::array<Image, 3> m_aImage;

	/*!An array of walls positioned in the world.*/
	std::array<Wall, 2> m_aWall;

	/*!An array of tires positioned at the top of the screen.*/
	std::array<Tire, 17> m_aTopTire;

	/*!An array of tires positioned at the bottom of the screen.*/
	std::array<Tire, 17> m_aBottomTire;

	/*!An array of checkpoints positioned in the world.*/
	std::array<Checkpoint, 4> m_aCheckpoint;

	/*!An array of cars positioned on the left.*/
	std::array<StaticCar, 3> m_aLeftStaticCar;

	/*!An array of cars positioned on the right.*/
	std::array<StaticCar, 3> m_aRightStaticCar;

	/*!An array of cars positioned on the top.*/
	std::array<StaticCar, 2> m_aTopStaticCar;

	/*!An array of cars positioned on the top.*/
	std::array<StaticCar, 2> m_aBottomStaticCar;

	/*!An array of sounds.*/
	std::array<sf::Sound, 1> m_aSound;

	/*!A vector of file names with textures.*/
	std::vector<std::string> sFileNameTexture;

	/*!A vector of file names with fonts.*/
	std::vector<std::string> sFileNameFont;

	/*!A vector of file names with music.*/
	std::vector<std::string> sFileNameMusic;

	/*!A vector of file names with sound effects.*/
	std::vector<std::string> sFileNameSound;

	/*!A texture loader.*/
	TextureLoader m_textureLoader;

	/*!A font loader.*/
	FontLoader m_fontLoader;

	/*!An audio loader.*/
	AudioLoader m_audioLoader;

	/*!An array of texts.*/
	std::array<SimpleText, 4> m_aText;

	/*!Clock needed to track the time.*/
	sf::Clock m_clock;

	/*!Time tracker.*/
	int iTime;

	/*!Lap counter.*/
	int iLap;

	/*!Lap confirmation.*/
	bool bLapConfirm[4];

	/*!Game states.*/
	enum GameState
	{
		Start, /*!< Start = We are starting the game.*/
		Reset, /*!< Reset = We are resetting game variables.*/
		Playing, /*!< Playing = We are playing the game.*/
		Pause /*!< Pause = Player has finished the game.*/
	};

	/*Our current game state.*/
	GameState eCurrentState;

public:
	/*!An initializer.*/
	Game();

	/*!Game update.*/
	/**@param timeStep = Time which updates most of the functions and variables, for example velocity.*/
	void update(float timeStep);

	/*!Drawing objects.*/
	/**@param target = Render target to draw to.
	   @param states = Current render states.*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/*!Process any key events.*/
	/**@param e = Event variable needed to capture any key presses.
	   @param window = Takes a window variable so that we can process events to it*/
	void processEvent(sf::Event& e, sf::RenderWindow& window);

	/*!All collision detection is done in here.*/
	void collisionDetection();

	/*!Bounding Volume Hierarchies - Left side.*/
	void leftBHV();

	/*!Bounding Volume Hierarchies - Right side.*/
	void rightBHV();

	/*!Bounding Volume Hierarchies - Top.*/
	void topBHV();

	/*!Bounding Volume Hierarchies - Bottom.*/
	void bottomBHV();
};