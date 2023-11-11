#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 5.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(25.f, 25.f));
}

Player::Player(float x,float y)
{
	this->shape.setPosition(x, y);
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

void Player::update(sf::RenderTarget* target)
{
	//Window bounds collision

	this->updateInput();



	
}

void Player::updateInput()
{
	// Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->shape.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

sf::Vector2f Player::getplayerposition()
{
	return this->shape.getPosition();
}
