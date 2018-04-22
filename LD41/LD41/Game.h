#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Level.h"

class Game
{
public:

	struct LevelInfo {

		std::vector<sf::Vector2f> platformPositions;
		std::string musicDir;
		std::string playerSpriteDir;
		std::string platformSpriteDir;
		std::string backgroundSpriteDir;
		std::string deathSpriteDir;
		float playerSpeed;
		sf::Vector2f finishPosition;
	};

	static std::vector<LevelInfo> levels;
	
	static void Start();
	static void Update();

	static sf::RenderWindow window;
	static sf::View view;


private:

	static clock_t t;
	static float elapsedTime;
};

