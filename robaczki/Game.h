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
	bool endGame;
	Player player;
	Nest nest;


	float spawnTimerMax;
	float spawnTimer;
	int maxFood;
	std::vector<Food> food;
	void initVariables();
	void initWindow();
public:
	//Constructors /Destructors
	Game();
	virtual ~Game();
	


	//Functions
	const bool running() const;
	void pollEvents();
	void foodNestCollison();
	void spawnFood();
	void playerFoodCollision();
	void update();
	void render();
};

