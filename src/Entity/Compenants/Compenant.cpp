/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Compenant
*/

#include "Compenant.hpp"
#include "Entity.hpp"

Compenant::Compenant(Entity *entityLink)
{
    this->_entity = entityLink;
}

Compenant::~Compenant()
{
}
