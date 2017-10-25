#include "game.h"

//!< Initializer
Game::Game()
{
	//Loading fonts, textures and sounds----------------------------------------------------------------------------------------
	sFileNameTexture = { "player.png", "background.png", "wall.png", "tire.png", "checkpoint.png", "car.png", "menu.png", "pause.png" };
	m_textureLoader.load(sFileNameTexture);
	sFileNameFont = { "leaugeGothic.otf", "Chunkfive.otf" };
	m_fontLoader.load(sFileNameFont);
	sFileNameMusic = { "menu.ogg", "game.ogg" };
	m_audioLoader.open(sFileNameMusic);
	m_audioLoader.getMusic(1).play();
	

	//Setting background screen images--------------------------------------------------------------------------------
	for (int unsigned i = 0; i < m_aImage.size(); i++)
	{
		m_aImage.at(0) = Image(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f), m_textureLoader.getTexture(1)); // Background
		m_aImage.at(1) = Image(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f), m_textureLoader.getTexture(6)); // Menu
		m_aImage.at(2) = Image(sf::Vector2f(400.f, 300.f), sf::Vector2f(520.f, 129.f), m_textureLoader.getTexture(7)); // Pause pop-up screen
	}

	//Declaring objects --------------------------------------------------------------------------------------
	
	//Player and player's trigger
	m_player = Player(sf::Vector2f(100.f, 340.f), sf::Vector2f(42.f, 48.f), m_textureLoader.getTexture(0));

	//Walls
	for (int unsigned i = 0; i < m_aWall.size(); i++)
	{
		m_aWall.at(0) = Wall(sf::Vector2f(25.f, 300.f), sf::Vector2f(50.f, 600.f), m_textureLoader.getTexture(2)); //Left wall
		m_aWall.at(1) = Wall(sf::Vector2f(775.f, 300.f), sf::Vector2f(50.f, 600.f), m_textureLoader.getTexture(2)); //Right wall
	}

	//Tires
	for (int unsigned i = 0; i < m_aTopTire.size(); i++) m_aTopTire.at(i) = Tire(sf::Vector2f(75.f + i * 40.f, 20.f), 20.f, m_textureLoader.getTexture(3));
	for (int unsigned i = 0; i < m_aBottomTire.size(); i++) m_aBottomTire.at(i) = Tire(sf::Vector2f(75.f + i * 40.f, 580.f), 20.f, m_textureLoader.getTexture(3));
	
	//Cars
	for (int unsigned i = 0; i < m_aLeftStaticCar.size(); i++) m_aLeftStaticCar.at(i) = StaticCar(sf::Vector2f(270.f, 150.f + i * 100.f), sf::Vector2f(100.f, 50.f), m_textureLoader.getTexture(5), 90.f);
	for (int unsigned i = 0; i < m_aRightStaticCar.size(); i++) m_aRightStaticCar.at(i) = StaticCar(sf::Vector2f(550.f, 150.f + i * 100.f), sf::Vector2f(100.f, 50.f), m_textureLoader.getTexture(5), 90.f);
	for (int unsigned i = 0; i < m_aTopStaticCar.size(); i++) m_aTopStaticCar.at(i) = StaticCar(sf::Vector2f(360.f + i * 100.f, 150.f), sf::Vector2f(100.f, 50.f), m_textureLoader.getTexture(5), 0.f);
	for (int unsigned i = 0; i < m_aBottomStaticCar.size(); i++) m_aBottomStaticCar.at(i) = StaticCar(sf::Vector2f(360.f + i * 100.f, 425.f), sf::Vector2f(100.f, 50.f), m_textureLoader.getTexture(5), 0.f);
	
	//Rectangle triggers
	for (int unsigned i = 0; i < m_aRectTrigger.size(); i++)
	{
		m_aRectTrigger.at(0) = RectangleTrigger(sf::Vector2f(400.f, 40.f), sf::Vector2f(75.f + m_aTopTire.size() * 40.f, 20.f), 0.f); // Top tire
		m_aRectTrigger.at(1) = RectangleTrigger(sf::Vector2f(400.f, 560.f), sf::Vector2f(75.f + m_aBottomTire.size() * 40.f, 20.f), 0.f); // Bottom tire
		m_aRectTrigger.at(2) = RectangleTrigger(sf::Vector2f(400.f, 120.f), sf::Vector2f(260.f, 40.f), 0.f); // Top cars
		m_aRectTrigger.at(3) = RectangleTrigger(sf::Vector2f(400.f, 450.f), sf::Vector2f(260.f, 40.f), 0.f); // Bottom cars
		m_aRectTrigger.at(4) = RectangleTrigger(sf::Vector2f(270.f, 250.f), sf::Vector2f(80.f, 325.f), 0.f); // Left cars
		m_aRectTrigger.at(5) = RectangleTrigger(sf::Vector2f(550.f, 250.f), sf::Vector2f(80.f, 325.f), 0.f); // Right cars
		m_aRectTrigger.at(6) = RectangleTrigger(sf::Vector2f(150.f, 280.f), sf::Vector2f(300.f, 360.f), 0.f); // Left Rectangle Check
		m_aRectTrigger.at(7) = RectangleTrigger(sf::Vector2f(400.f, 60.f), sf::Vector2f(800.f, 200.f), 0.f); // Top Rectangle Check
		m_aRectTrigger.at(8) = RectangleTrigger(sf::Vector2f(650.f, 280.f), sf::Vector2f(300.f, 360.f), 0.f); // Right Rectangle Check
		m_aRectTrigger.at(9) = RectangleTrigger(sf::Vector2f(400.f, 515.f), sf::Vector2f(800.f, 250.f), 0.f); // Bottom Rectangle Check
		m_aRectTrigger.at(10) = RectangleTrigger(m_player.getPosition(), sf::Vector2f(m_player.getSize().x + 50.f, m_player.getSize().y + 50.f), 0.f); // Player's trigger
	}
	
	//Checkpoints
	for (int unsigned i = 0; i < m_aCheckpoint.size(); i++)
	{
		m_aCheckpoint.at(0) = Checkpoint(sf::Vector2f(156.f, 300.f), sf::Vector2f(160.f, 10.f), m_textureLoader.getTexture(4), 0.f); // Left
		m_aCheckpoint.at(1) = Checkpoint(sf::Vector2f(670.f, 300.f), sf::Vector2f(160.f, 10.f), m_textureLoader.getTexture(4), 0.f); // Right
		m_aCheckpoint.at(2) = Checkpoint(sf::Vector2f(400.f, 50.f), sf::Vector2f(80.f, 10.f), m_textureLoader.getTexture(4), 90.f); // Top
		m_aCheckpoint.at(3) = Checkpoint(sf::Vector2f(400.f, 525.f), sf::Vector2f(110.f, 10.f), m_textureLoader.getTexture(4), 90.f); // Bottom
	}
	
	//Texts-------------------------------------------------------------------------------------------------------------
	for (int unsigned i = 0; i < m_aText.size(); i++)
	{
		m_aText.at(0) = SimpleText(m_vectMaths.zero(), m_fontLoader.getFont(2), 14, sf::String("Speed: "), sf::Color::Yellow); // Speed text
		m_aText.at(1) = SimpleText(m_vectMaths.zero(), m_fontLoader.getFont(1), 14, sf::String("Time: "), sf::Color::Yellow); // Time text
		m_aText.at(2) = SimpleText(m_vectMaths.zero(), m_fontLoader.getFont(2), 14, sf::String("Lap: "), sf::Color::Yellow); // Lap text
	}
	
	//View-----------------------------------------------------------------------------------------------------------
	for (int unsigned i = 0; i < m_aView.size(); i++)
	{
		m_aView.at(0) = View(sf::Vector2f(800.f, 600.f), m_player.getPosition(), 0.5f); // Scene
		m_aView.at(1) = View(sf::Vector2f(800.f, 600.f), m_aImage.at(1).getPosition(), 1.f); // Menu
		m_aView.at(2) = View(sf::Vector2f(800.f, 600.f), m_player.getPosition(), 1.f); // Minimap
	}

	sf::Vector2f newCent = sf::Vector2f(400.f, 300.f);
	m_aView.at(2).setViewport(sf::FloatRect(0.8f, 0.f, 0.2f, 0.2f));
	m_aView.at(2).setCenter(newCent);
	
	//Enum declarations and game variables--------------------------------------------------------------------------------------------------
	eCurrentState = GameState::Start;

	iLap = 0;
	bLapConfirm[0] = false;
	bLapConfirm[1] = false;
	bLapConfirm[2] = false;
	bLapConfirm[3] = false;
}

