/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** GameState
*/

#include "GameState.hpp"

GameState::GameState()
{
    DEBUG("GameState init");
    this->_allEntity = Entity::getAllEntity();
}

void GameState::removeState()
{
    for (auto &entity : this->_allEntity) {
        entity->removeEntity();
    }
    DEBUG("GameState remove");
}
    
void GameState::update(const float dt)
{
    for (auto &entity : this->_allEntity) {
        entity->autoUpdate(dt);
    }
}

void GameState::render(sf::RenderTarget &target)
{
    for (auto &entity : this->_allEntity) {
        entity->autoRender(target);
    }
}
