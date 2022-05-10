#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Game.hpp"

namespace coup
{
    /**
     * @brief Construct a new Game:: Game object
     *
     */
    Game::Game()
    {
        std::vector<coup::Player *> PlayersList;
        this->_turn = 0;
        this->numOfPlayers = 0;
        this->isGameActive = false;
    }

    void Game::addPlayer(Player *player)
    {
        if (this->isGameActive)
        {
            throw std::invalid_argument("you can't add player");
        }
        if (this->PlayersList.size() == MAXPLAYERS)
        {
            throw std::invalid_argument("this game can have up to 6 players!");
        }
        this->PlayersList.push_back(player);

        this->numOfPlayers++;
    }

    /**
     * @brief whose turn is now
     *
     * @return std::string
     */
    std::string Game::turn()
    {
        return this->PlayersList.at((size_t)(this->_turn % this->PlayersList.size()))->getName();
    }

    bool Game::getGameState() const
    {
        return this->isGameActive;
    }

    void Game::turnGameOn()
    {
        this->isGameActive = true;
    }

    Player *Game::locate(std::string &name)
    {
        Player *ans = nullptr;
        for (uint i = 0; i < this->PlayersList.size(); i++)
        {
            if (this->PlayersList.at(i)->getName() == name)
            {
                ans = this->PlayersList.at(i);
            }
        }
        return ans;
    }

    /**
     * @brief advance to the next turn
     *
     */
    void Game::nextTurn()
    {
        this->_turn = ++this->_turn % this->PlayersList.size();
        std::string name = this->turn(); // has to be lvalue
        Player *nextCheck = this->locate(name);
        // std::cout << "name: " << nextCheck->getState() << std::endl;
        if (nextCheck->getIsDead() || nextCheck->getState())
        {
            nextCheck->setDead();
        }
        while (this->PlayersList[this->_turn % this->PlayersList.size()]->getIsDead())
        {
            this->_turn = ++this->_turn % this->PlayersList.size();
        }
    }

    int Game::getNumOfPlayers() const
    {
        return this->numOfPlayers;
    }

    void Game::setNumOfPlayers(int x)
    {
        this->numOfPlayers = x;
    }

    /**
     * @brief get the players list
     *
     * @return std::vector<std::string>
     */
    std::vector<std::string> Game::players()
    {
        std::vector<std::string> cleaned;
        for (Player *p : this->PlayersList)
        {
            if (!p->getState())
            {
                cleaned.push_back(p->getName());
            }
        }
        return cleaned;
    }

    /**
     * @brief Announce winner
     *
     * @return std::string
     */
    std::string Game::winner()
    {
        if (!this->isGameActive)
        {
            throw std::invalid_argument("The game hasn't started");
        }
        if (this->numOfPlayers > 1)
        {
            throw std::invalid_argument("The game is not over");
        }

        std::string winner = this->players().at(0);
        return winner;
    }
}