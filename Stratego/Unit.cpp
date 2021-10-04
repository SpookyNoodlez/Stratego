#include "Unit.h"
#include "iostream"
#include "string"


void Unit::initVariables()
{
}

void Unit::initSprite(const char* texturePath)
{
    if (!this->unitTexture.loadFromFile(texturePath)) {
        std::cout << "Could not load unit texture";
    }
    
    this->unitSprite.setTexture(this->unitTexture);
}

//constructor
Unit::Unit(int allegiance, int rank, char* texturePath)
{
    this->allegiance = allegiance;
    this->rank = rank;

    initSprite(texturePath);
}

Unit::Unit()
{
    this->allegiance = NEUTRAL;
    this->rank = DEAD;

    initSprite("Textures/0_blue.png");
}

//getters
int Unit::getRank()
{
    return this->rank;
}
/*
sf::Sprite Unit::getUnitSprite()
{
    return this->unitSprite;
}
*/


//setters
void Unit::setRank(int rank)
{
    this->rank = rank;
}

void Unit::setAllegiance(int allegiance) {
    this->allegiance = allegiance;
}



//functions
void Unit::die()
{
    this->rank = DEAD;
    this->allegiance = NEUTRAL;
}
