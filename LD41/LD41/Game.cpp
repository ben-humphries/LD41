#include "Game.h"

sf::RenderWindow Game::window;

clock_t Game::t;

bool running = true;

Player * p;
GameObject * g;

void Game::Start() {


	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	p = new Player();
	std::string dir = "ground.png";
	g = new GameObject(dir);
	g->setPosition(sf::Vector2f(0, 550));

	p->collider = sf::FloatRect(0, 0, 16 * 5, 16 * 5);




	while (running) {
		Update();
	}

}

void Game::Update() {

	//calculate dt
	float dt = ((float)(clock() - t)) / CLOCKS_PER_SEC;
	t = clock();

	sf::Event e;
	while (window.pollEvent(e)) {

		p->handleInput(e);

		if (e.type == sf::Event::Closed) {
			running = false;
		}
	}

	p->boundCollision(g);

	p->update(dt);


	window.clear();
	window.draw(*p);
	window.draw(*g);
	window.display();

}
