#include "Game.h"

sf::RenderWindow Game::window;

bool running = true;

GameObject g;

void Game::Start() {


	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	while (running) {
		Update();
	}

	g = GameObject();
}

void Game::Update() {

	g.update();


	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			running = false;
		}
	}

	window.clear();
	window.draw(g);
	window.display();

}
