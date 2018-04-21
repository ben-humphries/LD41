#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
public:
	
	static void Start();
	static void Update();

	static sf::RenderWindow window;

};

