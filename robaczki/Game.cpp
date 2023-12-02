#include "Game.h"
#include < stdlib.h >

Button FoodAmountInc("+", { 20,20 }, 10);
Button FoodAmountRed("-", { 20,20 }, 10);
Button FoodSpawnRateInc("+", { 20,20 }, 10);
Button FoodSpawnRateRed("-", { 20,20 }, 10);
Button MaxBugsInc("+", { 20,20 }, 10);
Button MaxBugsRed("-", { 20,20 }, 10);
Button NewBugFoodThresholdInc("+", { 20,20 }, 10);
Button NewBugFoodThresholdRed("-", { 20,20 }, 10);
Button SpawnBug("SpawnBug", { 80,40 }, 10);
//private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->spawnTimerMax = 30.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxFood = 5;
	this->maxBugs = 1;
	this->foodrequired = 2;
	this->bug.push_back(Player(nest.shape.getPosition().x+20, nest.shape.getPosition().y+30));
	this->bug[0].sprite.setTexture(resources.bugtexture);
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
	FoodAmountInc.setPosition({ x1,220});
	FoodAmountRed.setPosition({ x2,220 });
	FoodSpawnRateInc.setPosition({ x1,300 });
	FoodSpawnRateRed.setPosition({ x2,300 });
	MaxBugsInc.setPosition({ x1,380 });
	MaxBugsRed.setPosition({ x2,380 });
	NewBugFoodThresholdInc.setPosition({ x1,460 });
	NewBugFoodThresholdRed.setPosition({ x2,460 });
	buttons.push_back(FoodAmountInc);
	buttons.push_back(FoodAmountRed);
	buttons.push_back(FoodSpawnRateInc);
	buttons.push_back(FoodSpawnRateRed);
	buttons.push_back(MaxBugsInc);
	buttons.push_back(MaxBugsRed);
	buttons.push_back(NewBugFoodThresholdInc);
	buttons.push_back(NewBugFoodThresholdRed);
	
	respawnfoodtxt.setPosition(xT, 265);
	maxfoodtxt.setPosition(xT, 200);
	maxbugstxt.setPosition(xT, 345);
	bugfoodthreshold.setPosition(xT, 425);
	texts.push_back(maxfoodtxt);
	texts.push_back(respawnfoodtxt);
	texts.push_back(maxbugstxt);
	texts.push_back(bugfoodthreshold);
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
	for (size_t i = 0; i < buttons.size(); i++) {
		buttons[i].setFont(font);
	}
}

// Constructors / Destructors

Game::Game() {
	this->resources.initTextures();
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
			if (nest.isMouseOver(window)&&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				nest.isHeld = true;
				//nest.shape.setPosition(sf::Mouse::getPosition().x - nest.shape.getLocalBounds().width / 2, sf::Mouse::getPosition().y - nest.shape.getLocalBounds().height / 2);
			}
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				nest.isHeld = false;
			}

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
			if (FoodAmountInc.isMouseOver(window) ) {
				maxFood++;
			}
			else if (FoodAmountRed.isMouseOver(window) && maxFood > 0) {
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
			else if (MaxBugsRed.isMouseOver(window) && maxBugs>1) {
				maxBugs--;
			}
			else if (NewBugFoodThresholdInc.isMouseOver(window)) {
				foodrequired++;
			}
			else if (NewBugFoodThresholdRed.isMouseOver(window)&& foodrequired>1) {
				foodrequired--;
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
		if (this->nest.counter >= foodrequired) {
			std::cout << "max bugs: " << maxBugs << '\n' << "bug amount: " << this->bug.size() << std::endl;
			this->bug.push_back(Player(nest.shape.getPosition().x + 20, nest.shape.getPosition().y + 30));
			this->nest.counter -= foodrequired;
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
	texts[3].setString("food required to \nspawn a new bug: " + std::to_string(foodrequired));
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
		i.sprite.setTexture(resources.bugtexture);
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

