#ifndef _DUKE_HPP_
#define _DUKE_HPP_

#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Game.hpp"


namespace coup {
    class Duke : public Player {
    private:
    public:
        Duke(Game &game, const std::string &name) : Player(game, name, "Duke") {}
        ~Duke() {}
        void tax();
        void block(Player player);
    };
}
#endif 
