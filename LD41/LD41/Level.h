#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "SFML/Audio.hpp"

class Level : public sf::Drawable
{
public:
	Level();
	~Level();

	std::vector<GameObject*> gameObjects;

	void addGameObject(GameObject * g);
	void addGameObject(GameObject * g, sf::Vector2f position);

	void boundCollisionsWithPlayer(Player * p);

	void drawLevel(sf::RenderWindow & window);

private:

	sf::Music music;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
};

