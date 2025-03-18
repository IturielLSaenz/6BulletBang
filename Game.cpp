#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int rounds = 6; //number of spaces in bullet chamber!

Game::Game(){
    cout<<"There's no players registered!"<<endl;
    this->revolver = Gun();
}
Game::Game(Player player1, Player player2){
    this->revolver = Gun();
    this->player1 = player1;
    this->player2 = player2;
    this->turn=0;
}
void Game::selectOpt(){
    cout<<"\n**[ Options ]**"<<endl;
    cout<<"1. shoot \n";
    cout<<"2. point \n";
    cout<<"\n Please choose wisely: ";
    cin>>this->option;
}
int Game::getSelectedOpt(){
    return this->option;
}
void Game::gameLogic() {
    if (this->getSelectedOpt() == 1) { // Player chooses to shoot
        if (this->revolver.chamber[this->turn] == 1) { // Bullet is in the chamber
            cout << "You have lost!" << endl;
        } else { // No bullet in the chamber
            cout << "You have survived! No bullet in the chamber." << endl;
        }
    } else if (this->getSelectedOpt() == 2) { // Player chooses to point
        if (this->revolver.chamber[this->turn] == 1) { // Bullet is in the chamber
            cout << "You have eliminated the other player!" << endl;
        } else { // No bullet in the chamber
            cout << "You have missed, now point to yourself!" << endl;
            this->update();
            if (this->revolver.chamber[this->turn] == 1) { // Bullet is now in the chamber
                cout << "You have lost!" << endl;
            } else {
                cout << "You have survived! No bullet in the chamber." << endl;
            }
        }
    } else {
        cout << "Invalid option selected. Please choose 1 (shoot) or 2 (point)." << endl;
    }
}
void Game::update(){
    if (this->turn < rounds - 1) {
        this->turn++;
    } else {
        cout << "End of chamber reached. Resetting turn." << endl;
        this->turn = 0;
    }
}
void Game::start() {
    cout << "\n***--- Game Started ---***\n" << endl;

    cout << "*** Players: " << endl;
    cout << this->player1.getName() << "\n";
    cout << this->player2.getName() << "\n";

    int b;
    cout << "Please enter the total number of bullets in the chamber: (recommended: 1)" << "\n";
    cin >> b;
    this->revolver.loadGun(b);
    this->revolver.gunShuffle();
    int maxTurns = 6; // Maximum number of turns before the game ends
    int currentTurn = 0;

    while (currentTurn < maxTurns) {
        cout << "\nTurn " << currentTurn + 1 << " of " << maxTurns << endl;

        cout << "It's " << this->player1.getName() << "'s turn!" << endl;
        this->selectOpt();
        this->gameLogic();
        if (this->revolver.chamber[this->turn] == 1) { // Check if the game ends
            cout << this->player1.getName() << " has lost!" << endl;
            break;
        }

        cout << "It's " << this->player2.getName() << "'s turn!" << endl;
        this->selectOpt();
        this->gameLogic();
        if (this->revolver.chamber[this->turn] == 1) { // Check if the game ends
            cout << this->player2.getName() << " has lost!" << endl;
            break;
        }

        currentTurn++;
    }
    if (currentTurn == maxTurns) {
        cout << "The game has ended in a draw after " << maxTurns << " turns!" << endl;
    }
}