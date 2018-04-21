#include "Level.h"



Level::Level()
{
	if (!music.openFromFile("test.ogg")) {
		printf("could not open music file");
	}
	music.setLoop(true);
	music.setVolume(5);
	//music.play();

}


Level::~Level()
{
}

void Level::setBackground(std::string dir) {
	
	if (!backgroundTexture.loadFromFile(dir)) {
		printf("could not load background texture");
	}
	background.setTexture(backgroundTexture);
}


void Level::addGameObject(GameObject * g) {
	this->gameObjects.push_back(g);
}

void Level::addGameObject(GameObject * g, sf::Vector2f position) {
	g->setPosition(position);
	this->gameObjects.push_back(g);
}

void Level::boundCollisionsWithPlayer(Player * p) {
	for (int i = 0; i < gameObjects.size(); i++) {
		p->boundCollision(gameObjects.at(i));
	}
}

void Level::drawLevel(sf::RenderWindow & window) {
	for (int i = 0; i < gameObjects.size(); i++) {
		window.draw(*gameObjects.at(i));
	}

}


void Level::update(float dt, float elapsedTime){
	
	if (elapsedTime > startDelay && !(music.getStatus() == sf::Music::Playing)){
		music.play();
	}
}

