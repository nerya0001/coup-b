#include <vector>
#include <string>
#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"

namespace coup
{
    void Assassin::coup(Player &player)
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
                throw std::invalid_argument("the player you are trying to coup is already dead");
            }
            throw std::invalid_argument("player is couped");
        }
        if (this->getGame()->turn() != this->getName())
        {
            throw std::invalid_argument("Not your turn");
        }
        if (this->coins() < COUPMIN)
        {
            throw std::invalid_argument("Not enough coins");
        }
        if (this->coins() >= COUPMIN && this->coins() < COUPCOST)
        {
            this->setCoins(this->coins() - COUPMIN);
            player.setCouped(true);
            this->setFromWhom(&player);
            this->getGame()->setNumOfPlayers(this->getGame()->getNumOfPlayers() - 1);
            this->SetLastAction(COUP);
            this->getGame()->nextTurn();
        }
        else
        {
            Player::coup(player);
        }
    }
}