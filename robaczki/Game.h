#pragma once

#include <iostream>
#include <vector>

#include "Player.h"
#include "Food.h"
#include "Nest.h"
#include "Button.h"
#include <sstream>
#include <iostream>
#define FRAMERATE 60

// Class for rendering the game

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	sf::RectangleShape menu;
	
	//Player bug;
	std::vector<Player> bug;
	std::vector<Button> buttons;
	std::vector<sf::Text> texts;
	Nest nest;
	sf::Font font;
	sf::Text maxfoodtxt;
	sf::Text respawnfoodtxt;
	sf::Text maxbugstxt;
	//sf::Text text;
	bool endGame;
	int maxBugs;
	float spawnTimerMax;
	float spawnTimer;
	int maxFood;
	std::vector<Food> food;
	void initVariables();
	void initWindow();
	void initMenu();
	void initFont();
public:
	//Constructors /Destructors
	Game();
	virtual ~Game();



	//Functions
	const bool running() const;
	void pollEvents();
	void playerMovement();
	void foodNestCollison();
	void bugNestCollison();
	void spawnBugs();
	void despawnBugs();
	void spawnFood();
	void playerFoodCollision();
	void update();
	void render();
	void textupdate();
};
