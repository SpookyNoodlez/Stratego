
#include "Game.h"
using namespace std;

#include <chrono>
#include <thread>
#include <windows.h>

int main(){
    Game game;
    while (game.running()) {
        auto start = std::chrono::high_resolution_clock::now();

        game.update();
        game.render();

        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        //sleep to limit fps std::chrono::high_resolution_clock
        //std::cout << microseconds << "\n";

        //Sleep(1000000 - microseconds);
    }

    return 0;
}
