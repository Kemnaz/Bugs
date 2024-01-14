#include "Food.h"

void Food::initShape(const sf::RenderWindow& window, float x, float  y)
{
	int randomcolor = float(rand() % 3);
	switch (randomcolor) {
	case 0:
		this->shape.setFillColor(sf::Color::Red);
		break;
	case 1:
		this->shape.setFillColor(sf::Color::Green);
		break;
	case 2:
		this->shape.setFillColor(sf::Color::Yellow);
		break;
	}
	//this->shape.setFillColor(sf::Color::Green);
	this->shape.setRadius(5);
	/*if (x == 0 && y == 0) {
		this->shape.setPosition(sf::Vector2f(
			static_cast<float>(200 + (rand() % (window.getSize().x - 500) - this->shape.getGlobalBounds().width)),
			static_cast<float>(100 + (rand() % (window.getSize().y - 200) - this->shape.getGlobalBounds().height))));
	}*/
	if (x == 0 && y == 0) {
		this->shape.setPosition(sf::Vector2f(
			static_cast<float>(20+ (rand() % (window.getSize().x - 250) - this->shape.getGlobalBounds().width)),
			static_cast<float>(20+ (rand() % (window.getSize().y - 50) - this->shape.getGlobalBounds().height))));
	}
	else {
		this->shape.setPosition(x, y);
	}

}


Food::Food(const sf::RenderWindow& window, float height, float width)
{

	this->initShape(window, height, width);
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
	this->shape.setPosition(position + sf::Vector2f(2.5f, 2.5f));
}