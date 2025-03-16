#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Gun.h"

using namespace std;

Gun::Gun(){
    this->bullets=0;
    for(int i = 0; i < 6; i++) {
        this->chamber[i] = 0;
    }
    cout<<"Gun Created with zero bullets!"<<endl;
}
Gun::Gun(int n_bullets){
    for(int i = 0; i < 6; i++) {
        this->chamber[i] = 0;
    }
    this->bullets=n_bullets;
}
/*-Methods for the gun-*/
void Gun::loadGun(int n_bullets){
    if(n_bullets<=6 && n_bullets>0){
        this->bullets=n_bullets;
    }else{
        cout<<"The number of bullets should be in between 0 and 6!"<<endl;
    }
}
void Gun::unloadGun(){
    this->bullets=0;
}
void Gun::gunShuffle(){
    srand (time(NULL));
    this->pos_chamber=rand() % 6+1;
    cout<<to_string(this->pos_chamber)<<endl;
    this->chamber[pos_chamber-1] = 1;
}
void Gun::gunShoot(){
    
}
//outside og game because it is a spoiler of the game :(
void Gun::revealGun(){
    cout<<"Chamber [ ";
    for(int i = 0; i < 6; i++){
        cout<<this->chamber[i]<<" ";
    }
    cout<<"]"<<endl;
}