#include "Game.h"
#include < stdlib.h >

Button FoodAmountIncrement("+", { 20,20 }, 10);
Button FoodAmountReduction("-", { 20,20 }, 10);
Button FoodSpawnRateInc("+", { 20,20 }, 10);
Button FoodSpawnRateRed("-", { 20,20 }, 10);
Button MaxBugsInc("+", { 20,20 }, 10);
Button MaxBugsRed("-", { 20,20 }, 10);
//private functions
void Game::initVariables()
{
	
	this->window = nullptr;
	this->spawnTimerMax = 30.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxFood = 5;
	this->maxBugs = 1;
	this->bug.push_back(Player(nest.shape.getPosition().x+20, nest.shape.getPosition().y+30));
}

void Game::initWindow()
{

	this->videoMode.height = 1080;
	this->videoMode.width = 1920;
	this->window = new sf::RenderWindow(this->videoMode, "Robaczki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(FRAMERATE);
}
void Game::initMenu() {
	float x1 = 1750;
	float x2 = 1780;
	float xT = 1710;
	FoodAmountIncrement.setPosition({ x1,220});
	FoodAmountIncrement.setFont(font);
	FoodAmountReduction.setPosition({ x2,220 });
	FoodAmountReduction.setFont(font);
	FoodSpawnRateInc.setPosition({ x1,300 });
	FoodSpawnRateInc.setFont(font);
	FoodSpawnRateRed.setPosition({ x2,300 });
	FoodSpawnRateRed.setFont(font);
	MaxBugsInc.setPosition({ x1,380 });
	MaxBugsInc.setFont(font);
	MaxBugsRed.setPosition({ x2,380 });
	MaxBugsRed.setFont(font);
	buttons.push_back(FoodAmountIncrement);
	buttons.push_back(FoodAmountReduction);
	buttons.push_back(FoodSpawnRateInc);
	buttons.push_back(FoodSpawnRateRed);
	buttons.push_back(MaxBugsInc);
	buttons.push_back(MaxBugsRed);
	respawnfoodtxt.setPosition(xT, 265);
	maxfoodtxt.setPosition(xT, 200);
	maxbugstxt.setPosition(xT, 345);
	texts.push_back(maxfoodtxt);
	texts.push_back(respawnfoodtxt);
	texts.push_back(maxbugstxt);
	this->menu.setFillColor(sf::Color::Black);
	this->menu.setSize(sf::Vector2f(220.f, 1080.f));
	this->menu.setPosition(sf::Vector2f(1700.f, 0.f));
}
void Game::initFont()
{
	font.loadFromFile("C:\\Users\\User\\Documents\\Unreal Projects\\Bugs\\robaczki\\mcfont.ttf");
	for (size_t i = 0; i < texts.size(); i++) {
		texts[i].setCharacterSize(12);
		texts[i].setFont(font);
	}
}

// Constructors / Destructors

Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initMenu();
	this->initFont();
	
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
		case sf::Event::MouseMoved:
			for (size_t j = 0; j < this->buttons.size(); j++) {
				if (buttons[j].isMouseOver(window)) {
					buttons[j].setBackColor(sf::Color::Green);
				}
				else {
					buttons[j].setBackColor(sf::Color::Red);
				}
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (FoodAmountIncrement.isMouseOver(window) ) {
				maxFood++;
			}
			else if (FoodAmountReduction.isMouseOver(window) && maxFood > 0) {
				maxFood--;
			}
			else if (FoodSpawnRateInc.isMouseOver(window) && spawnTimerMax > 5) {
				spawnTimerMax -= 5;
			}
			else if (FoodSpawnRateRed.isMouseOver(window)) {
				spawnTimerMax += 5;
			}
			else if (MaxBugsInc.isMouseOver(window)) {
				maxBugs++;
			}
			else if (MaxBugsRed.isMouseOver(window)) {
				maxBugs--;
			}
			break;
			
			
			
			
			
		}
	}
}
void Game::playerMovement() {
	for (size_t j = 0; j < this->bug.size(); j++) {
		if (!(this->bug[j].hasFood) && this->food.size() > 0) {
			sf::Vector2f currentPlayerPosition = this->bug[j].sprite.getPosition();
			/*std::cout << "current player x" << currentPlayerPosition.x;
			std::cout << ", current player y" << currentPlayerPosition.y << std::endl;*/
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
			this->bug[j].sprite.move(bug[j].movementSpeed * direction);

		}
		else if (this->bug[j].hasFood || this->food.size() == 0) {
			sf::Vector2f currentPlayerPosition = this->bug[j].sprite.getPosition();
			sf::Vector2f distance;
			sf::Vector2f nestPosition;
			nestPosition = this->nest.shape.getPosition();
			distance = nestPosition - currentPlayerPosition;

			sf::Vector2f direction = distance / std::sqrt(distance.x * distance.x + distance.y * distance.y);

			this->bug[j].sprite.move(bug[j].movementSpeed * direction);
		}
	}

}

