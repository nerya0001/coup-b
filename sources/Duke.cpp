#include <iostream>
#include <stdexcept>
#include <string>
#include "Duke.hpp"
#include "Player.hpp"

namespace coup
{

    void Duke::tax()
    {
        if (!this->getGame()->getGameState())
        {
            this->getGame()->turnGameOn();
        }
        if (this->getState())
        {
            if (!this->getIsDead())
            {
                this->setDead();

                throw std::invalid_argument("you are dead");
            }

            throw std::invalid_argument("you are dead");
        }
        if (this->game->turn() != this->getName())
        {
            throw std::invalid_argument("Not your turn");
        }
        if (this->coins() >= MAXCOINS)
        {
            throw std::invalid_argument("You have to coup");
        }
        this->setCoins(this->coins() + 3);
        this->SetLastAction(TAX);
        this->getGame()->nextTurn();
    }

    void Duke::block(Player player)
    {
        if (this->getState())
        {
            if (!this->getIsDead())
            {
                this->setDead();

                throw std::invalid_argument("you are dead");
            }

            throw std::invalid_argument("you are dead");
        }
        if (player.getState())
        {
            if (player.getIsDead())
            {
                throw std::invalid_argument("the player you are trying to block is already dead");
            }
            throw std::invalid_argument("player is couped");
        }
        if (player.getLastAction() == 2)
        {
            player.setCoins(player.coins() - 2);
        }
        else
        {
            throw std::invalid_argument("You are not allowd to block");
        }
    }

}