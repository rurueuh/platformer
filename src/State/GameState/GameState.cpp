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
    this->_player = new Player();
    this->_exit = new Exit();
    this->_map = new Map(*this->_player, *this->_exit, this->_spikes);
    this->_allEntity = Entity::getAllEntity();
}

GameState::~GameState()
{
    DEBUG("GameState remove");
    this->_player->removeEntity();
    this->_exit->removeEntity();
    for (auto &spike : this->_spikes) {
        spike->removeEntity();
    }
    delete this->_map;
    this->removeState();
}

void GameState::reset()
{
    this->_player->removeEntity();
    this->_exit->removeEntity();
    delete this->_map;
    this->_player = new Player();
    this->_exit = new Exit();
    this->_map = new Map(*this->_player, *this->_exit, this->_spikes);
    this->_allEntity = Entity::getAllEntity();
    this->updateEntity = true;
}

void GameState::removeState()
{
    for (auto &entity : this->_allEntity) {
        entity->removeEntity();
    }
    delete this->_map;
    DEBUG("GameState remove");
}
    
void GameState::update(const float dt)
{
    this->_map->updateMap();
    for (auto &entity : this->_allEntity) {
        if (updateEntity == true) {
            updateEntity = false;
            break;
        }
        entity->autoUpdate(dt);
    }
}

void GameState::render(sf::RenderTarget &target)
{
    this->_map->drawMap(target);
    for (auto &entity : this->_allEntity) {
        entity->autoRender(target);
    }
}
