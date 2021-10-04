#pragma once

#ifndef BOARDSPACE_H
#define BOARDSPACE_H

#include "Unit.h"


class BoardSpace
{
private:
	//Occupying unit
	Unit* occupier;

	//The space's coordinates on the board
	int xCoord;
	int yCoord;

	//The spaces pixel coordinates
	float pixel_x;
	float pixel_y;

	//Graphics
	sf::RectangleShape shape;

	//Game logic
	bool mouseHeld = false;

	//private functions
	


public:
	//Default constructor
	BoardSpace();
	//Parameterised constructor
	BoardSpace(Unit* occupier, int xCoord, int yCoord, float scale);

	//getters
	sf::RectangleShape getShape();
	Unit* getUnitPtr();
	float getPixelX();
	float getPixelY();

	//setters
	void setUnitPtr(Unit* unitPtr);
	void setPixelX(float x);
	void setPixelY(float y);

	//Functions
	void initShape(float scale);
	void changePixelPosition(float x, float y);
	void changeColour(sf::Color colour);
	bool isClicked(sf::Vector2f* mousePosView);
};


#endif // !BOARDSPACE_H