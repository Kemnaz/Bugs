#include "Player.h"
#include <iostream>



void Player::initVariables()
{
	this->movementSpeed = 3 + float(rand() % 200)/200;
	lifespan = 60 * 20;
}

void Player::initShape(sf::Texture texture)
{
	
	sprite.setTexture(texture);


}

Player::Player(float x, float y, sf::Texture texture)
{
	this->initVariables();
	this->initShape(texture);
	this->sprite.setPosition(x, y);
	

}

Player::~Player()
{

}

void Player::update(sf::RenderTarget* target,int nestx)
{
	//Window bounds collision

	this->updateInput();
	if (hasFood) {
		if (sprite.getPosition().x < nestx) {
			sprite.setScale(-1.0f, 1.0f);
		}
		else {
			sprite.setScale(1.0f, 1.0f);
		}
	}
	else {
		if (sprite.getPosition().x < nestx) {
			sprite.setScale(1.0f, 1.0f);
		}
		else {
			sprite.setScale(-1.0f, 1.0f);
		}
	}
	


}

void Player::updateInput()
{
	// Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->sprite.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->sprite.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->sprite.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->sprite.move(0.f, this->movementSpeed);
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

sf::Vector2f Player::getplayerposition()
{
	return this->sprite.getPosition();
}