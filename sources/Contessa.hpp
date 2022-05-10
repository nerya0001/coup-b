#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"

#ifndef _CONTESSA_HPP_
#define _CONTESSA_HPP_

namespace coup {
    class Contessa : public Player {
    private:
    public:
        Contessa(Game &game, const std::string &name) : Player(game, name, "Contessa") {}
        ~Contessa() {}
        void block(Player &player);

    };
}
#endif 
