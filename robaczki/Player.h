#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>

class Player
{
private:
	

	

	void initVariables();
	void initShape();



public:
	float lifespan;
	float movementSpeed;
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Sprite sprite;
	bool hasFood = false;
	//constructor
	Player(float x = 0.f, float y=800.f);
	virtual ~Player();
	
	void update(sf::RenderTarget* target);
	void updateInput();
	void render(sf::RenderTarget* target);
	sf::Vector2f getplayerposition();
};

