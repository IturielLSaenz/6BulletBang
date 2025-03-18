#include "Player.cpp"
#include "Gun.cpp"

class Game{
    private:
        Player player1,player2;
        Gun revolver;
        int dead_players,turn,option;
    public:
        Game();
        Game(Player player1, Player player2);
        void selectOpt();
        int getSelectedOpt();
        //game methods
        void gameLogic(); //manipulates data to get the current state of the game!
        void update();
        void start();
        void credits();
};
