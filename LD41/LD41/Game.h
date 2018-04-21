#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Level.h"

class Game
{
public:
	
	static void Start();
	static void Update();

	static sf::RenderWindow window;
	static sf::View view;


private:

	static clock_t t;
	static float elapsedTime;
};

