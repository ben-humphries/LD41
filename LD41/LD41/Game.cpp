#include "Game.h"

sf::RenderWindow Game::window;

clock_t Game::t;

bool running = true;

Player p;

void Game::Start() {


	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	while (running) {
		Update();
	}

	p = Player();
}

void Game::Update() {

	//calculate dt
	float dt = ((float)(clock() - t)) / CLOCKS_PER_SEC;
	t = clock();

	sf::Event e;
	while (window.pollEvent(e)) {

		p.handleInput(e);

		if (e.type == sf::Event::Closed) {
			running = false;
		}
	}


	p.update(dt);


	window.clear();
	window.draw(p);
	window.display();

}
