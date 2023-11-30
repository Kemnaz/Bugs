#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>
class Nest
{
private:
	void initShape();

public:
	int counter = 0;
	sf::RectangleShape shape;

	sf::Font font;
	sf::Text text;

	//constructor
	Nest(float x = 0.f, float y = 700.f);
	virtual ~Nest();

	//functions
	void render(sf::RenderTarget* target);
	void update();
	void initFont();
};
