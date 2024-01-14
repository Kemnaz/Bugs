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
Button LifeSpanInc("+", { 20,20 }, 10);
Button LifeSpanRed("-", { 20,20 }, 10);
Button SpeedInc("+", { 20,20 }, 10);
Button SpeedRed("-", { 20,20 }, 10);
Button SpawnBug("+", { 80,40 }, 10);
Button DoubleFoodAmountInc("x", { 20,20 }, 10);
Button DoubleFoodAmountRed("x", { 20,20 }, 10);

//private functions
void Game::initVariables(int maxbee, int maxfood, int lifelen)
{
	this->window = nullptr;
	this->spawnTimerMax = 5.f;
	this->spawnTimer = this->spawnTimerMax;
	this->lifelength = lifelen;
	this->mvmspeed = 3;
	this->maxFood = maxfood;
	this->maxBugs = maxbee;
	this->foodrequired = 2;
	this->nest.sprite.setTexture(resources.beehive);
	this->nest.sprite.setPosition(vwidth / 2 - 100, vheight / 2 - 40);
	this->bug.push_back(Insect(nest.sprite.getPosition().x+20, nest.sprite.getPosition().y+30,resources.bugtexture,mvmspeed,lifelength));
	this->bug[0].sprite.setTexture(resources.bugtexture);
}

