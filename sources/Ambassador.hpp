#ifndef _AMBASSADOR_HPP_
#define _AMBASSADOR_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

namespace coup {
    class Ambassador : public Player {
    private:

    public:
        Ambassador(Game &game, const std::string &name) : Player(game, name, "Ambassador") {}
        void transfer(Player &player1,Player &player2);
        void block(Player &Player);

    };
}

#endif 
