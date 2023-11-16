#include "Game.h"






//private functions
void Game::initVariables()
{
	
	this->window = nullptr;
	this->spawnTimerMax = 120.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxFood = 10;

}

void Game::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "Robaczki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}
void Game::initMenu() {
	this->menu.setFillColor(sf::Color::Black);
	this->menu.setSize(sf::Vector2f(220.f, 1080.f));
	this->menu.setPosition(sf::Vector2f(1700.f, 0.f));
}
void Game::initFont()
{
	
}

// Constructors / Destructors

Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initMenu();
	this->nest.initFont();
}
Game::~Game() {
	delete this->window;
}



// Functions
const bool Game::running() const
{
	return this->window->isOpen();
}


void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::foodNestCollison()
{
	for (size_t i = 0; i < this->food.size(); i++) {
		if (this->nest.shape.getGlobalBounds().intersects(this->food[i].shape.getGlobalBounds()))
		{
			nest.counter += 1;
			player.hasFood = false;
			this->food.erase(this->food.begin() + i);

		}
	}
}

void Game::spawnFood()
{
	//timer
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->food.size() < this->maxFood) {
			this->food.push_back(Food(*this->window));
			this->spawnTimer = 0.f;

		}
	}
}

void Game::playerFoodCollision()
{
	//check collision
	for (size_t i = 0; i < this->food.size(); i++) {
		if (this->player.hasFood) {
			this->food[this->player.carriedFood].update(this->window, player.getplayerposition());
		}
		else if (this->player.shape.getGlobalBounds().intersects(this->food[i].shape.getGlobalBounds()) ) 
		{
			//this->food.erase(this->food.begin() + i);
			this->food[i].update(this->window, player.getplayerposition());
			this->player.hasFood=true;
			this->player.carriedFood = i;
		}
	}
}


void Game::update()
{
	this->pollEvents();
	this->foodNestCollison();
	this->spawnFood();
	this->player.update(this->window);
	this->playerFoodCollision();
	this->nest.update();
	
}

void Game::render()
{
	/*
	* -clear old frame
	* -render objects
	* -display frame in window
	* -Renders the game objects
	*/
	

	this->window->clear(sf::Color(160, 82, 45, 0));
	//Draw game objects
	
	this->player.render(this->window);
	this->nest.render(this->window);
	for (auto i : this->food) {
		i.render(this->window);

	}
	this->window->draw(menu);
	this->window->draw(nest.text);
	this->window->display();
}
