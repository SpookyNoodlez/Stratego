#pragma once

#ifndef UNIT_H
#define UNIT_H

//Teams for allegience
#define NEUTRAL 0
#define BLUE 1
#define RED 2
//Ranks
#define BLOCKADE -1
#define DEAD 0
#define SPY 1
#define SCOUT 2
#define MINER 3
#define SERGEANT 4
#define LIUTENANT 5
#define CAPTAIN 6
#define MAJOR 7
#define COLONEL 8
#define GENERAL 9
#define MARSHAL 10
#define BOMB 11
#define FLAG 12


struct ArrayCoords {
    int x;
    int y;
};


class Unit {
private:
    struct ArrayCoords location;
    int allegiance;
    int rank;
    int ID;
public:
    //public graveyard space
    const struct ArrayCoords graveYard = { -1,-1 };

    //constructor
    Unit(struct ArrayCoords location, int allegiance, int rank, int id);

    //getters
    int getRank();
    struct ArrayCoords getLocation();

    //setters
    void setRank(int rank);
    void setLocation(struct ArrayCoords newLocation);

    //other
    void die();
};

#endif // !UNIT_H