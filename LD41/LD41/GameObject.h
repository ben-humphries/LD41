#pragma once
#include <SFML/Graphics.hpp>


class GameObject : public sf::Transformable , public sf::Drawable
{
public:
	GameObject();
	~GameObject();

	sf::Sprite sprite;
	sf::Texture texture;

	virtual void update();
	

private:

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

