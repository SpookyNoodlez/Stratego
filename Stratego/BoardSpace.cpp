#include "BoardSpace.h"


//default constuctor
BoardSpace::BoardSpace()
{
	initShape(1.f);
	this->setUnitPtr(nullptr);
}

//getters
sf::RectangleShape BoardSpace::getShape()
{
	return this->shape;
}

Unit* BoardSpace::getUnitPtr()
{
	return this->occupier;
}

float BoardSpace::getPixelX()
{
	return this->pixel_x;
}

float BoardSpace::getPixelY()
{
	return this->pixel_y;
}

int BoardSpace::getX()
{
	return this->xCoord;
}

int BoardSpace::getY()
{
	return this->yCoord;
}



//setters
void BoardSpace::setUnitPtr(Unit* unitPtr)
{
	this->occupier = unitPtr;
}

void BoardSpace::setPixelX(float x)
{
	this->pixel_x = x;
}

void BoardSpace::setPixelY(float y)
{
	this->pixel_y = y;
}

void BoardSpace::setX(int x)
{
	this->xCoord = x;
}

void BoardSpace::setY(int y)
{
	this->yCoord = y;
}



//functions
BoardSpace::BoardSpace(Unit* occupier, int xCoord, int yCoord, float scale)
{
	this->occupier = occupier;
	this->xCoord = xCoord;
	this->yCoord = yCoord;

	initShape(scale);
}


void BoardSpace::changePixelPosition(float x, float y)
{
	this->shape.setPosition(x, y);
}

void BoardSpace::changeColour(sf::Color colour)
{
	this->shape.setFillColor(colour);
}

bool BoardSpace::isClicked(sf::Vector2f* mousePosView)
{
	if (this->mouseHeld == false) {
		this->mouseHeld = true;

		if (this->shape.getGlobalBounds().contains(*mousePosView)) {
			return true;
		}
	}
	else {
		this->mouseHeld = false; //Hold check not working
	}
	
	return false;
}

void BoardSpace::initShape(float scale)
{
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setScale(sf::Vector2f(scale, scale));
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(2.f);
}