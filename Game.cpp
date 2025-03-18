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
    cout<<"\n Please choose wisely: ";
    cin>>this->option;
}
int Game::getSelectedOpt(){
    return this->option;
}
void Game::gameLogic(){
    if(this->getSelectedOpt()==1 && this->revolver.chamber[this->turn]==1){ //if selected 1 and in chamber is bullet!
        cout<<"You have lost!"<<endl;
        this->update();
    }else if(this->getSelectedOpt()==2 && this->revolver.chamber[this->turn]==1){ //if point and shoot and is bullet!
        cout<<"You have eliminated the other player!"<<endl;
    }else if(this->getSelectedOpt()==2 && this->revolver.chamber[this->turn]!=1){ //if point and shoot but no bullet!
        cout<<"You have missed, now point to yourself!"<<endl;
        this->update();
        if(this->revolver.chamber[this->turn]==1){ //shoot yourself!
            cout<<"You have lost!"<<endl;
        }else{
            cout<<"You have missed, that was good luck!"<<endl; //miss!
            this->update();
        }
    }else{ //if shoot but no bullet!
        cout<<"You have missed!"<<endl;
        this->update();
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

    this->gameLogic();
}