#include "Game.h"

std::vector<Game::LevelInfo> Game::levels;


sf::RenderWindow Game::window;
sf::View Game::view;

MainMenu * menu;

clock_t Game::t;
float Game::elapsedTime;

bool running = true;
bool showMenu = true;
bool playerAlive = true;
bool playerFinished = false;

Player * p;
GameObject * finish;

sf::Texture deathTex;
sf::Sprite deathSprite;

sf::Texture winTex;
sf::Sprite winSprite;

Level * level;
int Game::levelNumber = 0;


void Game::Start() {

	menu = new MainMenu(); 

	winTex.loadFromFile("res/win.png");
	winSprite.setTexture(winTex);
	winSprite.setPosition(0, 0);

	LevelInfo l = LevelInfo();

	//LEVEL 1
	l.backgroundSpriteDir = "res/background.png";
	l.musicDir = "res/test.ogg";
	l.platformPositions = { sf::Vector2f(899.201050 - 320*3, 500), sf::Vector2f(899.201050 - 320*2, 500), sf::Vector2f(899.201050 - 320, 500), sf::Vector2f(899.201050, 500), sf::Vector2f(1939.329834, 500), sf::Vector2f(2998.356201, 500), sf::Vector2f(4037.853027, 500), sf::Vector2f(5095.143066, 500), sf::Vector2f(6141.230469, 500), sf::Vector2f(7180.314453, 500), sf::Vector2f(8249.509766, 500), sf::Vector2f(9282.297852, 500), sf::Vector2f(9810.244141, 500), sf::Vector2f(10847.933594, 500), sf::Vector2f(11369.579102, 500), sf::Vector2f(12441.577148, 500), sf::Vector2f(12948.518555, 500), sf::Vector2f(13477.866211, 500), sf::Vector2f(13985.506836, 500), sf::Vector2f(14970.809570, 500), sf::Vector2f(15464.447266, 500), sf::Vector2f(16539.927734, 500), sf::Vector2f(17032.177734, 500), sf::Vector2f(17562.189453, 500), sf::Vector2f(18075.425781, 500), sf::Vector2f(18623.615234, 500), sf::Vector2f(19684.333984, 500), sf::Vector2f(20743.656250, 500), sf::Vector2f(21250.595703, 500), sf::Vector2f(21765.226563, 500), sf::Vector2f(22285.451172, 500), sf::Vector2f(23304.917969, 500), sf::Vector2f(23862.898438, 500), sf::Vector2f(24832.021484, 500), sf::Vector2f(24832.021484 + 320, 500)
	};
	l.platformSpriteDir = "res/ground.png";
	l.playerSpriteDir = "res/player.png";
	l.deathSpriteDir = "res/death.png";
	l.playerSpeed = 700;
	l.finishPosition = sf::Vector2f(25600, 0);

	levels.push_back(l);


	//LEVEL 2
	l.backgroundSpriteDir = "res/background2.png";
	l.musicDir = "res/level2.ogg";
	l.platformPositions = { sf::Vector2f(1183.989746 - 320 * 4, 500), sf::Vector2f(1183.989746 - 320*3, 500), sf::Vector2f(1183.989746 - 320 * 2, 500), sf::Vector2f(1183.989746 - 320, 500), sf::Vector2f(1183.989746, 500), sf::Vector2f(1649.457886, 500), sf::Vector2f(2157.623047, 500), sf::Vector2f(2718.190918, 450), sf::Vector2f(3221.455811, 400), sf::Vector2f(3774.510254, 500), sf::Vector2f(4401.128418, 500), sf::Vector2f(4898.967285, 500), sf::Vector2f(5398.906738, 500), sf::Vector2f(6340.668945, 400), sf::Vector2f(6837.106934, 350), sf::Vector2f(7366.454590, 300), sf::Vector2f(7829.983398, 250), sf::Vector2f(8313.818359, 200), sf::Vector2f(8971.301758, 200), sf::Vector2f(9588.874023, 500), sf::Vector2f(10205.869141, 500), sf::Vector2f(10702.309570, 500), sf::Vector2f(11194.546875, 500), sf::Vector2f(11674.180664, 500), sf::Vector2f(12153.814453, 500), sf::Vector2f(12806.395508, 500), sf::Vector2f(13420.466797, 500), sf::Vector2f(13921.805664, 500), sf::Vector2f(14422.445313, 500), sf::Vector2f(15384.511719, 500), sf::Vector2f(15880.950195, 500), sf::Vector2f(16360.253906, 500), sf::Vector2f(16839.921875, 500), sf::Vector2f(17388.675781, 500), sf::Vector2f(17963.566406, 500), sf::Vector2f(18618.736328, 500), sf::Vector2f(19241.742188, 500), sf::Vector2f(19743.083984, 500), sf::Vector2f(20223.447266, 500), sf::Vector2f(20719.193359, 500), sf::Vector2f(21206.550781, 500), sf::Vector2f(21851.933594, 500), sf::Vector2f(22463.750000, 500), sf::Vector2f(22962.294922, 500), sf::Vector2f(23449.650391, 500), sf::Vector2f(24396.394531, 500), sf::Vector2f(24898.433594, 500), sf::Vector2f(25409.566406, 500), sf::Vector2f(25872.449219, 500), sf::Vector2f(26372.392578, 500), sf::Vector2f(26993.306641, 500), sf::Vector2f(27633.792969, 500), sf::Vector2f(28284.072266, 500), sf::Vector2f(28284.072266 + 320, 500), sf::Vector2f(28284.072266 + 320* 2, 500), sf::Vector2f(28284.072266 + 320 * 3, 500), sf::Vector2f(29558.054688, 500), sf::Vector2f(30051.003906, 500), sf::Vector2f(30574.718750, 500), sf::Vector2f(31041.800781, 500), sf::Vector2f(31566.361328, 500), sf::Vector2f(32157.757813, 500), sf::Vector2f(32782.863281, 500), sf::Vector2f(33291.195313, 500), sf::Vector2f(33798.828125, 500), sf::Vector2f(34763.050781, 500), sf::Vector2f(35235.027344, 500), sf::Vector2f(35722.382813, 500), sf::Vector2f(36210.437500, 500), sf::Vector2f(36688.703125, 500), sf::Vector2f(37334.082031, 500), sf::Vector2f(37986.453125, 500), sf::Vector2f(38596.871094, 500),
	};
	l.platformSpriteDir = "res/ground2.png";
	l.playerSpriteDir = "res/player2.png";
	l.deathSpriteDir = "res/death.png";
	l.playerSpeed = 700;
	l.finishPosition = sf::Vector2f(39000, 0);

	levels.push_back(l);

	//LEVEL 3
	l.backgroundSpriteDir = "res/background3.png";
	l.musicDir = "res/level3.ogg";
	l.platformPositions = { sf::Vector2f(1156.085205 - 320 * 4, 500), sf::Vector2f(1156.085205 - 320*3, 500), sf::Vector2f(1156.085205 - 320 * 2, 500), sf::Vector2f(1156.085205 - 320, 500), sf::Vector2f(1156.085205, 500), sf::Vector2f(1613.853271, 500), sf::Vector2f(2441.895508, 500),  sf::Vector2f(3727.705811 - 320, 500), sf::Vector2f(3727.705811, 500), sf::Vector2f(4201.000488, 500), sf::Vector2f(5039.133789, 500),  sf::Vector2f(6303.684570 - 320, 500), sf::Vector2f(6303.684570, 500), sf::Vector2f(7255.950195, 500), sf::Vector2f(7933.738281, 500), sf::Vector2f(8414.771484, 500), sf::Vector2f(9221.395508, 500), sf::Vector2f(9705.230469, 500), sf::Vector2f(10191.165039, 500), sf::Vector2f(10670.097656, 500), sf::Vector2f(11463.417969, 500), sf::Vector2f(12124.400391, 500), sf::Vector2f(12625.038086, 500), sf::Vector2f(13108.170898, 500), sf::Vector2f(13566.098633, 500), sf::Vector2f(14071.638672, 500), sf::Vector2f(14519.063477, 500), sf::Vector2f(15027.405273, 500), sf::Vector2f(15481.831055, 500), sf::Vector2f(15995.071289, 500), sf::Vector2f(16314.097656, 500), sf::Vector2f(16646.929688, 500), sf::Vector2f(17301.400391, 500), sf::Vector2f(17904.826172, 500), sf::Vector2f(18392.185547, 500), sf::Vector2f(19244.541016, 500), sf::Vector2f(19737.494141, 500), sf::Vector2f(20538.804688, 500), sf::Vector2f(20996.800781, 500), };
	l.platformSpriteDir = "res/ground3.png";
	l.playerSpriteDir = "res/player3.png";
	l.deathSpriteDir = "res/death.png";
	l.playerSpeed = 700;
	l.finishPosition = sf::Vector2f(21400.800781, 0);

	levels.push_back(l);

	//LEVEL 4
	l.backgroundSpriteDir = "res/background4.png";
	l.musicDir = "res/level4.ogg";
	l.platformPositions = { sf::Vector2f(1398.572510 - 320*5, 350.187683),sf::Vector2f(1398.572510 - 320*4, 350.187683),sf::Vector2f(1398.572510 - 320*3, 350.187683), sf::Vector2f(1398.572510 - 320*2, 350.187683), sf::Vector2f(1398.572510 -320, 350.187683),sf::Vector2f(1398.572510, 350.187683), sf::Vector2f(2162.919434, 434.537811), sf::Vector2f(2929.365967, 378.995636), sf::Vector2f(3693.712646, 471.311066), sf::Vector2f(4421.148438, 437.751404), sf::Vector2f(5171.057617, 421.980957), sf::Vector2f(5939.171875, 402.543732), sf::Vector2f(6686.980469, 484.394348), sf::Vector2f(7107.797363, 473.425995), sf::Vector2f(7505.507813, 461.990723), sf::Vector2f(8293.927734, 376.116211), sf::Vector2f(8630.721680, 300), sf::Vector2f(9758.736328, 456.575226), sf::Vector2f(10881.849609 - 320, 427.030243),sf::Vector2f(10881.849609, 427.030243), sf::Vector2f(11288.663086, 395.599243), sf::Vector2f(12087.585938, 352.247681), sf::Vector2f(12850.098633, 363.710449), sf::Vector2f(13667.923828, 378.995636), sf::Vector2f(14443.740234, 471.311066), sf::Vector2f(15214.655273, 437.751404), sf::Vector2f(15935.855469, 421.980957), sf::Vector2f(16701.132813, 402.543732), sf::Vector2f(17477.267578, 484.394348), sf::Vector2f(17842.259766, 473.425995), sf::Vector2f(18240.816406, 461.990723), sf::Vector2f(19036.529297, 376.116211), sf::Vector2f(19396.626953, 478.841522),sf::Vector2f(20523.068359 - 320, 456.575226), sf::Vector2f(20523.068359, 456.575226),sf::Vector2f(21608.255859 - 320, 427.030243), sf::Vector2f(21608.255859, 427.030243), sf::Vector2f(22034.779297, 395.599243), sf::Vector2f(22827.701172, 250.312820), sf::Vector2f(23626.910156, 390.896332), sf::Vector2f(23942.257813, 298.326050), sf::Vector2f(24728.181641, 452.185120), sf::Vector2f(25473.550781, 396.252319), sf::Vector2f(25839.941406, 369.968262), sf::Vector2f(26602.095703, 337.572876), sf::Vector2f(27375.433594, 473.990601), sf::Vector2f(28122.205078, 455.710022), sf::Vector2f(28476.011719, 436.651184), sf::Vector2f(28875.964844, 293.527039), sf::Vector2f(29655.593750, 464.735870), sf::Vector2f(30001.707031, 427.625366), sf::Vector2f(30779.937500, 378.383728), sf::Vector2f(31163.808594, 325.998718), sf::Vector2f(32293.748047, 500), sf::Vector2f(32660.839844, 500), sf::Vector2f(33492.210938, 500), sf::Vector2f(33819.445313, 500), };
	l.platformSpriteDir = "res/ground4.png";
	l.playerSpriteDir = "res/player4.png";
	l.deathSpriteDir = "res/death.png";
	l.playerSpeed = 700;
	l.finishPosition = sf::Vector2f(34500, 0);

	levels.push_back(l);

	//LEVEL 5
	l.backgroundSpriteDir = "res/background5.png";
	l.musicDir = "res/level5.ogg";
	l.platformPositions = { sf::Vector2f(1219.384277 - 320*4, 250.312820),sf::Vector2f(1219.384277 - 320*3, 250.312820),sf::Vector2f(1219.384277 - 320*2, 250.312820), sf::Vector2f(1219.384277 - 320, 250.312820),sf::Vector2f(1219.384277, 250.312820), sf::Vector2f(1805.243530, 390.896332), sf::Vector2f(2394.602539, 298.326050), sf::Vector2f(2922.365723, 452.185120), sf::Vector2f(3750.407959, 396.252319), sf::Vector2f(4315.418457, 369.968262), sf::Vector2f(4893.779785, 337.572876), sf::Vector2f(5826.439941, 473.990601), sf::Vector2f(6276.665039, 455.710022), sf::Vector2f(6833.320313, 436.651184), sf::Vector2f(7384.374023, 293.527039), sf::Vector2f(8130.782227, 464.735870), sf::Vector2f(9062.742188, 427.625366), sf::Vector2f(9643.904297, 378.383728), sf::Vector2f(10226.466797, 325.998718), sf::Vector2f(10756.514648, 253.746140), sf::Vector2f(11290.063477, 272.850739), sf::Vector2f(11892.231445, 341.113007), sf::Vector2f(12608.531250, 286.828217), sf::Vector2f(13305.924805, 291.474670), sf::Vector2f(13854.177734, 497.131256), sf::Vector2f(14720.319336, 361.423065), sf::Vector2f(15248.265625, 279.770813), sf::Vector2f(15810.522461, 251.167328), sf::Vector2f(16347.330078, 252.227844), sf::Vector2f(17045.851563, 344.470032), sf::Vector2f(18028.255859, 382.915741), sf::Vector2f(18595.322266, 392), sf::Vector2f(18916.970703, 392), sf::Vector2f(19249.099609, 392), sf::Vector2f(19731.560547, 390.326050), sf::Vector2f(20591.603516, 452.185120), sf::Vector2f(21171.257813, 396.252319), sf::Vector2f(21978.855469, 369.968262), sf::Vector2f(22548.019531, 337.572876), sf::Vector2f(23092.013672, 473.990601), sf::Vector2f(24072.306641, 455.), sf::Vector2f(24397.443359, 455),sf::Vector2f(26139.916016 - 320*3, 250.312820),sf::Vector2f(26139.916016 - 320*2, 250.312820),sf::Vector2f(26139.916016 - 320, 250.312820),sf::Vector2f(26139.916016, 250.312820), sf::Vector2f(26461.556641, 390.896332), sf::Vector2f(27018.833984, 298.326050), sf::Vector2f(27553.041016, 452.185120), sf::Vector2f(28337.564453, 396.252319), sf::Vector2f(28966.162109, 369.968262), sf::Vector2f(29508.757813, 337.572876), sf::Vector2f(30378.585938, 473.990601), sf::Vector2f(30961.734375, 455.710022), sf::Vector2f(31487.546875, 436.651184), sf::Vector2f(32039.929688, 293.527039), sf::Vector2f(32756.628906, 464.735870), sf::Vector2f(33725.746094, 427.625366), sf::Vector2f(34265.542969, 378.383728), };
	l.platformSpriteDir = "res/ground5.png";
	l.playerSpriteDir = "res/player5.png";
	l.deathSpriteDir = "res/death.png";
	l.playerSpeed = 700;
	l.finishPosition = sf::Vector2f(34800, 0);

	levels.push_back(l);

	window.create(sf::VideoMode(800, 600, 32), "LD41", sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	view = sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(800, 600)));

	level = new Level(levels[levelNumber].musicDir);
	p = new Player(levels[levelNumber].playerSpriteDir);
	finish = new GameObject("res/finish.png");
	finish->setPosition(levels[levelNumber].finishPosition);
	
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

	if (!showMenu) {

		level->boundCollisionsWithPlayer(p);
	}

	sf::Event e;
	while (window.pollEvent(e)) {

		p->handleInput(e);

		if (e.type == sf::Event::Closed) {
			running = false;
		}

		if (showMenu) {
			if (e.type == sf::Event::MouseButtonPressed) {
				int click = menu->click(e.mouseButton.x, e.mouseButton.y, window);


				if (click == -1) {

				}
				else if (click == 0) {
					running = false;
				}
				else {
					LoadLevel(click - 1);
					playerAlive = true;
					showMenu = false;
					playerFinished = false;
				}
			}
		}

		if (e.type == sf::Event::KeyPressed) {
			if (e.key.code == sf::Keyboard::Space) {
				if (!playerAlive) {
					p->setPosition(0, 0);
					p->velocity.y = 0;
					level->restartMusic();
					playerAlive = true;
				}
				if (playerFinished) {
					if (levelNumber < 4) {
						level->stopMusic();
						LoadLevel(levelNumber + 1);
						playerFinished = false;
					}
					else {
						view.setCenter(400, 300);
						level->stopMusic();
						showMenu = true;
					}
				}
			}
			else if (e.key.code == sf::Keyboard::Escape) {
				view.setCenter(400, 300);
				level->stopMusic();
				showMenu = true;
			}
		}
	}
	if (!showMenu) {
		p->move(sf::Vector2f(levels[levelNumber].playerSpeed * dt, 0));
		//printf("%f\n", levels[levelNumber].playerSpeed);

		p->update(dt);
		view.setCenter(sf::Vector2f(p->getPosition().x + 200, 300));

		deathSprite.setPosition(sf::Vector2f(p->getPosition().x - 200, 0));


		if (p->getPosition().y > 700) {
			playerAlive = false;
			level->setTextPosition(sf::Vector2f(deathSprite.getPosition().x + 400 - 20, deathSprite.getPosition().y + 300));
		}
		else {
			level->updateText(p->getPosition(), levels[levelNumber].finishPosition);
			level->setTextPosition(sf::Vector2f(p->getPosition().x + 80, p->getPosition().y - 50));

		}

		level->background.setPosition(sf::Vector2f(p->getPosition().x - 200, 0));
		level->update(dt, elapsedTime);


		if (!playerFinished) {
			window.clear();
			window.setView(view);
			window.draw(level->background);
			window.draw(*p);
			window.draw(*finish);
			level->drawLevel(window);
			if (!playerAlive) {
				window.draw(deathSprite);
			}
		}
		else if (playerFinished) {

			view.setCenter(400, 300);
			level->background.setPosition(0, 0);
			window.clear();
			window.setView(view);
			window.draw(level->background);
			window.draw(winSprite);
		}

		window.display();

		if (finish->boundCollision(p).x != 0 || finish->boundCollision(p).y != 0) {
			playerFinished = true;
		}
	}
	else {

		window.clear();
		window.setView(view);
		menu->showMenu(window);
		window.display();
	}

}


void Game::LoadLevel(int levelNumber) {
	
	Game::levelNumber = levelNumber;
	level = new Level(levels[levelNumber].musicDir);
	p = new Player(levels[levelNumber].playerSpriteDir);
	finish = new GameObject("res/finish.png");
	finish->setPosition(levels[levelNumber].finishPosition);

	level->setBackground(levels[levelNumber].backgroundSpriteDir);

	for (int i = 0; i < levels[levelNumber].platformPositions.size(); i++) {
		level->addGameObject(new GameObject(levels[levelNumber].platformSpriteDir), levels[levelNumber].platformPositions[i]);
	}

	p->setPosition(0, -200);

	deathTex.loadFromFile(levels[levelNumber].deathSpriteDir);
	deathSprite.setTexture(deathTex);


	t = clock();
	elapsedTime = 0;
}