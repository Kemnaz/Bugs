#include "Player.h"
#include <iostream>


void Player::initVariables()
{
	this->movementSpeed = 3 + float(rand() % 200)/200;
	lifespan = 60 * 20;
}

void Player::initShape()
{
	if (!texture.loadFromFile("C:\\Users\\User\\Documents\\Unreal Projects\\Bugs\\robaczki\\textures\\ant.png")) {
		std::cout << "Bug texture load failed";
		system("pause");
	}
	sprite.setTexture(texture);
	/*this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(15.f, 15.f));*/


}

Player::Player(float x, float y)
{
	this->initShape();
	this->sprite.setPosition(x, y);
	this->initVariables();

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