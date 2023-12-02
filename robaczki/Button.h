#pragma once
#include <SFML/Graphics.hpp>
class Button
{
private:
	sf::RectangleShape button;
	sf::Text text;
public:

	Button();

	// Overloaded constructor
	Button(std::string txt, sf::Vector2f size, int charSize);
	void setFont(sf::Font& font);
	void setBackColor(sf::Color color);
	//void setTextColor(sf::Color color);
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderTarget* target);
	bool isMouseOver(sf::RenderWindow* window);
};

