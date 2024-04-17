#include "Nest.h"

void Nest::initShape()
{
	/*this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(50.f, 100.f));*/
}

Nest::Nest(float x, float y)
{
	this->sprite.setPosition(x, y);
	this->initShape();
}

Nest::~Nest()
{
}

void Nest::followMouse(sf::RenderWindow* window)
{
	if ( sf::Mouse::getPosition(*window).x < window->getSize().x - 400 && sf::Mouse::getPosition(*window).x > 200 && sf::Mouse::getPosition(*window).y > 50 && sf::Mouse::getPosition(*window).y < window->getSize().y-50) {
		this->sprite.setPosition(sf::Mouse::getPosition(*window).x - this->sprite.getLocalBounds().width / 1.5, sf::Mouse::getPosition(*window).y - this->sprite.getLocalBounds().height / 1.5);

	}
	
}

void Nest::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

void Nest::update(sf::RenderWindow* window)
{

	/*text.setString("food amount: " + std::to_string(counter));*/
	if (this->isHeld) {
		followMouse(window);
	}
}

bool Nest::isMouseOver(sf::RenderWindow* window) {
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;

	float nestPosx = sprite.getPosition().x;
	float nestPosY = sprite.getPosition().y;

	float nestWidth = sprite.getPosition().x + sprite.getLocalBounds().width;
	float nestHeight = sprite.getPosition().y + sprite.getLocalBounds().height;
	if (mouseX > nestPosx && mouseX < nestWidth && mouseY > nestPosY && mouseY < nestHeight) {
		return true;
	}
	return false;
}