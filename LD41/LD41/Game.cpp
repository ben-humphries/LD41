#include "Game.h"

sf::RenderWindow Game::window;
sf::View Game::view;

clock_t Game::t;
float Game::elapsedTime;

bool running = true;

Player * p;
GameObject * g;
GameObject * g2;

sf::Texture deathTex;
sf::Sprite deathSprite;


Level * level;

sf::Vector2f positions[] = {sf::Vector2f(-278, 500), sf::Vector2f(42, 500), sf::Vector2f(362, 500), sf::Vector2f(682.588135, 500), sf::Vector2f(1591.551514, 500), sf::Vector2f(2500.659180, 500), sf::Vector2f(3410.406738, 500), sf::Vector2f(4325.555664, 500), sf::Vector2f(5249.105957, 500), sf::Vector2f(6153.453125, 500), sf::Vector2f(7037.996094, 500), sf::Vector2f(7942.933594, 500), sf::Vector2f(8388.443359, 500), sf::Vector2f(9286.659180, 500), sf::Vector2f(9736.367188, 500), sf::Vector2f(10662.764648, 500), sf::Vector2f(11087.888672, 500), sf::Vector2f(11539.998047, 500), sf::Vector2f(11973.515625, 500), sf::Vector2f(12879.526367, 500), sf::Vector2f(13299.252930, 500), sf::Vector2f(14240.639648, 500), sf::Vector2f(14668.162109, 500), sf::Vector2f(15104.677734, 500), sf::Vector2f(15540.594727, 500), sf::Vector2f(16029.875977, 500), sf::Vector2f(16933.488281, 500), sf::Vector2f(17883.871094, 500), sf::Vector2f(18267.621094, 500), sf::Vector2f(18705.335938, 500), sf::Vector2f(19132.857422, 500), sf::Vector2f(20059.253906, 500), sf::Vector2f(20502.964844, 500), sf::Vector2f(21422.767578, 500) };

void Game::Start() {


	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(800, 600)));

	level = new Level();
	p = new Player();
	std::string dir = "ground.png";
	
	level->setBackground("background.png");
	for (int i = 0; i < sizeof(positions)/sizeof(sf::Vector2f); i++) {
		level->addGameObject(new GameObject(dir), positions[i]);
	}

	p->setPosition(0, 500);

	deathTex.loadFromFile("death.png");
	deathSprite.setTexture(deathTex);


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

	level->background.setPosition(sf::Vector2f(p->getPosition().x - 400, 0));
	level->update(dt, elapsedTime);

	deathSprite.setPosition(sf::Vector2f(p->getPosition().x - 400, 0));

	window.clear();
	window.setView(view);
	window.draw(level->background);
	window.draw(*p);
	level->drawLevel(window);
	if (p->getPosition().y > 700) {
		window.draw(deathSprite);
	}
	window.display();

}