/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** MouvementCompenant
*/

#include "MouvementCompenant.hpp"
#include <iomanip>
#include <cstdint>
#include <algorithm>
#include <iostream>

MouvementCompenant::MouvementCompenant(Entity *entityLink) : Compenant(entityLink)
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
    DEBUG("MouvementCompenant update");
    this->_entity->getSprite().move(0, 1);
    std::clamp(this->_velocity.x, -this->_maxVelocity.x, this->_maxVelocity.x);
    std::clamp(this->_velocity.y, -this->_maxVelocity.y, this->_maxVelocity.y);
}

void MouvementCompenant::render(sf::RenderTarget &target)
{
    // DEBUG("MouvementCompenant render");
}
