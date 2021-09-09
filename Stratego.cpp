#include <iostream>
using namespace std;

//Teams for allegi
#define BLUE = 0, RED = 1;

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

    public:
        //constructor
        Unit(struct Space location, int allegiance, int rank, int id){
            Location = location;
            Allegiance = allegiance;
            Rank = rank;
            ID = id;
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

        void battle(){

        }

};




int main(){



}