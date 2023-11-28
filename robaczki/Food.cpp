#include "Food.h"

void Food::initShape(const sf::RenderWindow& window, float x, float  y)
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setRadius(3);
	if (x == 0 && y == 0) {
		this->shape.setPosition(sf::Vector2f(
				static_cast<float>(200+(rand() % (window.getSize().x -1500) - this->shape.getGlobalBounds().width)),
				static_cast<float>(100+(rand() % (window.getSize().y -500) - this->shape.getGlobalBounds().height))));
	}
	else {
		this->shape.setPosition(x, y);
	}
	
}


Food::Food(const sf::RenderWindow& window,float height,float width)
{
	
	this->initShape(window,height,width);
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
