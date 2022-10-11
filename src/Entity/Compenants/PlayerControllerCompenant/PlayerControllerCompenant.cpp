/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** PlayerControllerCompenant
*/

#include "PlayerControllerCompenant.hpp"

PlayerControllerCompenant::PlayerControllerCompenant(Entity *entityLink) : Compenant(entityLink)
{
    this->initCompenant(true, true, true);
    this->initVariable();
    DEBUG("PlayerControllerCompenant init");
}

PlayerControllerCompenant::~PlayerControllerCompenant()
{
    DEBUG("PlayerControllerCompenant remove");
}

void PlayerControllerCompenant::remove()
{
    this->~PlayerControllerCompenant();
    delete this->mouvementCompenant;
}

void PlayerControllerCompenant::initVariable()
{
    this->mouvementCompenant = new MouvementCompenant(this->_entity);
}

void PlayerControllerCompenant::update(const float dt)
{
    // DEBUG("MouvementCompenant update");
    this->mouvementCompenant->update(dt);
}

void PlayerControllerCompenant::render(sf::RenderTarget &target)
{
    // DEBUG("MouvementCompenant render");
    this->mouvementCompenant->render(target);
}
