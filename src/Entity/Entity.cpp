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
    this->_allEntity.push_back(this);
}

Entity::~Entity()
{
}

void Entity::autoUpdate(const float dt)
{
    this->update(dt);
}

void Entity::autoRender(sf::RenderTarget &target)
{
    this->render(target);
}
