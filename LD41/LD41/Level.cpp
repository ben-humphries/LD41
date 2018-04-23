#include "Level.h"



Level::Level(std::string dir)
{
	if (!music.openFromFile(dir)) {
		printf("could not open music file");
	}
	music.setLoop(true);
	music.setVolume(10);
	//music.play();

	if (!font.loadFromFile("res/impact.ttf")) {
		printf("Could not load font");
	}

	percentageText.setFont(font);
	percentageText.setCharacterSize(40);
	percentageText.setStyle(sf::Text::Regular);

	percentageText.setPosition(-100, 100);
	percentageText.setOutlineColor(sf::Color(150, 150, 150, 255));
	percentageText.setOutlineThickness(3);

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

	window.draw(percentageText);

}


void Level::update(float dt, float elapsedTime){
	
	if (elapsedTime > startDelay && !(music.getStatus() == sf::Music::Playing)){
		music.play();
	}

}

void Level::updateText(sf::Vector2f playerPosition, sf::Vector2f finishPosition) {
	std::string text = std::to_string((int)(playerPosition.x / finishPosition.x * 100));
	percentageText.setString(text + "%");
}

void Level::setTextPosition(sf::Vector2f v) {
	percentageText.setPosition(v);
}

void Level::restartMusic() {
	music.play();
}

void Level::stopMusic() {
	music.stop();
}

