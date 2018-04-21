#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "SFML/Audio.hpp"

class Level
{
public:



	Level(std::string dir);
	~Level();

	std::vector<GameObject*> gameObjects;

	void addGameObject(GameObject * g);
	void addGameObject(GameObject * g, sf::Vector2f position);

	void setBackground(std::string dir);
	sf::Sprite background;

	void boundCollisionsWithPlayer(Player * p);

	void drawLevel(sf::RenderWindow & window);

	void update(float dt, float elapsedTime);

	void restartMusic();

private:

	sf::Music music;

	sf::Texture backgroundTexture;

	float startDelay = 0;

	
};

