/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Entity
*/

#include "Entity.hpp"

std::vector<Entity *> Entity::_allEntity = std::vector<Entity *>();

Entity::Entity()
{
    DEBUG("Entity init");

    // Add to all entity
    this->_allEntity.push_back(this);
}

Entity::~Entity()
{
    DEBUG("Entity remove");

    // auto remove from list of entity
    this->_allEntity.erase(std::remove(this->_allEntity.begin(), this->_allEntity.end(), this), this->_allEntity.end());
}

void Entity::autoUpdate(const float dt)
{
    this->update(dt);
}

void Entity::autoRender(sf::RenderTarget &target)
{
    this->render(target);
}
