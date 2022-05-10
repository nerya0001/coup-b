#include "Captain.hpp"
#include "Duke.hpp"
#include "Player.hpp"

namespace coup {

    void Captain::block(Player &player) {
        if (this->getState()) {
            if (!this->getIsDead()) {
                this->setDead();
                throw std::invalid_argument("you are dead");
            }
  
            throw std::invalid_argument("you are dead");
        } 
        if (player.getState()) {
            if (player.getIsDead()) {
                throw std::invalid_argument("the player you are trying to save is already dead");
            }
            throw std::invalid_argument("You are trying to block a couped player");
        }
        if (player.role() == "Captain" && player.getLastAction() == STEAL) {
            player.setCoins(player.coins() - 2);
            Player* happy = player.getFromWhom();
            happy->setCoins(happy->coins() + 2);
        } else {
            throw std::invalid_argument("Not a valid operation");
        }
    }

    void Captain::steal(Player &player) {
        int howMuch = 0;
        if (this->getState()) {
            if (!this->getIsDead()) {
                this->setDead();
              
                throw std::invalid_argument("you are dead");
            }
       
            throw std::invalid_argument("you are dead");
        }
        if (this->game->turn() != this->getName()) {
            throw std::invalid_argument("Not your turn");
        }
        if (player.getState()) {
            if (player.getIsDead()) {
                
                throw std::invalid_argument("the player you are trying to steal from is already dead");
            }
          
            throw std::invalid_argument("You are trying to steal from a couped player");
        }
        if (this->coins() >= MAXCOINS) {
            throw std::invalid_argument("You have to coup");
        }
        if (player.coins() == 1) {
            this->setCoins(this->coins() + 1);
            player.setCoins(player.coins() - 1);
            howMuch = 1;
        } else if (player.coins() >= 2) {
            this->setCoins(this->coins() + 2);
            player.setCoins(player.coins() - 2);
            howMuch = 2;
        }
        this->SetLastAction(STEAL);
        this->amountToSteal = howMuch;
        this->fromWhom = &player;
        this->game->nextTurn();
    }
}