void Game::initWindow(int width, int height)
{

	this->videoMode.height = height;
	this->videoMode.width = width;
	this->window = new sf::RenderWindow(this->videoMode, "Robaczki", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(FRAMERATE);
}
void Game::initMenu() {
	//float x1 = 1750;
	float x1 = window->getSize().x - 170;
	//float x2 = 1780;
	float x2 = x1+30;
	//float xT = 1725;
	float xT = window->getSize().x-195;
	float prev_butt_y = 200;
	float prev_description_text = prev_butt_y - 40;

	SpawnBug.setPosition({ x2-45,prev_butt_y - 110});


	DoubleFoodAmountInc.setPosition({ x1-30,prev_butt_y });
	DoubleFoodAmountRed.setPosition({ x2 + 30,prev_butt_y });

	FoodAmountInc.setPosition({ x1,prev_butt_y });
	FoodAmountRed.setPosition({ x2,prev_butt_y });
	prev_butt_y += 80;
	FoodSpawnRateInc.setPosition({ x1,prev_butt_y });
	FoodSpawnRateRed.setPosition({ x2,prev_butt_y });
	prev_butt_y += 80;
	MaxBugsInc.setPosition({ x1,prev_butt_y });
	MaxBugsRed.setPosition({ x2,prev_butt_y });
	prev_butt_y += 80;
	NewBugFoodThresholdInc.setPosition({ x1,prev_butt_y });
	NewBugFoodThresholdRed.setPosition({ x2,prev_butt_y });
	prev_butt_y += 80;
	LifeSpanInc.setPosition({ x1,prev_butt_y });
	LifeSpanRed.setPosition({ x2,prev_butt_y });
	prev_butt_y += 80;
	SpeedInc.setPosition({ x1,prev_butt_y });
	SpeedRed.setPosition({ x2,prev_butt_y });
	prev_butt_y += 80;
	buttons.push_back(FoodAmountInc);
	buttons.push_back(FoodAmountRed);
	buttons.push_back(FoodSpawnRateInc);
	buttons.push_back(FoodSpawnRateRed);
	buttons.push_back(MaxBugsInc);
	buttons.push_back(MaxBugsRed);
	buttons.push_back(NewBugFoodThresholdInc);
	buttons.push_back(NewBugFoodThresholdRed);
	buttons.push_back(LifeSpanInc);
	buttons.push_back(LifeSpanRed);
	buttons.push_back(SpeedInc);
	buttons.push_back(SpeedRed);
	//test
	buttons.push_back(SpawnBug);
	buttons.push_back(DoubleFoodAmountInc);
	buttons.push_back(DoubleFoodAmountRed);


	currentbugsamounttxt.setPosition({ xT,prev_description_text - 100 });
	currentbugsamounttxt.setString("Bugs: " + std::to_string(size(bug)));
	foodamount.setPosition(nest.sprite.getPosition().x, nest.sprite.getPosition().y);
	foodamount.setString("food amount: " + std::to_string(nest.counter));
	foodamount.setCharacterSize(12);

	maxfoodtxt.setPosition(xT, prev_description_text);
	prev_description_text += 80;
	respawnfoodtxt.setPosition(xT, prev_description_text);
	prev_description_text += 80;
	maxbugstxt.setPosition(xT, prev_description_text);
	prev_description_text += 80;
	bugfoodthreshold.setPosition(xT, prev_description_text);
	prev_description_text += 80;
	bugLifeSpan.setPosition(xT, prev_description_text);
	prev_description_text += 80;
	bugSpeed.setPosition(xT, prev_description_text);
	texts.push_back(maxfoodtxt);
	texts.push_back(respawnfoodtxt);
	texts.push_back(maxbugstxt);
	texts.push_back(bugfoodthreshold);
	texts.push_back(bugLifeSpan);
	texts.push_back(bugSpeed);
	//texts.push_back(currentbugsamounttxt);
	this->menu.setFillColor(sf::Color::Black);
	this->menu.setSize(sf::Vector2f(220.f, 1080.f));
	//this->menu.setPosition(sf::Vector2f(1700.f, 0.f));
	this->menu.setPosition(sf::Vector2f(window->getSize().x-220.f, 0.f));

}
void Game::initFont()
{
	font.loadFromFile("mcfont.ttf");
	for (size_t i = 0; i < texts.size(); i++) {
		texts[i].setCharacterSize(12);
		texts[i].setFont(font);
	}
	foodamount.setFont(font);
	currentbugsamounttxt.setFont(font);
	for (size_t i = 0; i < buttons.size(); i++) {
		buttons[i].setFont(font);
	}

}

// Constructors / Destructors

Game::Game(int maxbee = 5, int maxfood = 150, int lifelen = 20, int width=1920, int height=1080) {
	vwidth = width;
	vheight = height;
	this->resources.initTextures();
	this->initVariables(maxbee, maxfood, lifelen);
	this->initWindow(width,height);
	this->initMenu();
	this->initFont();
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
			else if (LifeSpanInc.isMouseOver(window) && lifelength < 100) {
				lifelength++;
			}
			else if (LifeSpanRed.isMouseOver(window) && lifelength > 1) {
				lifelength--;
			}
			else if (SpeedInc.isMouseOver(window) && mvmspeed < 10) {
				mvmspeed++;
			}
			else if (SpeedRed.isMouseOver(window) && mvmspeed > 1) {
				mvmspeed--;
			}
			else if (SpawnBug.isMouseOver(window)) {
				this->bug.push_back(Insect(nest.sprite.getPosition().x + 20, nest.sprite.getPosition().y + 30, resources.bugtexture, mvmspeed, lifelength));
			}
			else if (DoubleFoodAmountInc.isMouseOver(window)) {
				maxFood+=10;
			}
			else if (DoubleFoodAmountRed.isMouseOver(window) && maxFood > 10) {
				maxFood-=10;
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
			sf::Vector2f adjustment = { +1, -4 };

			size_t closestFoodIndex = 0; // Index of the closest food

			for (size_t i = 0; i < this->food.size(); i++) {
				targetFoodPosition = this->food[i].shape.getPosition();
				distance = targetFoodPosition + adjustment- currentPlayerPosition;

				if (std::abs(distance.x) + std::abs(distance.y) < std::abs(minDistance.x) + std::abs(minDistance.y)) {
					minDistance = distance;
					closestFoodIndex = i;
				}
			}

			// Calculate the normalized direction vector towards the closest food 
			sf::Vector2f direction = minDistance / std::sqrt(minDistance.x * minDistance.x + minDistance.y * minDistance.y);

			// Adjust the player's position based on the direction and a predefined speed
			this->bug[j].sprite.move(bug[j].movementSpeed * direction);
			if (bug[j].sprite.getPosition().x < food[closestFoodIndex].shape.getPosition().x) {
				bug[j].sprite.setScale(-1.0f, 1.0f);
			}
			else {
				bug[j].sprite.setScale(1.0f, 1.0f);
			}
			
				
			
		}
		else if (this->bug[j].hasFood || this->food.size() == 0) {
			sf::Vector2f currentPlayerPosition = this->bug[j].sprite.getPosition();
			sf::Vector2f distance;
			sf::Vector2f nestPosition;
			sf::Vector2f adjustment = { 20, 20 };
			nestPosition = this->nest.sprite.getPosition();
			distance = nestPosition+adjustment - currentPlayerPosition;

			sf::Vector2f direction = distance / std::sqrt(distance.x * distance.x + distance.y * distance.y);

			this->bug[j].sprite.move(bug[j].movementSpeed * direction);
			if (bug[j].sprite.getPosition().x < nest.sprite.getPosition().x) {
				bug[j].sprite.setScale(-1.0f, 1.0f);
			}
			else {
				bug[j].sprite.setScale(1.0f, 1.0f);
			}
		}
	}

}

