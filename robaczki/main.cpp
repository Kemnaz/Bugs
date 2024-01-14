#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include <random>
#include <string>

int maxbee;
int maxfood;
int lifelength;

// function to validate integer input within a specified range
int getValidInput(int minValue, int maxValue) {
    int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail() || input < minValue || input > maxValue) {
            // clear input buffer to restore cin to a usable state
            std::cin.clear(); 
            // ignore last input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number between " << minValue << " and " << maxValue << ": ";
        }
        else {
            break;
        }
    }
    return input;
}

// function to validate yes/no input
bool getYesNoInput() {
    std::string input;
    while (true) {
        std::cin >> input;
        if (input == "Y" || input == "y" || input == "yes" || input == "N" || input == "n" || input == "no") {
            break;
        }
        else {
            std::cout << "Invalid input. Please enter 'Y' or 'N': ";
        }
    }
    return (input == "Y" || input == "y" || input == "yes");
}

int main() {
    bool restart = true;
    srand(time(NULL));
    char choice;
    int width = 1920, height = 1080;

    while (true) {
        std::cout << "Enter 'd' for default window size or 's' for specified size: ";
        std::cin >> choice;

        if (choice == 'd' || choice == 'D') {
            std::cout << "Using default window size." << std::endl;
            break;
        }
        else if (choice == 's' || choice == 'S') {
            std::cout << "Enter the width of the window (800:1920): ";
            width = getValidInput(800, 1920);
            std::cout << "Enter the height of the window (650:1080): ";
            height = getValidInput(650, 1080);
            std::cout << "Using specified window size - Width: " << width << ", Height: " << height << "." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 'd' or 's'." << std::endl;
        }
    }

    // Game loop
    do {

        // User's choice of initial game state
        int option;

        std::cout << "List of settings:\n Default:\n 1) 20 bees, 400 maximum food, 20 seconds of life.\n 2) 40 bees, 100 maximum food, 10 seconds of life.  \n 3) Manual settings \n 4) Determine all parameters in the simulation\nChoice: ";
        option = getValidInput(1, 4);

        switch (option) {
        case 1:
            maxbee = 20;
            maxfood = 400;
            lifelength = 20;
            break;
        case 2:
            maxbee = 40;
            maxfood = 100;
            lifelength = 10;
            break;
        case 3:
            std::cout << "Set max amount of bugs (1:80): ";
            maxbee = getValidInput(1, 80);
            std::cout << "Set max amount of food (1:500): ";
            maxfood = getValidInput(1, 500);
            std::cout << "Set life length of bugs in seconds (5:60): ";
            lifelength = getValidInput(5, 60);
            break;
        case 4:
            maxbee = 0;
            maxfood = 0;
            lifelength = 1;
            break;
        default:
            break;
        }

        Game game(maxbee, maxfood, lifelength, width, height);

        while (game.running()) {
            game.update();
            game.render();
        }

        std::string run = "";
        do {
            std::cout << "Run again? [Y/N]: ";
            run = getYesNoInput() ? "Y" : "N";
        } while (!(run == "Y" || run == "N"));
        restart = (run == "Y");

    } while (restart);

    return 0;
}
