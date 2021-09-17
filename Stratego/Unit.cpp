#include "Unit.h"



//constructor
Unit::Unit(ArrayCoords location, int allegiance, int rank, int ID)
{
    this->location = location;
    this->allegiance = allegiance;
    this->rank = rank;
    this->ID = ID;
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