//!< Update
void Game::update(float timeStep)
{
	
	if (eCurrentState == GameState::Start) m_clock.restart();
	
	if (eCurrentState == GameState::Reset)
	{
		//Reset everything to default
		m_clock.restart();
		
		iLap = 0;
		bLapConfirm[0] = false;
		bLapConfirm[1] = false;
		bLapConfirm[2] = false;
		bLapConfirm[3] = false;

		m_player.resetPlayer();
		m_player.setPositionPhys(sf::Vector2f(100.f, 340.f));
		
		m_audioLoader.getMusic(1).stop();
		m_audioLoader.getMusic(0).play();
		eCurrentState = GameState::Playing;
	}

	if (eCurrentState == GameState::Playing)
	{	
		/*!Clock needed to track the time.*/
		//Updating objects
		iTime = m_clock.getElapsedTime().asSeconds();
		m_aView.at(0).setCenter(m_player.getPosition());
		m_player.update(timeStep);
		m_aText.at(0).update(m_aView.at(0), -200.f, 135.f);
		m_aText.at(1).update(m_aView.at(0), -200.f, -150.f);
		m_aText.at(2).update(m_aView.at(0), 130.f, 135.f);
		m_aRectTrigger.at(10).update(m_player.getPosition(), true);
		
		//Detecting collisions
		collisionDetection();

		//Updating the content of the text
		//Speed update
		std::stringstream ssSpeed;
		int iMag = m_vectMaths.getMagnitude(m_player.getVelocityPhys()) / 100.f;
		if (iMag < 0) iMag = 0;
		ssSpeed << iMag;
		m_aText.at(0).setString(m_aText.at(0).getSFString() + ssSpeed.str() + " m/s");

		//Time update
		std::stringstream ssTime;
		ssTime << iTime;
		m_aText.at(1).setString(m_aText.at(1).getSFString() + ssTime.str() + "s");

		//Laps update
		std::stringstream ssLap;
		ssLap << iLap;
		m_aText.at(2).setString(m_aText.at(2).getSFString() + ssLap.str() + "/4");

		//If we manage to pass all laps four times
		if (iLap == 4)
		{
			eCurrentState = GameState::Pause;
		
			//Show a pop-up
			sf::Vector2f newPos;
			newPos.x = m_player.getPosition().x - 30.f;
			newPos.y = m_player.getPosition().y;
			m_aImage.at(2).setPosition(newPos);
		}
	}
}

