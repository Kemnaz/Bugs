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

void Nest::followMouse()
{
	this->shape.setPosition(sf::Mouse::getPosition().x - this->shape.getLocalBounds().width / 1.5, sf::Mouse::getPosition().y - this->shape.getLocalBounds().height / 1.5);

}

void Nest::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Nest::update()
{

	text.setString("food amount: " + std::to_string(counter));
	if (this->isHeld) {
		followMouse();
	}
}
void Nest::initFont() {

	font.loadFromFile("C:\\Users\\User\\Documents\\Unreal Projects\\Bugs\\robaczki\\mcfont.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(1710, 25);
	text.setString("food amount: " + std::to_string(counter));
}
bool Nest::isMouseOver(sf::RenderWindow* window) {
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;

	float nestPosx = shape.getPosition().x;
	float nestPosY = shape.getPosition().y;

	float nestWidth = shape.getPosition().x + shape.getLocalBounds().width;
	float nestHeight = shape.getPosition().y + shape.getLocalBounds().height;
	if (mouseX > nestPosx && mouseX < nestWidth && mouseY > nestPosY && mouseY < nestHeight) {
		return true;
	}
	return false;
}