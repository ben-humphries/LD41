#include "MainMenu.h"



MainMenu::MainMenu()
{

	texture.loadFromFile("res/mainmenu.png");
	sprite.setTexture(texture);

	/*43, 207
	192, 253*/
	sf::IntRect level1Button;
	level1Button.top = 207;
	level1Button.left = 43;
	level1Button.width = 149;
	level1Button.height = 46;

	/*318, 288
	483, 338*/
	sf::IntRect level2Button;
	level2Button.top = 288;
	level2Button.left = 318;
	level2Button.width = 149;
	level2Button.height = 46;

	//606, 210
	sf::IntRect level3Button;
	level3Button.top = 210;
	level3Button.left = 606;
	level3Button.width = 149;
	level3Button.height = 46;

	//37, 395
	sf::IntRect level4Button;
	level4Button.top = 395;
	level4Button.left = 37;
	level4Button.width = 149;
	level4Button.height = 46;

	//605, 396
	sf::IntRect level5Button;
	level5Button.top = 396;
	level5Button.left = 605;
	level5Button.width = 149;
	level5Button.height = 46;

	/*330, 506
	484, 583*/
	sf::IntRect quitButton;
	quitButton.top = 506;
	quitButton.left = 330;
	quitButton.width = 150;
	quitButton.height = 80;

	buttons.push_back(quitButton);
	buttons.push_back(level1Button);
	buttons.push_back(level2Button);
	buttons.push_back(level3Button);
	buttons.push_back(level4Button);
	buttons.push_back(level5Button);
}


MainMenu::~MainMenu()
{
}


int MainMenu::click(int x, int y, sf::RenderWindow & window) {

	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i].top < y &&
			buttons[i].top + buttons[i].height > y &&
			buttons[i].left < x &&
			buttons[i].left + buttons[i].width > x) {

			return i;
		}
	}

	return -1;
}

void MainMenu::showMenu(sf::RenderWindow & window) {

	window.draw(sprite);
}