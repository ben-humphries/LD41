#include "Player.h"

bool jumpEnded = false;

Player::Player(std::string dir)
{
	if (!texture.loadFromFile("player.png")) {
		printf("Could not load player texture");
	}
	sprite.setTexture(texture);
	collider = sprite.getLocalBounds();

	color = sf::Color(255, 255, 255, 255);

	state == Grounded;

}


Player::~Player()
{
}

void Player::update(float dt) {


	applyGravity(dt);


	this->move(velocity * dt);



	GameObject::update();
}

void Player::applyGravity(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumpEnded) {
		this->acceleration = sf::Vector2f(0, 1500);
	}
	else {
		this->acceleration = sf::Vector2f(0, 2500);
	}
	this->velocity += acceleration * dt;
}

void Player::handleInput(sf::Event e) {

	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			printf("%i", state);

			if (state == Grounded && !jumping) {
				velocity.y = -800;
				state = Jumping;
				jumping = true;
				jumpEnded = false;
			}

			printf("sf::Vector2f(%f, 500), ", this->getPosition().x - 64 * 5 / 2 - 100);
		}
	}
	if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			jumpEnded = true;
		}
	}
	
}

sf::Vector2i Player::boundCollision(GameObject * g) {
	sf::Vector2i collision = this->GameObject::boundCollision(g);

	if (collision.y == 1) {
		state = Grounded;
		if (jumping) {
			velocity.y = -800;
			jumping = false;
		}
		else {
			velocity.y = 0;
			jumpEnded = true;
		}
	}
	else if (collision.y == 0 && velocity.y != 0) {
		state = Jumping;
	}
	else if (collision.y == -1 && velocity.y < 0) {
		velocity.y = 0;
		state = Jumping;
	}

	if (collision.x == 1 && velocity.x <= 0 || collision.x == -1 && velocity.x >= 0) {
		velocity.x = 0;
	}

	return collision;
}