#include "GameObject.h"



GameObject::GameObject()
{
	texture.loadFromFile("test.png");
	sprite.setTexture(texture);

}


GameObject::~GameObject()
{
}

void GameObject::update() {

}


void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(sprite, states);
}
