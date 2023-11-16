#include "Food.h"

void Food::initShape(const sf::RenderWindow& window)
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setRadius(5);
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(200+(rand() % (window.getSize().x -400) - this->shape.getGlobalBounds().width)),
		static_cast<float>(100+(rand() % (window.getSize().y -200) - this->shape.getGlobalBounds().height))));
}


Food::Food(const sf::RenderWindow& window)
{
	
	this->initShape(window);
}

Food::~Food()
{
}

void Food::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Food::update(sf::RenderTarget* target, sf::Vector2f position)
{
	this->shape.setPosition(position+sf::Vector2f(2.5f,2.5f));
}
