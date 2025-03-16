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
    cout<<"**[ Options ]**"<<endl;
    cout<<"1. shoot \n";
    cout<<"2. point \n";
    cout<<"3. bet \n";
    cout<<"\n Please choose wisely: ";
    cin>>this->option;
}
int Game::getSelectedOpt(){
    return this->option;
}
void Game::start(){
    cout<<"\n***--- Game Started ---***\n"<<endl;

    cout<<"*** Players: "<<endl;
    cout<<this->player1.getName()<<"\n";
    cout<<this->player2.getName()<<"\n";

    int b;
    cout<<"Please enter the total of bullets in the chamber: (recommended: 1)"<<"\n";
    cin>>b;
    this->revolver.loadGun(b);
    this->revolver.gunShuffle();
    this->revolver.revealGun();
    cout<<"It's "<<this->player1.getName()<<"'s turn!"<<endl;
    this->selectOpt();

    if(this->getSelectedOpt()==1){

    }
}