#include <iostream>
#include <string>
#include "Player.h"

using namespace std;
//implementation --- constructors ---
Player::Player(){
    this->name=" ";
}
Player::Player(string name, float balance){
    this->name = name;
    this->balance = balance;
}
//setters:
void Player::setName(string name){
    this->name = name;
}
void Player::setBalance(float balance){
    this->balance = balance;
}
void Player::setOption(int option){
    this->option = option;
}
//getters:
string Player::getName(){
    return this->name;
}
float Player::getBalance(){
    return this->balance;
}
int Player::getOption(){
    return this->option;
}
//toString:
void Player::toString(){
    cout<<"[ Player: "<<this->name<<" | Balance: "<<to_string(this->balance)<<" ]"<<endl;
}
