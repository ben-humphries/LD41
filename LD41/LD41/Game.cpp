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
int levelNumber = 1;


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
	l2.platformPositions = { sf::Vector2f(1183.989746 - 320 * 4, 500), sf::Vector2f(1183.989746 - 320*3, 500), sf::Vector2f(1183.989746 - 320 * 2, 500), sf::Vector2f(1183.989746 - 320, 500), sf::Vector2f(1183.989746, 500), sf::Vector2f(1649.457886, 500), sf::Vector2f(2157.623047, 500), sf::Vector2f(2718.190918, 450), sf::Vector2f(3221.455811, 400), sf::Vector2f(3774.510254, 500), sf::Vector2f(4401.128418, 500), sf::Vector2f(4898.967285, 500), sf::Vector2f(5398.906738, 500), sf::Vector2f(6340.668945, 400), sf::Vector2f(6837.106934, 350), sf::Vector2f(7366.454590, 300), sf::Vector2f(7829.983398, 250), sf::Vector2f(8313.818359, 200), sf::Vector2f(8971.301758, 200), sf::Vector2f(9588.874023, 500), sf::Vector2f(10205.869141, 500), sf::Vector2f(10702.309570, 500), sf::Vector2f(11194.546875, 500), sf::Vector2f(11674.180664, 500), sf::Vector2f(12153.814453, 500), sf::Vector2f(12806.395508, 500), sf::Vector2f(13420.466797, 500), sf::Vector2f(13921.805664, 500), sf::Vector2f(14422.445313, 500), sf::Vector2f(15384.511719, 500), sf::Vector2f(15880.950195, 500), sf::Vector2f(16360.253906, 500), sf::Vector2f(16839.921875, 500), sf::Vector2f(17388.675781, 500), sf::Vector2f(17963.566406, 500), sf::Vector2f(18618.736328, 500), sf::Vector2f(19241.742188, 500), sf::Vector2f(19743.083984, 500), sf::Vector2f(20223.447266, 500), sf::Vector2f(20719.193359, 500), sf::Vector2f(21206.550781, 500), sf::Vector2f(21851.933594, 500), sf::Vector2f(22463.750000, 500), sf::Vector2f(22962.294922, 500), sf::Vector2f(23449.650391, 500), sf::Vector2f(24396.394531, 500), sf::Vector2f(24898.433594, 500), sf::Vector2f(25409.566406, 500), sf::Vector2f(25872.449219, 500), sf::Vector2f(26372.392578, 500), sf::Vector2f(26993.306641, 500), sf::Vector2f(27633.792969, 500), sf::Vector2f(28284.072266, 500), sf::Vector2f(28284.072266 + 320, 500), sf::Vector2f(28284.072266 + 320* 2, 500), sf::Vector2f(28284.072266 + 320 * 3, 500), sf::Vector2f(29558.054688, 500), sf::Vector2f(30051.003906, 500), sf::Vector2f(30574.718750, 500), sf::Vector2f(31041.800781, 500), sf::Vector2f(31566.361328, 500), sf::Vector2f(32157.757813, 500), sf::Vector2f(32782.863281, 500), sf::Vector2f(33291.195313, 500), sf::Vector2f(33798.828125, 500), sf::Vector2f(34763.050781, 500), sf::Vector2f(35235.027344, 500), sf::Vector2f(35722.382813, 500), sf::Vector2f(36210.437500, 500), sf::Vector2f(36688.703125, 500), sf::Vector2f(37334.082031, 500), sf::Vector2f(37986.453125, 500), sf::Vector2f(38596.871094, 500),
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

	p->setPosition(0, -200);

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

	level->boundCollisionsWithPlayer(p);


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
	view.setCenter(sf::Vector2f(p->getPosition().x + 200, 300));

	level->background.setPosition(sf::Vector2f(p->getPosition().x - 200, 0));
	level->update(dt, elapsedTime);

	deathSprite.setPosition(sf::Vector2f(p->getPosition().x - 200, 0));

	if (finish->boundCollision(p).x != 0 || finish->boundCollision(p).y != 0) {
		//printf("YOU WIN!");
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