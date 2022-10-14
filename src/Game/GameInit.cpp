/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** GameInit
*/

#include "Game.hpp"

void Game::initWindow()
{
    this->_window.create(sf::VideoMode(1920, 1080), "SFML works!");
    this->_window.setFramerateLimit(60);
}

void Game::initState()
{
    this->_state = new std::vector<State *>();
    this->_state->push_back(new GameState());
}

void Game::initGameState()
{
    this->_font.loadFromFile("assets/font.ttf");
}

void Game::removeState()
{
    this->_state->back()->removeState();
    delete this->_state->back();
    this->_state->pop_back();
}