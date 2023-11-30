#pragma once

#include <iostream>
#include <vector>

#include "Player.h"
#include "Food.h"
#include "Nest.h"
// Class for rendering the game

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event sfmlEvent;
	sf::RectangleShape menu;
	bool endGame;
	//Player bug;
	std::vector<Player> bug;
	Nest nest;
	sf::Font font;
	sf::Text text;
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
};
