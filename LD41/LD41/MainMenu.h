#pragma once
#include "SFML/Graphics.hpp"

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	sf::Texture texture;
	sf::Sprite sprite;


	std::vector<sf::IntRect> buttons;

	int click(int x, int y, sf::RenderWindow & window);

	void showMenu(sf::RenderWindow & window);


};

