#pragma once

#ifndef BOARDSPACE_H
#define BOARDSPACE_H

#include "Unit.h"


class BoardSpace
{
private:
	//Occupying unit
	Unit occupier;

	//The space's coordinates on the board
	int xCoord;
	int yCoord;

	//Graphics
	sf::RectangleShape shape;


public:




	
};


#endif // !BOARDSPACE_H