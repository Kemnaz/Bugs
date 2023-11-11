#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>

class Player
{
private:
	

	float movementSpeed;

	void initVariables();
	void initShape();



public:
	sf::RectangleShape shape;
	bool hasFood = false;
	//constructor
	Player(float x = 0.f, float y=0.f);
	virtual ~Player();
	int carriedFood;
	void update(sf::RenderTarget* target);
	void updateInput();
	void render(sf::RenderTarget* target);
	sf::Vector2f getplayerposition();
};

