#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float dt);
	void handleInput(sf::Event e);

	bool jumping;

	enum State {Grounded, Jumping};
	State state;

	sf::Vector2f acceleration, velocity;

private:

	void applyGravity(float dt);
};

