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
#include "BoardSpace.h"

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
	static const int mainBoardSize = 10;
	BoardSpace board[mainBoardSize][mainBoardSize];

	static const int sideBoardWidth = 4;
	static const int sideBoardHeight = 10;
	BoardSpace sideBoardBlue[sideBoardWidth][sideBoardHeight];
	BoardSpace sideBoardRed[sideBoardWidth][sideBoardHeight];

	sf::RectangleShape startButton;

	//All units in the game, manually initialised in initUnits()
	/*
	10: 1 Marshall
	9: 1 General
	8: 2 Colonels
	7: 3 Majors
	6: 4 Captains
	5: 4 Lieutenants
	4: 4 Sergeants
	3: 5 Miners
	2: 8 Scouts
	1: 1 Spy
	*/
	Unit blue_marshall, blue_general, blue_colonel_1, blue_colonel_2, blue_major_1, blue_major_2, blue_major_3, blue_captain_1, blue_captain_2, blue_captain_3, blue_captain_4;
	Unit blue_lieutenant_1, blue_lieutenant_2, blue_lieutenant_3, blue_lieutenant_4, blue_sergeant_1, blue_sergeant_2, blue_sergeant_3, blue_sergeant_4;
	Unit blue_miner_1, blue_miner_2, blue_miner_3, blue_miner_4, blue_miner_5, blue_scout_1, blue_scout_2, blue_scout_3, blue_scout_4, blue_scout_5, blue_scout_6, blue_scout_7, blue_scout_8;
	Unit blue_spy, blue_bomb_1, blue_bomb_2, blue_bomb_3, blue_bomb_4, blue_bomb_5, blue_bomb_6, blue_flag;

	Unit red_marshall, red_general, red_colonel_1, red_colonel_2, red_major_1, red_major_2, red_major_3, red_captain_1, red_captain_2, red_captain_3, red_captain_4;
	Unit red_lieutenants_1, red_lieutenants_2, red_lieutenants_3, red_lieutenants_4, red_seargeant_1, red_seargeant_2, red_seargeant_3, red_seargeant_4;
	Unit red_miner_1, red_miner_2, red_miner_3, red_miner_4, red_miner_5, red_scout_1, red_scout_2, red_scout_3, red_scout_4, red_scout_5, red_scout_6, red_scout_7, red_scout_8;
	Unit red_spy, red_bomb_1, red_bomb_2, red_bomb_3, red_bomb_4, red_bomb_5, red_bomb_6, red_flag;

	Unit blockades[8];

	//Texture stuff
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	//Game logic
	BoardSpace* selectedSpace;
	bool unitIsSelected;
	bool setupTime;
	bool mouseHeld;
	

	//private functions
	void initVariables();
	void initWindow();
	void initBoard();
	void initSideBoards();
	void initUnits();
	void spawnBlockades();

	enum direction { left, right, up, down };
	

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
	void clickLogicDuringGame();
	void clickLogicDuringSetup();
	void renderBoard();
	void renderSideBoards();
	void renderStartButton();
	//void renderUnit(int y, int x);
	void moveUnit(BoardSpace* from, BoardSpace* to);
	int validateMove(BoardSpace* from, BoardSpace* to);
	bool validateSetupMove(BoardSpace* to);
	void onClick();
	void battle(BoardSpace* attackerSpace, BoardSpace* defenderSpace);
};

#endif // !GAME_H