#include "Unit.h"







void Unit::initVariables()
{
}

void Unit::initSprite(char* texturePath)
{
    this->unitTexture.loadFromFile(texturePath);
    this->unitSprite.setTexture(this->unitTexture);
}

//constructor
Unit::Unit(int allegiance, int rank, char* texturePath)
{
    this->allegiance = allegiance;
    this->rank = rank;

    initSprite(texturePath);
}

//getters
int Unit::getRank()
{
    return this->rank;
}

ArrayCoords Unit::getLocation()
{
    return this->location;
}

//setters
void Unit::setRank(int rank)
{
    this->rank = rank;
}

void Unit::setLocation(ArrayCoords newLocation)
{
    this->location = newLocation;
}


//functions
void Unit::die()
{
    this->location = this->graveYard;
    this->rank = DEAD;
    this->allegiance = NEUTRAL;
}
