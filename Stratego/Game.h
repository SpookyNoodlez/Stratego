#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "Unit.h"

//Class that acts as the game engine

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Vector2i mousePosWindow;

	//Game objects
	sf::RectangleShape boardSpace;

	//Texture stuff
	sf::Texture background;

	//private functions
	void initVariables();
	void initWindow();
	void initBoardSpace();
public:
	//constructor
	Game();
	~Game();

	//Accesors
	const bool running() const;

	//Functions
	void update();
	void render();
	void pollEvents();
	void updateMousePosition();
};

#endif // !GAME_H