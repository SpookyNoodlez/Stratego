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


struct Space {
    int x;
    int y;
};

const struct Space graveYard = { -1,-1 };


class Unit {
private:
    struct Space Location;
    int Allegiance;
    int Rank;
    int ID;
    const struct Space graveYard = { -1,-1 };
public:
    //constructor
    Unit(struct Space location, int allegiance, int rank, int id) {
        Location = location;
        Allegiance = allegiance;
        Rank = rank;
        ID = id;
    }
    //getters
    int getRank() {
        return Rank;
    }
    struct Space getLocation() {
        return Location;
    }
    //setters
    void setRank(int rank) {
        Rank = rank;
    }
    void setLocation(struct Space newLocation) {
        Location = newLocation;
    }
    //other
    void die() {
        Location = graveYard;
        Rank = DEAD;
        Allegiance = NEUTRAL;
    }
};

#endif // !UNIT_H