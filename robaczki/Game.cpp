#include "Game.h"
#include < stdlib.h >





//private functions
void Game::initVariables()
{
	
	this->window = nullptr;
	this->spawnTimerMax = 30.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxFood = 100;

}

void Game::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "Robaczki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

// Constructors / Destructors

Game::Game() {
	this->initVariables();
	this->initWindow();
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
void Game::playerMovement() {
	if(not this->player.hasFood){
			sf::Vector2f currentPlayerPosition = this->player.shape.getPosition();
			std::cout << "current player x" << currentPlayerPosition.x;
			std::cout << ", current player y" << currentPlayerPosition.y << std::endl;
			sf::Vector2f minDistance = sf::Vector2f(2000.f, 2000.f);
			sf::Vector2f distance;
			sf::Vector2f targetFoodPosition;

			size_t closestFoodIndex = 0; // Index of the closest food

			for (size_t i = 0; i < this->food.size(); i++) {
				targetFoodPosition = this->food[i].shape.getPosition();
				distance = targetFoodPosition - currentPlayerPosition;

				if (std::abs(distance.x) + std::abs(distance.y) < std::abs(minDistance.x) + std::abs(minDistance.y)) {
					minDistance = distance;
					closestFoodIndex = i;
				}
			}

			// Calculate the normalized direction vector towards the closest food 
			sf::Vector2f direction = minDistance / std::sqrt(minDistance.x * minDistance.x + minDistance.y * minDistance.y);

			// Adjust the player's position based on the direction and a predefined speed
			this->player.shape.move(player.movementSpeed * direction);

	}
	else if (this->player.hasFood) {
		sf::Vector2f currentPlayerPosition = this->player.shape.getPosition();
		sf::Vector2f distance;
		sf::Vector2f nestPosition;
		nestPosition = this->nest.shape.getPosition();
		distance = nestPosition - currentPlayerPosition;

		sf::Vector2f direction = distance / std::sqrt(distance.x * distance.x + distance.y * distance.y);

		this->player.shape.move(player.movementSpeed * direction);
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
	this->playerMovement();
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
	this->toolbar.render(this->window);
	this->window->draw(nest.text);
	

	this->window->display();
}