//!< Drawing objects
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Draw if playing or is pause
	if (eCurrentState == GameState::Playing || GameState::Pause)
	{
		//Our game view*******************************************************
		target.setView(m_aView.at(0));
		target.draw(m_aImage.at(0));

		for (int unsigned i = 0; i < m_aWall.size(); i++) target.draw(m_aWall.at(i));
		for (int unsigned i = 0; i < m_aCheckpoint.size(); i++) target.draw(m_aCheckpoint.at(i));
		for (int unsigned i = 0; i < m_aTopTire.size(); i++) target.draw(m_aTopTire.at(i));
		for (int unsigned i = 0; i < m_aBottomTire.size(); i++) target.draw(m_aBottomTire.at(i));
		for (int unsigned i = 0; i < m_aLeftStaticCar.size(); i++) target.draw(m_aLeftStaticCar.at(i));
		for (int unsigned i = 0; i < m_aRightStaticCar.size(); i++) target.draw(m_aRightStaticCar.at(i));
		for (int unsigned i = 0; i < m_aTopStaticCar.size(); i++) target.draw(m_aTopStaticCar.at(i));
		for (int unsigned i = 0; i < m_aBottomStaticCar.size(); i++) target.draw(m_aBottomStaticCar.at(i));

		target.draw(m_player);

		for (int unsigned i = 0; i < m_aText.size(); i++) target.draw(m_aText.at(i));

		if (eCurrentState == GameState::Pause) target.draw(m_aImage.at(2));
		
		//Our minimap****************************************************************************************
		target.setView(m_aView.at(2));
		target.draw(m_aImage.at(0));

		for (int unsigned i = 0; i < m_aWall.size(); i++) target.draw(m_aWall.at(i));
		for (int unsigned i = 0; i < m_aCheckpoint.size(); i++) target.draw(m_aCheckpoint.at(i));
		for (int unsigned i = 0; i < m_aTopTire.size(); i++) target.draw(m_aTopTire.at(i));
		for (int unsigned i = 0; i < m_aBottomTire.size(); i++) target.draw(m_aBottomTire.at(i));
		for (int unsigned i = 0; i < m_aLeftStaticCar.size(); i++) target.draw(m_aLeftStaticCar.at(i));
		for (int unsigned i = 0; i < m_aRightStaticCar.size(); i++) target.draw(m_aRightStaticCar.at(i));
		for (int unsigned i = 0; i < m_aTopStaticCar.size(); i++) target.draw(m_aTopStaticCar.at(i));
		for (int unsigned i = 0; i < m_aBottomStaticCar.size(); i++) target.draw(m_aBottomStaticCar.at(i));

		target.draw(m_player);
		
	}

	if (eCurrentState == GameState::Start)
	{
		target.setView(m_aView.at(1));
		target.draw(m_aImage.at(1));
	}
}

