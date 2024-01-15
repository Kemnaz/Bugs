#include "Insect.h"
#include <iostream>



void Insect::initVariables(float speed,int lifespan)
{
	this->movementSpeed = speed + float(rand() % 200)/200;
	this->lifespan = 60 * lifespan;
}

void Insect::initShape(sf::Texture texture)
{
	
	sprite.setTexture(texture);


}

float Insect::returnLifespan() {
	return this->lifespan;
}

Insect::Insect(float x, float y, sf::Texture texture, float speed, int lifespan)
{
	this->initVariables(speed, lifespan);
	this->initShape(texture);
	this->sprite.setPosition(x, y);
	

}

Insect::~Insect()
{

}

void Insect::update(sf::RenderTarget* target,int nestx)
{
	//Window bounds collision

	//this->updateInput();
	/*if (hasFood) {
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
	}*/
	


}

void Insect::updateInput()
{
	// Keyboard input
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
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
	}*/
}

void Insect::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

sf::Vector2f Insect::getplayerposition()
{
	return this->sprite.getPosition();
}