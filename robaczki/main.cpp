#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include <random>


int main() { 
	
	srand(time(NULL));
	// Init game engine 
	Game game;
	//game loop
	while (game.running()) {
		//Event polling
		

		//Update
		game.update();
		//Render
		game.render();
		


	}



	return 0;
}