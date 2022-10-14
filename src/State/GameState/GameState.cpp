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
    this->_map = new Map(this->_player);
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
    this->_map->updateMap();
}

void GameState::render(sf::RenderTarget &target)
{
    for (auto &entity : this->_allEntity) {
        entity->autoRender(target);
    }
    this->_map->drawMap(target);
}
