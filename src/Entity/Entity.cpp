/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Entity
*/

#include "Entity.hpp"
#include "Compenant.hpp"

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
    // remover of compenants
    for (auto &compenant : this->_compenants) {
        compenant->remove();
        delete compenant;
    }
    // auto remove from list of entity
    this->_allEntity.erase(std::remove(this->_allEntity.begin(), this->_allEntity.end(), this), this->_allEntity.end());
}

void Entity::autoUpdate(const float dt)
{
    for (auto &compenant : this->_compenants) {
        if (compenant->isUpdateable() && compenant->isActive())
            compenant->update(dt);
    }
    this->update(dt);
}

void Entity::autoRender(sf::RenderTarget &target)
{
    for (auto &compenant : this->_compenants) {
        if (compenant->isDrawable() && compenant->isActive())
            compenant->render(target);
    }
    this->render(target);
}
