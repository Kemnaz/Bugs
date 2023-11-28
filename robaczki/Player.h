#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>

class Player
{
private:
	

	

	void initVariables();
	void initShape();



public:
	float movementSpeed;
	sf::RectangleShape shape;
	bool hasFood = false;
	//constructor
	Player(float x = 0.f, float y=500.f);
	virtual ~Player();
	int carriedFood;
	void update(sf::RenderTarget* target);
	void updateInput();
	void render(sf::RenderTarget* target);
	sf::Vector2f getplayerposition();
};