void Game::foodNestCollison()
{
	for (size_t i = 0; i < this->food.size(); i++) {
		if (this->nest.sprite.getGlobalBounds().intersects(this->food[i].shape.getGlobalBounds()))
		{
			nest.counter += 1;
			for (size_t j = 0; j < this->bug.size(); j++) {
				if (this->nest.sprite.getGlobalBounds().intersects(this->bug[j].sprite.getGlobalBounds()))
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
		/*if (this->nest.sprite.getGlobalBounds().intersects(this->bug[j].sprite.getGlobalBounds()) && bug[j].hasFood)
		{
			bug[j].hasFood = false;
			nest.counter += 1;

		}*/
		if (this->nest.sprite.getGlobalBounds().intersects(this->bug[j].sprite.getGlobalBounds()) && bug[j].hasFood)
		{
			bug[j].hasFood = false;
			nest.counter += 1;

		}
	}
}

void Game::spawnBugs() {
	if (this->bug.size() < this->maxBugs) {
		if (this->nest.counter >= foodrequired) {
			//std::cout << "max bugs: " << maxBugs << '\n' << "bug amount: " << this->bug.size() << std::endl;
			this->bug.push_back(Insect(nest.sprite.getPosition().x + 20, nest.sprite.getPosition().y + 30,resources.bugtexture, mvmspeed, lifelength));
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
	foodamount.setString("food accumulated: " + std::to_string(nest.counter));
	foodamount.setPosition(nest.sprite.getPosition().x -30, nest.sprite.getPosition().y-5);
	texts[0].setString("current max \nfood: " + std::to_string(maxFood));
	float f = float(spawnTimerMax) / float(FRAMERATE);
	std::stringstream stream;
	stream.precision(3);
	stream << std::fixed;
	stream << f;
	std::string str = stream.str();

	texts[1].setString("current respawn rate:\n" + str + " sec.");
	texts[2].setString("current max amount \nof bugs: " + std::to_string(maxBugs));
	texts[3].setString("food required to \nspawn a new bug: " + std::to_string(foodrequired));
	texts[4].setString("new bug life \nlength (in seconds): " + std::to_string(lifelength));
	texts[5].setString("new bug average \nspeed: " + std::to_string(int(mvmspeed)));
	currentbugsamounttxt.setString("Bugs: " + std::to_string(size(bug)));
	//currentbugsamounttxt.setString("Bugs: " + std::to_string(size(bug)));

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
		this->bug[j].update(this->window,nest.sprite.getPosition().x);
	}

	this->playerFoodCollision();
	this->nest.update(window);
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

	
	for (auto i : this->food) {
		i.render(this->window);

	}
	this->nest.render(this->window);
	this->window->draw(menu);
	for (auto i : this->buttons) {
		i.render(this->window);

	}
	for (auto i : this->texts) {
		this->window->draw(i);
	}
	this->window->draw(foodamount);
	this->window->draw(currentbugsamounttxt);

	this->window->display();
}

