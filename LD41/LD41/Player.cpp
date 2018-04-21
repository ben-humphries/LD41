#include "Player.h"



Player::Player()
{
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);
	sprite.setScale(5, 5);

	state == Grounded;

}


Player::~Player()
{
}

void Player::update(float dt) {


	if (jumping) {
		velocity.y = -1000;
		state = Jumping;
		jumping = false;
	}

	applyGravity(dt);


	this->move(velocity * dt);


	GameObject::update();
}

void Player::applyGravity(float dt) {
	this->acceleration =  sf::Vector2f(0, 2000);
	this->velocity += acceleration * dt;
}

void Player::handleInput(sf::Event e) {

	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			if(state == Grounded)
				jumping = true;
		}
	}
	else if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			//jumping = false;
		}

	}
}

sf::Vector2i Player::boundCollision(GameObject * g) {
	sf::Vector2i collision = this->GameObject::boundCollision(g);

	if (collision.y == 1) {
		state = Grounded;
		velocity.y = 0;
	}
	else if (collision.y == -1 && velocity.y < 0) {
		velocity.y = 0;
	}

	if (collision.x == 1 && velocity.x <= 0 || collision.x == -1 && velocity.x >= 0) {
		velocity.x = 0;
	}

	return collision;
}