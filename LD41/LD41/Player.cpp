#include "Player.h"



Player::Player()
{
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);

	state == Grounded;

}


Player::~Player()
{
}

void Player::update(float dt) {


	if (jumping && state == Grounded) {
		velocity.y = -200;
		//state = Jumping;
	}

	applyGravity(dt);


	this->move(velocity * dt);


	GameObject::update();
}

void Player::applyGravity(float dt) {
	this->acceleration =  sf::Vector2f(0, 1400);
	this->velocity += acceleration * dt;
}

void Player::handleInput(sf::Event e) {

	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			jumping = true;
		}
	}
	else if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			jumping = false;
		}

	}
}
