#include "ToolBar.h"

void ToolBar::initShape()
{
	shape.setFillColor(sf::Color::Black);
	shape.setSize(sf::Vector2f(220.f, 1080.f));
	shape.setPosition(sf::Vector2f(1700.f, 0.f));
}

ToolBar::ToolBar()
{
	this->initShape();
}

void ToolBar::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
