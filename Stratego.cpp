#include <iostream>
using namespace std;

//Teams for allegience
#define BLUE = 0
#define RED = 1
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
            setLocation(graveYard);
            setRank(DEAD);
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
        //constructor
        GameHandler(Unit board[10][10]){
            copy(board, board+10, Board);
        }

        void validateMove(){

        }

        bool movePiece(){
            bool valid = true;
            if(!valid){
                return false;
            }
        }

        void setup(){
            
        }

        void battle(Unit attacker, Unit defender){
            int attackerRank = attacker.getRank();
            int defenderRank = defender.getRank();
            bool attackerWin;

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




int main(){



}