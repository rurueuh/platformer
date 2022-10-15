/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    this->initWindow();
    this->initState();
    this->initGameState();
}

Game::~Game()
{
    while (!this->_state->empty()) {
        this->removeState();
    }
    delete this->_state;
}

void Game::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                _window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                _window.close();
                return;
            }
        }
        update();
        draw();
    }
}

void Game::update()
{
    auto *last = _state->back();
    static sf::Clock clock; // todo : move clock in state
    float dt = clock.restart().asSeconds();
    last->update(dt);
}

void Game::draw()
{
    _window.clear();
    auto *last = _state->back();
    last->render(_window);
    _window.display();
}
