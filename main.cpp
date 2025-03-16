#include <iostream>
#include <string>
#include "Game.cpp"

using namespace std;

int main() {
    Player p1("Itu",0.0f);
    Player p2("Chino",0.0f);
    
    Game partida(p1,p2);
    partida.start();

    return 0;
}
