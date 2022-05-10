#include <iostream>
#include <string>
#include <vector>
#include "Contessa.hpp"
#include "Player.hpp"


namespace coup {
    void Contessa::block(Player &player){
        if (this->getState()) {
            if (!this->getIsDead()) {
                this->setDead();
              
                throw std::invalid_argument("you are dead");
            }
         
            throw std::invalid_argument("you are dead");
        }
        if (player.getState()) {
            if (player.getIsDead()) {
                
                throw std::invalid_argument("the player you are trying to block is already dead");
            }
            throw std::invalid_argument("player is couped");
        }  
        if (player.role() == "Assassin" && player.getLastAction() == 3) {
            Player* happy = player.getFromWhom();
            if (happy->getIsDead()) {
                throw std::invalid_argument("the player you are trying to save is already dead");
            }
            happy->setCouped(false);
            this->getGame()->setNumOfPlayers(this->getGame()->getNumOfPlayers() + 1);
        } else {
            throw std::invalid_argument("Not a valid operation");
        }

    }
}