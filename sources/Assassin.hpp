#ifndef _ASSASSIN_HPP_
#define _ASSASSIN_HPP_

#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"
#include "Game.hpp"


namespace coup {
    class Assassin : public Player {
    private:
    public:
        Assassin(Game &game, const std::string &name) : Player(game, name, "Assassin") {}
        ~Assassin() {}
        void coup(Player &player);

    };
}
#endif 
