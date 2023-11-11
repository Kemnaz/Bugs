#include "Nest.h"

void Nest::initShape()
{
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(50.f, 100.f));
}

Nest::Nest(float x, float y)
{
	this->shape.setPosition(x, y);
	this->initShape();
}

Nest::~Nest()
{
}

void Nest::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Nest::update(sf::RenderTarget* target, sf::Vector2f position)
{
}
