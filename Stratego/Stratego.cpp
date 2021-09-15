#include <iostream>
using namespace std;

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
#define LIUTENANT 5
#define CAPTAIN 6
#define MAJOR 7
#define COLONEL 8
#define GENERAL 9
#define MARSHAL 10
#define BOMB 11
#define FLAG 12

struct Space{
    int x;
    int y;
};

class Unit{
    private:
        struct Space Location;
        int Allegiance;
        int Rank;
        int ID;
        const struct Space graveYard = {-1,-1};
    public:
        //constructor
        Unit(struct Space location, int allegiance, int rank, int id){
            Location = location;
            Allegiance = allegiance;
            Rank = rank;
            ID = id;
        }
        //getters
        int getRank(){
            return Rank;
        }
        struct Space getLocation(){
            return Location;
        }
        //setters
        void setRank(int rank){
            Rank = rank;
        }
        void setLocation(struct Space newLocation){
            Location = newLocation;
        }
        //other
        void die(){
            Location = graveYard;
            Rank = DEAD;
            Allegiance = NEUTRAL;
        }
};

class playerUI{
    private: 
        int PlayerTurn;
    public:
        void tryMove(){

        }
};



class GameHandler{
    private:
        Unit Board[10][10];
        const struct Space graveYard = {-1,-1};
    public:
        /*
        GameHandler(Unit board[10][10]){
            copy(board, board+10, Board);
        }*/

        bool validateMove(Unit unit, struct Space currentLocation, struct Space attemptedLocation){
            //check if same space clicked
            if(currentLocation.x == attemptedLocation.x && currentLocation.y == attemptedLocation.y){
                return false;
            }
            //check if alligned
            bool x_aligned = false;
            if(currentLocation.x == attemptedLocation.x){
                x_aligned = true;
            }
            else if(currentLocation.y == attemptedLocation.y){
                x_aligned = false;
            }
            else{
                //not alligned
                return false;
            }



            if(unit.getRank() == SCOUT){
                if (x_aligned){
                    if(attemptedLocation.x < currentLocation.x){
                        for(int x)
                    }
                }
                
            }
            else{

            }
        }

        bool movePiece(){
            bool valid = true;
            if(!valid){
                return false;
            }
        }

        void setup(){
            //fill top with dead people
            for(int y=0;y<3;y++){
                for(int x=0,x<10,x++){
                        struct Space space = {x,y};
                        Board[y][x] = Unit(space, NEUTRAL, DEAD, -10);
				}     
			}
            //alternate grass and lake in the middle
            for(int y=4;y<5;y++){
                for(int x=0;x<10;x++){
                    for (int i = 0; i < 2; i++)
                    {
                        struct Space space = {x,y};
                        Board[y][x] = Unit(space, NEUTRAL, DEAD, -10);
                    }
                    for (int i = 0; i < 2; i++)
                    {
                        struct Space space = {x,y};
                        Board[y][x] = Unit(space, NEUTRAL, BLOCKADE, -10);
                    }
                }
            }
            //fill bottom with dead people
            for(int y=6;y<10;y++){
                for(int x=0,x<10,x++){
                        struct Space space = {x,y};
                        Board[y][x] = Unit(space, NEUTRAL, DEAD, -10);
				}     
			}
            //allow blue player to set up
            int currentPlayer = BLUE;

            
        }

        void battle(Unit attacker, Unit defender){
            int attackerRank = attacker.getRank();
            int defenderRank = defender.getRank();

            //draw
            if (attackerRank == defenderRank){
                attacker.die();
                defender.die();
            }
            //spy kills marshal
            else if(attackerRank == SPY && defenderRank == MARSHAL){
                attacker.setLocation(defender.getLocation());
                defender.die();
            }
            //bomb is defused
            else if(attackerRank == MINER && defenderRank == BOMB){
                attacker.setLocation(defender.getLocation());
                defender.die();
            }
            //bomb is triggered
            else if(defenderRank == BOMB){
                attacker.die();
            }
            //flag is captured
            else if(defenderRank == FLAG){
                //WIN THE GAME
            }
            //normal attacker win
            else if(attackerRank > defenderRank){
                attacker.setLocation(defender.getLocation());
                defender.die();
            }
            //normal defender win
            else{
                attacker.die();
            }
        }
};

class Graphics{
    private: 
        int PlayerTurn;
    public:
        void tryMove(){

        }
};


int main(){



}