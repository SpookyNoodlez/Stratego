
#include "Game.h"
using namespace std;


class GameHandler{
    private:
        Unit Board[10][10];
        
    public:
        /*
        GameHandler(Unit board[10][10]){
            copy(board, board+10, Board);
        }*/

        bool validateMove(Unit unit, struct ArrayCoords currentLocation, struct ArrayCoords attemptedLocation){
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
                        //for(int x)
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
            //fill top with red dead people
            for(int y=0;y<3;y++){
                for (int x = 0; x < 10; x++) {
                        struct ArrayCoords space = {x,y};
                       // Board[y][x] = new Unit(space, RED, DEAD, -10); //Unit(struct Space location, int allegiance, int rank, int id){
				}     
			}
            //alternate grass and lake in the middle
            for(int y=4;y<5;y++){
                for(int x=0;x<10;x++){
                    for (int i = 0; i < 2; i++)
                    {
                        struct ArrayCoords space = {x,y};
                      //  Board[y][x] = new Unit(space, NEUTRAL, DEAD, -10);
                    }
                    for (int i = 0; i < 2; i++)
                    {
                        struct ArrayCoords space = {x,y};
                    //    Board[y][x] = Unit(space, NEUTRAL, BLOCKADE, -10);
                    }
                }
            }
            //fill bottom with blue dead people
            for(int y=6;y<10;y++){
                for (int x = 0; x < 10; x++) {
                        struct ArrayCoords space = {x,y};
                        //Board[y][x] = Unit(space, BLUE, DEAD, -10);
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


int main(){
    Game game;
    while (game.running()) {
        game.update();
        game.render();
    }

    return 0;
}