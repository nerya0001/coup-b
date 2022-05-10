#ifndef _CAPTAIN_HPP_
#define _CAPTAIN_HPP_

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"

namespace coup {
    class Captain : public Player {
    private:
    public:
        Captain(Game &game, const std::string &name) : Player(game, name, "Captain") {}
        ~Captain() {}
        void block(Player &player);
        void steal(Player &player);


    };
}

#endif 
