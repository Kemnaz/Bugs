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
	//sf::RectangleShape shape;
	sf::Sprite sprite;

	sf::Font font;
	sf::Text text;

	//constructor
	Nest(float x = 900.f, float y = 450.f);
	virtual ~Nest();


	//functions
	void followMouse(sf::RenderWindow* window);
	void render(sf::RenderTarget* target);
	void update(sf::RenderWindow* window);
	bool isMouseOver(sf::RenderWindow* window);
};
