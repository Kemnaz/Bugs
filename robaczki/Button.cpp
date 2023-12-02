#include "Button.h"
#include <SFML/Graphics.hpp>
Button::Button()
{
}

// Overloaded constructor
Button::Button(std::string txt, sf::Vector2f size, int charSize) {
	text.setString(txt);
	text.setCharacterSize(charSize);

	button.setSize(size);
	//button.setFillColor(bgColor);
}
void Button::setFont(sf::Font &font) {
	text.setFont(font);
}
void Button::setBackColor(sf::Color color) {
	button.setFillColor(color);
}
//void Button::setTextColor(sf::Color color) {
//	text.setColor(color);
//}


void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);

	float xPos = (pos.x + button.getLocalBounds().width / 2) - 3;
	float yPos = (pos.y + button.getLocalBounds().height / 2) ;

	text.setPosition({ xPos,yPos });
}
void Button::render(sf::RenderTarget* target) {
	target->draw(button);
	target->draw(text);
}
bool Button::isMouseOver(sf::RenderWindow* window) {
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;

	float buttonPosx = button.getPosition().x;
	float buttonPosY = button.getPosition().y;

	float buttonWidth = button.getPosition().x + button.getLocalBounds().width;
	float buttnHeight = button.getPosition().y + button.getLocalBounds().height;
	if (mouseX > buttonPosx && mouseX < buttonWidth && mouseY > buttonPosY && mouseY < buttnHeight) {
		return true;
	}
	return false;
	}

