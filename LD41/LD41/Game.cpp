#include "Game.h"

std::vector<Game::LevelInfo> Game::levels;


sf::RenderWindow Game::window;
sf::View Game::view;

clock_t Game::t;
float Game::elapsedTime;

bool running = true;

bool playerAlive = true;

Player * p;
GameObject * finish;

sf::Texture deathTex;
sf::Sprite deathSprite;

Level * level;
int levelNumber = 0;


void Game::Start() {



	LevelInfo l = LevelInfo();

	//LEVEL 1
	l.backgroundSpriteDir = "background.png";
	l.musicDir = "test.ogg";
	l.platformPositions = { sf::Vector2f(899.201050 - 320*3, 500), sf::Vector2f(899.201050 - 320*2, 500), sf::Vector2f(899.201050 - 320, 500), sf::Vector2f(899.201050, 500), sf::Vector2f(1939.329834, 500), sf::Vector2f(2998.356201, 500), sf::Vector2f(4037.853027, 500), sf::Vector2f(5095.143066, 500), sf::Vector2f(6141.230469, 500), sf::Vector2f(7180.314453, 500), sf::Vector2f(8249.509766, 500), sf::Vector2f(9282.297852, 500), sf::Vector2f(9810.244141, 500), sf::Vector2f(10847.933594, 500), sf::Vector2f(11369.579102, 500), sf::Vector2f(12441.577148, 500), sf::Vector2f(12948.518555, 500), sf::Vector2f(13477.866211, 500), sf::Vector2f(13985.506836, 500), sf::Vector2f(14970.809570, 500), sf::Vector2f(15464.447266, 500), sf::Vector2f(16439.927734, 500), sf::Vector2f(17032.177734, 500), sf::Vector2f(17562.189453, 500), sf::Vector2f(18075.425781, 500), sf::Vector2f(18623.615234, 500), sf::Vector2f(19684.333984, 500), sf::Vector2f(20743.656250, 500), sf::Vector2f(21250.595703, 500), sf::Vector2f(21765.226563, 500), sf::Vector2f(22285.451172, 500), sf::Vector2f(23304.917969, 500), sf::Vector2f(23862.898438, 500), sf::Vector2f(24832.021484, 500), sf::Vector2f(24832.021484 + 320, 500)
	};
	l.platformSpriteDir = "ground.png";
	l.playerSpriteDir = "player.png";
	l.deathSpriteDir = "death.png";
	l.playerSpeed = 700;

	levels.push_back(l);

	LevelInfo l2 = LevelInfo();

	//LEVEL 2
	l2.backgroundSpriteDir = "background.png";
	l2.musicDir = "level2.ogg";
	l2.platformPositions = { sf::Vector2f(1183.989746 - 320 * 4, 500), sf::Vector2f(1183.989746 - 320*3, 500), sf::Vector2f(1183.989746 - 320 * 2, 500), sf::Vector2f(1183.989746 - 320, 500), sf::Vector2f(1183.989746, 500), sf::Vector2f(1649.457886, 500), sf::Vector2f(2157.623047, 500), sf::Vector2f(2718.190918, 500), sf::Vector2f(3221.455811, 500), sf::Vector2f(3774.510254, 500), sf::Vector2f(4401.128418, 500), sf::Vector2f(4898.967285, 500), sf::Vector2f(5398.906738, 500), sf::Vector2f(6340.668945, 500), sf::Vector2f(6837.106934, 500), sf::Vector2f(7366.454590, 500), sf::Vector2f(7829.983398, 500), sf::Vector2f(8313.818359, 500), sf::Vector2f(8971.301758, 500), sf::Vector2f(9588.874023, 500),
	};
	l2.platformSpriteDir = "ground.png";
	l2.playerSpriteDir = "player.png";
	l2.deathSpriteDir = "death.png";
	l2.playerSpeed = 700;

	levels.push_back(l2);


	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(800, 600)));

	level = new Level(levels[levelNumber].musicDir);
	p = new Player(levels[levelNumber].playerSpriteDir);
	finish = new GameObject("finish.png");
	finish->setPosition(25600, 0);
	
	level->setBackground(levels[levelNumber].backgroundSpriteDir);

	for (int i = 0; i < levels[levelNumber].platformPositions.size(); i++) {
		level->addGameObject(new GameObject(levels[levelNumber].platformSpriteDir), levels[levelNumber].platformPositions[i]);
	}

	p->setPosition(0, 0);

	deathTex.loadFromFile(levels[levelNumber].deathSpriteDir);
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

		if (e.type == sf::Event::KeyPressed) {
			if (e.key.code == sf::Keyboard::Space && !playerAlive) {
				p->setPosition(0, 400);
				p->velocity.y = 0;
				level->restartMusic();
				playerAlive = true;
			}
		}
	}

	p->move(sf::Vector2f(levels[levelNumber].playerSpeed * dt, 0));
	//printf("%f\n", levels[levelNumber].playerSpeed);
	
	p->update(dt);
	level->boundCollisionsWithPlayer(p);
	view.setCenter(sf::Vector2f(p->getPosition().x + 200, 300));

	level->background.setPosition(sf::Vector2f(p->getPosition().x - 200, 0));
	level->update(dt, elapsedTime);

	deathSprite.setPosition(sf::Vector2f(p->getPosition().x - 200, 0));

	if (finish->boundCollision(p).x != 0 || finish->boundCollision(p).y != 0) {
		printf("YOU WIN!");
	}

	window.clear();
	window.setView(view);
	window.draw(level->background);
	window.draw(*p);
	window.draw(*finish);
	level->drawLevel(window);
	if (p->getPosition().y > 700) {
		window.draw(deathSprite);
		playerAlive = false;
	}

	window.display();

}