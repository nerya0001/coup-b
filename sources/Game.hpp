#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Player.hpp"

const int MAXPLAYERS = 6;
const int MAXCOINS = 10;
const int COUPCOST = 7;
const int COUPMIN = 3;

namespace coup {
    class Player;
    class Game {
    protected:
        std::vector<coup::Player*> PlayersList;

        size_t _turn;
        bool isGameActive;
        int numOfPlayers;


    public:
        Game();
        ~Game() {}
        std::vector<std::string> cleanPlayersList();
        void addPlayer(coup::Player *player);
        std::string turn();
        std::vector<std::string> players();
        int getNumOfPlayers() const;
        void setNumOfPlayers(int x);
        void turnGameOn();
        bool getGameState() const;
        Game* getGame();
        std::string winner();
        void nextTurn();
        Player* locate(std::string &name);
        
    };
}
#endif 
