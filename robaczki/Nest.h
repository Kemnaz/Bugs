#pragma once
#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>
class Nest
{
private:
	void initShape();

public:
	bool isHeld;
	int counter = 0;
	sf::RectangleShape shape;

	sf::Font font;
	sf::Text text;

	//constructor
	Nest(float x = 900.f, float y = 450.f);
	virtual ~Nest();

	//functions
	void followMouse();
	void render(sf::RenderTarget* target);
	void update();
	void initFont();
	bool isMouseOver(sf::RenderWindow* window);
};
