#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>


class Food
{
private:
		void initShape(const sf::RenderWindow& window);

public:
	sf::CircleShape shape;

	//constructor
	Food(const sf::RenderWindow& window);
	virtual ~Food();

	//functions
	void render(sf::RenderTarget* target);
	void update(sf::RenderTarget* target, sf::Vector2f position);


};

