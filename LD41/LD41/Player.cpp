#include "Player.h"

bool jumpEnded = false;

Player::Player(std::string dir)
{
	if (!texture.loadFromFile(dir)) {
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

	//printf("jumpEnded: %i state: %i\n", jumpEnded, state);


	applyGravity(dt);


	this->move(velocity * dt);



	GameObject::update();
}

void Player::applyGravity(float dt) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (state == Grounded && jumpEnded) {
			jumpEnded = false;
			jumping = true;
			this->velocity.y = -800;
			this->move(0, -5);
			state = Jumping;
		}
		
	}
	else {
		jumpEnded = true;
	}

	if (!jumpEnded) {
		this->acceleration = sf::Vector2f(0, 1500);

	}
	else {
		this->acceleration = sf::Vector2f(0, 3000);
	}

	this->velocity += acceleration * dt;

}

void Player::handleInput(sf::Event e) {

	if (e.type == sf::Event::KeyPressed) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			//printf("%i", state);

			/*if (state == Grounded && !jumping) {
				velocity.y = -800;
				state = Jumping;
				jumping = true;
				jumpEnded = false;
			}*/

			//printf("sf::Vector2f(%f, %f), ", this->getPosition().x - 64 * 5 / 2 - 50, static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * 250 + 250);
		}
	}
	/*if (e.type == sf::Event::KeyReleased) {
		if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::Up) {
			jumpEnded = true;
		}
	}*/
	
}

sf::Vector2i Player::boundCollision(GameObject * g) {
	sf::Vector2i collision = this->GameObject::boundCollision(g);

	if (collision.y == 1) {
		state = Grounded;
		//if (jumping) {
		//	velocity.y = -800;
		//	jumping = false;
		//}
		//else {
			velocity.y = 0;
			//jumpEnded = true;
		//}
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