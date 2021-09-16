#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



//Class that acts as the game engine

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//private functions
	void initVariables();
	void initWindow();
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
};

#endif // !GAME_H