#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>

class Player
{
private:




	void initVariables();
	void initShape(sf::Texture);



public:
	float lifespan;
	float movementSpeed;
	sf::RectangleShape shape;
	//sf::Texture texture;
	//sf::Texture bugtexture;
	sf::Sprite sprite;
	bool hasFood = false;
	//constructor
	Player(float x, float y, sf::Texture);
	virtual ~Player();

	void update(sf::RenderTarget* target,int nestx);
	void updateInput();
	void render(sf::RenderTarget* target);
	sf::Vector2f getplayerposition();

};
