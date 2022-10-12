/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** ExempleCompenant
*/

#include "ExempleCompenant.hpp"

ExempleCompenant::ExempleCompenant(Entity *entityLink) : Compenant(entityLink)
{
    this->initCompenant(true, true, true);
    this->initVariable();
    DEBUG("ExempleCompenant created");
}

ExempleCompenant::~ExempleCompenant()
{
    DEBUG("ExempleCompenant destroyed");
}

void ExempleCompenant::remove()
{
    DEBUG("ExempleCompenant removed");
}

void ExempleCompenant::initVariable()
{
}

void ExempleCompenant::update(const float dt)
{
}

void ExempleCompenant::render(sf::RenderTarget &target)
{
}