// unused atm
void Game::foodNestCollison()
{
	for (size_t i = 0; i < this->food.size(); i++) {
		if (this->nest.shape.getGlobalBounds().intersects(this->food[i].shape.getGlobalBounds()))
		{
			nest.counter += 1;
			for (size_t j = 0; j < this->bug.size(); j++) {
				if (this->nest.shape.getGlobalBounds().intersects(this->bug[j].sprite.getGlobalBounds()))
				{
					bug[j].hasFood = false;
				}
			}
			this->food.erase(this->food.begin() + i);

		}
	}
}


void Game::bugNestCollison() {
	for (size_t j = 0; j < this->bug.size(); j++) {
		if (this->nest.shape.getGlobalBounds().intersects(this->bug[j].sprite.getGlobalBounds()) && bug[j].hasFood)
		{
			bug[j].hasFood = false;
			nest.counter += 1;

		}
	}
}

void Game::spawnBugs() {
	if (this->bug.size() < this->maxBugs) {
		if (this->nest.counter > 2) {
			std::cout << "max bugs: " << maxBugs << '\n' << "bug amount: " << this->bug.size() << std::endl;
			this->bug.push_back(Player(nest.shape.getPosition().x + 20, nest.shape.getPosition().y + 30));
			this->nest.counter -= 2;
		}

	}
}
void Game::despawnBugs() {
	for (size_t j = 0; j < this->bug.size(); j++) {
		if (this->bug[j].lifespan > 0) {
			this->bug[j].lifespan -= 1.f;
		}
		else {
			if (this->bug[j].hasFood) {
				this->food.push_back(Food(*this->window, this->bug[j].sprite.getPosition().x, this->bug[j].sprite.getPosition().y));
				this->bug.erase(this->bug.begin() + j);

			}
			else {
				this->bug.erase(this->bug.begin() + j);
			}



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
	for (size_t j = 0; j < this->bug.size(); j++) {
		for (size_t i = 0; i < this->food.size(); i++) {
			if (!(this->bug[j].hasFood) && this->bug[j].sprite.getGlobalBounds().intersects(this->food[i].shape.getGlobalBounds()))
			{
				this->food.erase(this->food.begin() + i);
				this->bug[j].hasFood = true;
			}
		}
	}
}


void Game::textupdate()
{
	texts[0].setString("current max food: " + std::to_string(maxFood));
	float f = float(spawnTimerMax) / float(FRAMERATE);
	std::stringstream stream;
	stream.precision(3);
	stream << std::fixed;
	stream << f;
	std::string str = stream.str();

	texts[1].setString("current respawn rate:\n" + str + " sec.");
	texts[2].setString("current max amount \nof bugs: " + std::to_string(maxBugs));
}

void Game::update()
{
	this->pollEvents();
	//this->foodNestCollison();
	this->bugNestCollison();
	this->spawnBugs();
	this->spawnFood();
	this->despawnBugs();
	this->textupdate();
	

	for (size_t j = 0; j < this->bug.size(); j++) {
		this->bug[j].update(this->window,nest.shape.getPosition().x);
	}

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


	this->window->clear(sf::Color(200, 117, 51, 0));
	//Draw game objects
	for (auto i : this->bug) {
		//i.texture.loadFromFile("C:\\Users\\User\\Documents\\Unreal Projects\\Bugs\\robaczki\\textures\\ant.png");
		i.sprite.setTexture(i.texture);
		i.render(this->window);
	}

	this->nest.render(this->window);
	for (auto i : this->food) {
		i.render(this->window);

	}
	this->window->draw(menu);
	for (auto i : this->buttons) {
		i.render(this->window);

	}
	for (auto i : this->texts) {
		this->window->draw(i);
	}
	//button1.render(window);
	
	this->window->draw(nest.text);

	this->window->display();
}

