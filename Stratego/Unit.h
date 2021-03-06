//#pragma once

#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


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
#define LIEUTENANT 5
#define CAPTAIN 6
#define MAJOR 7
#define COLONEL 8
#define GENERAL 9
#define MARSHAL 10
#define BOMB 11
#define FLAG 12


class Unit {
private:
    int allegiance;
    int rank;
    bool hidden;

    sf::Texture unitTexture;
    sf::Texture hiddenTexture;
    sf::Texture highResTexture;
public:
    


    //public variables
    sf::Sprite unitSprite;
    sf::Sprite highResSprite;

    //constructor
    Unit(int allegiance, int rank, char* texturePath);
    //Default constructor
    Unit();

    //getters
    int getRank();
    int getAllegiance();
    //sf::Sprite getUnitSprite();
    //struct ArrayCoords getLocation();

    //setters
    void setRank(int rank);
    void setAllegiance(int allegiance);
    //void setLocation(struct ArrayCoords newLocation);
    void initSprite(const char* texturePath);
    void hideUnit();

    //other
    void die();
};

#endif // !UNIT_H