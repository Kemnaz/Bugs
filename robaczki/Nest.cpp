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

void Nest::update()
{

	text.setString("food amount: " + std::to_string(counter));
	std::to_string(counter);
}
void Nest::initFont() {

	font.loadFromFile("C:\\Users\\User\\Documents\\Unreal Projects\\Bugs\\robaczki\\mcfont.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(1710, 25);
	text.setString("food amount: " + std::to_string(counter));
}