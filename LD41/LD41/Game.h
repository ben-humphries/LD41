#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"

class Game
{
public:
	
	static void Start();
	static void Update();

	static sf::RenderWindow window;


private:

	static clock_t t;
};

