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
        compenant.first->remove();
        delete compenant.first;
    }
    // auto remove from list of entity
    Entity::_allEntity.erase(std::remove(Entity::_allEntity.begin(), Entity::_allEntity.end(), this), Entity::_allEntity.end());
}

void Entity::addCompenant(Compenant *compenant, CompenantType type)
{
    this->_compenants.push_back({compenant, type});
}

Compenant *Entity::getCompenant(CompenantType type)
{
    std::vector<std::pair<Compenant *, CompenantType>>::iterator it = std::find_if(this->_compenants.begin(), this->_compenants.end(), [type](std::pair<Compenant *, CompenantType> compenant) {
        return compenant.second == type;
    });
    if (it != this->_compenants.end())
        return it->first;
    DEBUG("Compenant not found " + std::to_string(type));
    return nullptr;
}

void Entity::autoUpdate(const float dt)
{
    for (auto &compenant : this->_compenants) {
        if (compenant.first->isUpdateable() && compenant.first->isActive())
            compenant.first->update(dt);
    }
    this->update(dt);
}

void Entity::autoRender(sf::RenderTarget &target)
{
    for (auto &compenant : this->_compenants) {
        if (compenant.first->isDrawable() && compenant.first->isActive())
            compenant.first->render(target);
    }
    this->render(target);
}
