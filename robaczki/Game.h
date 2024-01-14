#pragma once

#include <iostream>
#include <vector>

#include "Insect.h"
#include "Food.h"
#include "Nest.h"
#include "Button.h"
#include "Resources.h"
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
	std::vector<Insect> bug;
	std::vector<Button> buttons;
	std::vector<sf::Text> texts;
	Nest nest;
	sf::Font font;
	sf::Text foodamount;
	sf::Text maxfoodtxt;
	sf::Text respawnfoodtxt;
	sf::Text maxbugstxt;
	sf::Text bugfoodthreshold;
	sf::Text bugLifeSpan;
	sf::Text bugSpeed;
	sf::Text currentbugsamounttxt;
	Resources resources;
	//sf::Text text;
	int vwidth;
	int vheight;
	int lifelength;
	float mvmspeed;
	bool endGame;
	int foodrequired;
	int maxBugs;
	float spawnTimerMax;
	float spawnTimer;
	int maxFood;
	std::vector<Food> food;
	void initVariables(int maxbee, int maxfood, int lifelen);
	void initWindow(int width, int height);
	void initMenu();
	void initFont();

public:
	//Constructors /Destructors
	Game(int maxbee, int maxfood, int lifelen,int width, int height);
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
	//void settings(int maxbee, int maxfood, int spawnspeed);
};