//!< Processing key events
void Game::processEvent(sf::Event& e, sf::RenderWindow& window)
{
	//As long as we are at the menu
	if (eCurrentState == GameState::Start)
	{
		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Return) eCurrentState = GameState::Reset;
			if (e.key.code == sf::Keyboard::Escape) window.close(); // Close the window
		}
	}
	
	//As long as we are playing
	if (eCurrentState == GameState::Playing)
	{
		m_player.processEvent(e);
		if (e.key.code == sf::Keyboard::Escape) window.close(); // Close the window
	}

	//As long as we are on the pause pop-up
	if (eCurrentState == GameState::Pause)
	{
		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Return) eCurrentState = GameState::Reset;
			if (e.key.code == sf::Keyboard::Escape) window.close(); // Close the window
		}
	}
}

//!< Collsion detection
void Game::collisionDetection()
{
	leftBHV(); //Left rectangle
	topBHV();  // Top rectangle
	rightBHV(); // Right rectangle
	bottomBHV(); // Bottom rectangle

	//If all true reset
	if (bLapConfirm[0] && bLapConfirm[1] && bLapConfirm[2] && bLapConfirm[3])
	{
		bLapConfirm[0] = false;
		bLapConfirm[1] = false;
		bLapConfirm[2] = false;
		bLapConfirm[3] = false;
		iLap++; // Add to our lap counter
	}
}

//Left rectangle
void Game::leftBHV()
{
	//Left rectangle
	if (m_col.Intersects(m_aRectTrigger.at(6), m_aRectTrigger.at(10), "AABB"))
	{
		//Collision check for the sphere trigger to intersect with a wall
		if (m_col.Intersects(m_aRectTrigger.at(10), m_aWall.at(0), "AABB"))
		{
			
			//Collision check if player collides with a wall
			if (m_col.Intersects(m_player, m_aWall.at(0)))
			{
				
				m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
				m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
			}
		}

		//Collision check for the sphere trigger to intersect with a left car
		if (m_col.Intersects(m_aRectTrigger.at(4), m_aRectTrigger.at(10), "AABB"))
		{
			for (int unsigned i = 0; i < m_aLeftStaticCar.size(); i++)
			{
				//Collision check for player against a car on the left
				if (m_col.Intersects(m_player, m_aLeftStaticCar.at(i)))
				{
					m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
					m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
				}
			}
		}

		if (m_col.Intersects(m_aCheckpoint.at(0), m_aRectTrigger.at(10), "AABB"))
		{
			if (bLapConfirm[1] && bLapConfirm[2] && bLapConfirm[3])
			{
				bLapConfirm[0] = true; //Left checkpoint
			}
		}
	}
}

//Top rectangle
void Game::topBHV()
{
	//Top rectangle
	if (m_col.Intersects(m_aRectTrigger.at(7), m_aRectTrigger.at(10), "AABB"))
	{
		//Collision check for the sphere trigger to intersect with the left wall
		if (m_col.Intersects(m_aWall.at(0), m_aRectTrigger.at(10), "AABB") && !m_col.Intersects(m_aRectTrigger.at(6), m_aRectTrigger.at(10), "AABB"))
		{
			//Collision check if player collides with the left wall
			if (m_col.Intersects(m_player, m_aWall.at(0))) // We must check player's OBB with the left rectagle to prevent weird collision behaviour
			{
				m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
				m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
			}
		}

		//Collision check for the sphere trigger to intersect with the right wall
		if (m_col.Intersects(m_aWall.at(1), m_aRectTrigger.at(10), "AABB") && !m_col.Intersects(m_aRectTrigger.at(8), m_aRectTrigger.at(10), "AABB"))
		{
			//Collision check if player collides with the right wall
			if (m_col.Intersects(m_player, m_aWall.at(1)))  // We must check player's OBB with the left rectagle to prevent weird collision behaviour
			{
				m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
				m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
			}
		}

		//Collision check for player against a tire at the top
		if (m_col.Intersects(m_aRectTrigger.at(0), m_aRectTrigger.at(10), "AABB"))
		{
			for (int unsigned i = 0; i < m_aTopTire.size(); i++)
			{
				if (m_col.Intersects(m_player, m_aTopTire.at(i)))
				{
					m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionCircNormal(), m_col.getCircOverlap()));
					m_player.setVelocityPhys(m_vectMaths.setResponse(-m_player.getVelocityPhys(), m_col.getCollisionCircNormal(), 2.f));
				}
			}
		}

		//Collision check for player against a car at the top
		if (m_col.Intersects(m_aRectTrigger.at(2), m_aRectTrigger.at(10), "AABB"))
		{
			for (int unsigned i = 0; i < m_aTopStaticCar.size(); i++)
			{
				if (m_col.Intersects(m_player, m_aTopStaticCar.at(i)))
				{
					m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
					m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
				}
			}
		}

		if (m_col.Intersects(m_aCheckpoint.at(2), m_aRectTrigger.at(10)))
		{
			bLapConfirm[2] = true; // Top checkpoint
		}
	}
}

