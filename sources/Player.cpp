#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

namespace coup
{
    /**
     * @brief Construct a new Player:: Player object
     *
     */
    Player::Player(Game &game, const std::string &name, const std::string &role)
    {
        this->game = &game;
        this->name = name;
        this->_coins = 0;
        this->_role = role;
        this->isCouped = false;
        this->isDead = false;
        this->lastAction = 0;
        this->amountToSteal = 0;
        this->fromWhom = NULL;
        this->game->addPlayer(this);
    }

    /**
     * @brief Destroy the Player:: Player object
     *
     */

    /**
     * @brief add two coins to the player
     *
     */
    void Player::foreign_aid()
    {
        if (this->getGame()->players().size() == 1)
        {
            throw std::invalid_argument("Not enough players");
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
        if (!this->getGame()->getGameState())
        {
            this->getGame()->turnGameOn();
        }
        if (this->getGame()->turn() != this->getName())
        {
            throw std::invalid_argument("Not your turn");
        }
        if (this->coins() >= MAXCOINS)
        {
            throw std::invalid_argument("You have to coup");
        }

        this->setCoins(this->coins() + 2);
        this->SetLastAction(FOREIGN);
        this->getGame()->nextTurn();
    }

    /**
     * @brief
     *
     */
    void Player::income()
    {
        if (this->getGame()->players().size() == 1)
        {
            throw std::invalid_argument("Not enough players");
        }
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
        if (this->getGame()->turn() != this->getName())
        {
            throw std::invalid_argument("Not your turn");
        }
        if (this->coins() >= MAXCOINS)
        {
            throw std::invalid_argument("You have to coup");
        }
        this->setCoins(this->coins() + 1);
        this->SetLastAction(INCOME);
        this->getGame()->nextTurn();
    }

        /**
     * @brief
     *
     * @param player
     */
    void Player::coup(Player &player)
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
        if (this->getGame()->turn() != this->getName())
        {
            throw std::invalid_argument("Not your turn");
        }
        if (player.getState())
        {
            if (player.getIsDead())
            {
                throw std::invalid_argument("the player you are trying to coup is already dead");
            }
            throw std::invalid_argument("player is couped");
        }
        if (this->coins() < COUPCOST)
        {
            throw std::invalid_argument("Not enough coins");
        }

        this->setCoins(this->coins() - COUPCOST);
        player.setCouped(true);
        player.setDead();
        this->setFromWhom(&player);
        this->getGame()->setNumOfPlayers(this->getGame()->getNumOfPlayers() - 1);
        this->SetLastAction(COUP);
        this->getGame()->nextTurn();
    }

    /**
     * @brief get the number of coins
     *
     * @return int
     */
    int Player::coins() const
    {
        return this->_coins;
    }

    bool Player::getState() const
    {
        return this->isCouped;
    }

    bool Player::getIsDead() const
    {
        return this->isDead;
    }

    void Player::setDead()
    {
        this->isDead = true;
    }

    void Player::setFromWhom(Player *who)
    {
        this->fromWhom = who;
    }

    void Player::SetLastAction(int action) {
        this->lastAction = action;
    }

    /**
     * @brief getter for the name
     *
     * @return std::string
     */
    std::string Player::getName() const
    {
        return this->name;
    }

    /**
     * @brief getter for the role
     *
     * @return std::string
     */
    std::string Player::role() const
    {
        return this->_role;
    }

    /**
     * @brief Set the Coins
     *
     * @param amount
     */
    void Player::setCoins(int amount)
    {
        this->_coins = amount;
    }

    int Player::getLastAction() const
    {
        return this->lastAction;
    }

    int Player::getWhatToSteal() const
    {
        return this->amountToSteal;
    }

    Player *Player::getFromWhom() const
    {
        return this->fromWhom;
    }

    void Player::setCouped(bool b)
    {
        this->isCouped = b;
    }

    Game *Player::getGame() const
    {
        return this->game;
    }

}
