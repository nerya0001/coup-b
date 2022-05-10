#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <stdexcept>
#include <string>
#include "Game.hpp"

const int NOTHING = 0;
const int INCOME = 1;
const int FOREIGN = 2;
const int COUP = 3;
const int ROLE = 4;
const int COINS = 5;
const int TRANSFER = 6;
const int STEAL = 7;
const int TAX = 8;

namespace coup
{
    class Game;

    class Player
    {
    protected:
        Game *game;
        std::string name;
        std::string _role;

        // options:
        // 0 = nothing,
        // 1 = income,
        // 2 = foreign_aid,
        // 3 = coup,
        // 4 = role,
        // 5 = coins,
        // 6 = transfer,
        // 7 = steal
        // 8 = tax
        int lastAction;

        int _coins;
        int amountToSteal;
        bool isCouped;
        bool isDead;
        Player *fromWhom;

    public:
        Player(coup::Game &game, const std::string &name, const std::string &role);
        ~Player() {}
        void income();
        void foreign_aid();
        void coup(Player &player);
        std::string getName() const;
        std::string role() const;
        int coins() const;
        void setDead();
        bool getIsDead() const;
        bool getState() const;
        Game *getGame() const;
        void setCoins(int amount);
        int getLastAction() const;
        void SetLastAction(int action);
        void setCouped(bool b);
        int getWhatToSteal() const;
        Player *getFromWhom() const; // from whom to steal or whom to coup
        void setFromWhom(Player *who);
    };
}
#endif
