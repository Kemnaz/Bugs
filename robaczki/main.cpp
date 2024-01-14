#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include <random>
#include <string>

int maxbee;
int maxfood;
int lifelength;
int windowsizex;
int windowsizey;

int main() {
	bool restart = true;
	srand(time(NULL));
	
	//game loop
	do {
		
		// creating game object
		

		// user's choice of initial game state
		int option;
		
		std::cout << "List of settings:\n Default:\n 1) 20 bees, 400 maximum food, 20 second of life.\n 2) 60 bees, 100 maximum food, 10 second of life.  \n 0) Manual settings \n Choice: ";
		std::cin >> option;
		switch (option) {
		case 1:
			maxbee = 20;
			maxfood = 400;
			lifelength = 20;
			break;
		case 2:
			maxbee = 60;
			maxfood = 100;
			lifelength = 10;
			break;
		case 3:
			std::cout << "Set max amount of bugs: ";
			std::cin >> maxbee;
			std::cout << "Set max amount of food: ";
			std::cin >> maxfood;
			std::cout << "Set life length of bugs in seconds: ";
			std::cin >> lifelength;
			
			break;
		}

		Game game(maxbee,maxfood, lifelength);
		//game.settings(maxbee, maxfood, spawnspeed);
		while (game.running()) {


			//Update all objects
			game.update();
			//Render visuals
			game.render();



		}
		std::string run = "";
		do{
			std::cout << "run again? [Y/N]: ";
			std::cin >> run;
		} while (!(run == "Y" || run == "y" || run == "yes" || run == "N" || run == "n" || run == "no"));
		if (run == "N" || run == "n" || run == "no") {
			restart = false;
		}
		else {
			restart = true;
		}
		
	} while (restart);
	


	return 0;
}