#include <iostream>
#include <string>

class Player{
    private:
        std::string name;
        float balance;
        int option;
    public:
        Player();
        Player(std::string name, float balance);
        //setters:
        void setName(std::string name);
        void setBalance(float balance);
        void setOption(int option);
        //getters:
        std::string getName();
        float getBalance();
        int getOption();
        void toString();
};
