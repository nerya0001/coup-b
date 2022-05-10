#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Ambassador.hpp"
#include "Player.hpp"

/**
 * @brief coup
 * 
 */

namespace coup {
    void Ambassador::transfer(Player &player1, Player &player2) {
        if (!this->getGame()->getGameState()) {
            this->getGame()->turnGameOn();
        }
        if (this->getState()) {
            if (!this->getIsDead()) {
                this->setDead();
                throw std::invalid_argument("you are dead");
            }

            throw std::invalid_argument("you are dead");
        }
        if (this->getGame()->turn() != this->getName()) {
            throw std::invalid_argument("Not your turn");
        }
        if (this->coins() >= MAXCOINS) {
            throw std::invalid_argument("You have to coup");
        }
        if (player1.getState() || player2.getState()) {
            throw std::invalid_argument("player1 or player2 are couped");
        }
        if (player1.coins() == 0) {
            throw std::invalid_argument("player1 doesn't have enough money");
        }
        player1.setCoins(player1.coins() - 1);
        player2.setCoins(player2.coins() + 1);
        this->SetLastAction(TRANSFER);
        this->game->nextTurn();
    }

    void Ambassador::block(Player &player) {
        if (this->getState()) {
            if (!this->getIsDead()) {
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
        if (player.role() == "Captain" && player.getLastAction() == STEAL) {
            int amountStolen = player.getWhatToSteal();
            player.setCoins(player.coins() - amountStolen);
            Player* returnTo = player.getFromWhom();
            returnTo->setCoins(returnTo->coins() + amountStolen);
        } else {
            throw std::invalid_argument("Not valid operation");
        }
    }
}