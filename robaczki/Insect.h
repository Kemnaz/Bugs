#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class Insect
{
private:




	void initVariables(float speed, int lifespan);
	void initShape(sf::Texture);



public:
	int lifespan;
	float movementSpeed;
	sf::RectangleShape shape;
	
	sf::Sprite sprite;
	bool hasFood = false;
	//constructor
	Insect(float x, float y, sf::Texture, float speed, int lifespan);
	virtual ~Insect();

	void update(sf::RenderTarget* target,int nestx);
	void updateInput();
	void render(sf::RenderTarget* target);
	float returnLifespan();
	sf::Vector2f getplayerposition();

};