//Right rectangle
void Game::rightBHV()
{
	if (m_col.Intersects(m_aRectTrigger.at(8), m_aRectTrigger.at(10), "AABB"))
	{
		//Collision check for the sphere trigger to intersect with the right wall
		if (m_col.Intersects(m_aWall.at(1), m_aRectTrigger.at(10), "AABB"))
		{
			//Collision check if player collides with the right wall
			if (m_col.Intersects(m_player, m_aWall.at(1)))  // We must check player's OBB with the left rectagle to prevent weird collision behaviour
			{
				m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
				m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
			}
		}

		//Collision check for player against a car on the right
		if (m_col.Intersects(m_aRectTrigger.at(5), m_aRectTrigger.at(10), "AABB"))
		{
			for (int unsigned i = 0; i < m_aRightStaticCar.size(); i++)
			{
				if (m_col.Intersects(m_player, m_aRightStaticCar.at(i)))
				{
					m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
					m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
				}
			}
		}

		if (m_col.Intersects(m_aCheckpoint.at(1), m_aRectTrigger.at(10), "AABB")) bLapConfirm[1] = true; //Right checkpoint
	}
}

//Bottom rectangle
void Game::bottomBHV()
{
	if (m_col.Intersects(m_aRectTrigger.at(9), m_aRectTrigger.at(10), "AABB"))
	{
		//Collision check for the sphere trigger to intersect with the left wall
		if (m_col.Intersects(m_aWall.at(0), m_aRectTrigger.at(10), "AABB") && !m_col.Intersects(m_aRectTrigger.at(6), m_aRectTrigger.at(10), "AABB"))
		{
			//Collision check if player collides with the left wall
			if (m_col.Intersects(m_player, m_aWall.at(0))) // We must check player's OBB with the left rectagle to prevent weird collision behaviour
			{
				m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
				m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
			}
		}

		//Collision check for the sphere trigger to intersect with the right wall
		if (m_col.Intersects(m_aWall.at(1), m_aRectTrigger.at(10), "AABB") && !m_col.Intersects(m_aRectTrigger.at(8), m_aRectTrigger.at(10), "AABB"))
		{
			//Collision check if player collides with the right wall
			if (m_col.Intersects(m_player, m_aWall.at(1)))  // We must check player's OBB with the left rectagle to prevent weird collision behaviour
			{
				m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
				m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
			}
		}

		//Collision check for player against a tire at the bottom
		if (m_col.Intersects(m_aRectTrigger.at(1), m_aRectTrigger.at(10), "AABB"))
		{
			for (int unsigned i = 0; i < m_aBottomTire.size(); i++)
			{
				if (m_col.Intersects(m_player, m_aBottomTire.at(i)))
				{
					m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionCircNormal(), m_col.getCircOverlap()));
					m_player.setVelocityPhys(m_vectMaths.setResponse(-m_player.getVelocityPhys(), m_col.getCollisionCircNormal(), 2.f));
				}
			}
		}

		//Collision check for player against a car at the bottom
		if (m_col.Intersects(m_aRectTrigger.at(3), m_aRectTrigger.at(10), "AABB"))
		{
			for (int unsigned i = 0; i < m_aBottomStaticCar.size(); i++)
			{
				if (m_col.Intersects(m_player, m_aBottomStaticCar.at(i)))
				{
					m_player.setPositionPhys(m_vectMaths.setPosition(m_player.getPosition(), m_col.getCollisionRectNormal(), m_col.getRectOverlap()));
					m_player.setVelocityPhys(m_vectMaths.setResponse(m_player.getVelocityPhys(), m_col.getCollisionRectNormal(), 1.f));
				}
			}
		}

		if (m_col.Intersects(m_aCheckpoint.at(3), m_aRectTrigger.at(10)))  bLapConfirm[3] = true; // Bottom checkpoint
	}
}