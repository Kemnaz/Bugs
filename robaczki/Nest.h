#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>
class Nest
{
private:
	void initShape();

public:
	sf::RectangleShape shape;

	//constructor
	Nest(float x = 0.f, float y = 300.f);
	virtual ~Nest();

	//functions
	void render(sf::RenderTarget* target);
	void update(sf::RenderTarget* target, sf::Vector2f position);
};

