#include "Game.h"

sf::RenderWindow Game::window;
sf::View Game::view;

clock_t Game::t;
float Game::elapsedTime;

bool running = true;

Player * p;
GameObject * g;
GameObject * g2;

Level * level;

sf::Vector2f positions[] = {sf::Vector2f(300, 500), sf::Vector2f(757.377686, 500), sf::Vector2f(1617.143066, 500), sf::Vector2f(2495.629883, 500), sf::Vector2f(3411.978271, 500), sf::Vector2f(4332.527344, 500), sf::Vector2f(5212.270508, 500), sf::Vector2f(6126.819336, 500), sf::Vector2f(7018.564453, 500), sf::Vector2f(7438.632813, 500), sf::Vector2f(8351.720703, 500), sf::Vector2f(8792.435547, 500), sf::Vector2f(9730.828125, 500), sf::Vector2f(10170.341797, 500), sf::Vector2f(10642.235352, 500), sf::Vector2f(11087.746094, 500), sf::Vector2f(11975.167969, 500), sf::Vector2f(12398.497070, 500), sf::Vector2f(13308.704102, 500), sf::Vector2f(13753.615234, 500)
};

void Game::Start() {


	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(800, 600)));

	level = new Level();
	p = new Player();
	std::string dir = "ground.png";
	

	for (int i = 0; i < 20; i++) {
		level->addGameObject(new GameObject(dir), positions[i]);
	}

	p->setPosition(0, 0);
	p->collider = sf::FloatRect(0, 0, 16 * 5, 16 * 5);




	t = clock();
	elapsedTime = 0;

	while (running) {
		Update();
	}

}

void Game::Update() {

	//calculate dt
	float dt = ((float)(clock() - t)) / CLOCKS_PER_SEC;
	elapsedTime += dt;
	t = clock();

	sf::Event e;
	while (window.pollEvent(e)) {

		p->handleInput(e);

		if (e.type == sf::Event::Closed) {
			running = false;
		}
	}

	p->move(sf::Vector2f(600 * dt, 0));

	p->update(dt);
	level->boundCollisionsWithPlayer(p);
	view.setCenter(sf::Vector2f(p->getPosition().x, 300));


	window.clear();
	window.setView(view);
	window.draw(*p);
	level->drawLevel(window);
	window.display();

}