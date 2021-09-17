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
#include <fstream>
#include <istream>

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
	sf::Vector2f mousePosView;

	//Game objects
	sf::RectangleShape board[10][10];

	//Texture stuff
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	//private functions
	void initVariables();
	void initWindow();
	void initBoard();
	void initTexture();
	void initSprite();
public:
	//constructor
	Game();
	//destructor
	~Game();

	//Accesors
	const bool running() const;

	//Functions
	void update();
	void render();
	void pollEvents();
	void updateMousePosition();
	void onClick();
	void renderBoard();
};

#endif // !GAME_H