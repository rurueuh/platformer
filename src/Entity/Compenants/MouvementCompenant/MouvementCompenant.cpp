/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** MouvementCompenant
*/

#include "MouvementCompenant.hpp"

MouvementCompenant::MouvementCompenant(Entity *entity) : Compenant(entity)
{
    this->initCompenant(true, true, true);
    this->initVariable();
    DEBUG("MouvementCompenant init");
}

MouvementCompenant::~MouvementCompenant()
{
    DEBUG("MouvementCompenant remove");
}

void MouvementCompenant::remove()
{
    this->~MouvementCompenant();
}

void MouvementCompenant::initVariable()
{
    
}

void MouvementCompenant::update(const float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        this->_entity->getSprite().move(-1, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        this->_entity->getSprite().move(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        this->_entity->getSprite().move(0, -1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        this->_entity->getSprite().move(0, 1);
    }
    // DEBUG("MouvementCompenant update");
}

void MouvementCompenant::render(sf::RenderTarget &target)
{
    DEBUG("MouvementCompenant render");
}
