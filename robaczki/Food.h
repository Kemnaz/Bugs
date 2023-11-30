#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>


class Food
{
private:
	//void initShape(const sf::RenderWindow& window);
	void initShape(const sf::RenderWindow& window, float x = 0, float y = 0);

public:


	sf::CircleShape shape;

	//constructor
	//Food(const sf::RenderWindow& window);
	Food(const sf::RenderWindow& window, float height = 0, float width = 0);
	virtual ~Food();

	//functions
	void render(sf::RenderTarget* target);
	void update(sf::RenderTarget* target, sf::Vector2f position);


};
