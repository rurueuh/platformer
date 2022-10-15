/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** GravityCompenant
*/

#include "GravityCompenant.hpp"
#include "CollisionCompenant.hpp"

GravityCompenant::GravityCompenant(Entity *entityLink) : Compenant(entityLink)
{
    this->initCompenant(false, true, true);
    this->initVariable();
    DEBUG("GravityCompenant created");
}

GravityCompenant::~GravityCompenant()
{
    DEBUG("GravityCompenant destroyed");
}

void GravityCompenant::remove()
{
    DEBUG("GravityCompenant removed");
}

void GravityCompenant::initVariable()
{
}

void GravityCompenant::update(const float dt)
{
    this->_actualGravity += this->_force;
    if (this->_actualGravity > this->_maxGravity)
        this->_actualGravity = this->_maxGravity;
    if (this->_entity->getCompenant(CompenantType::COLLISION_COMPENANT) != nullptr) {
        CollisionCompenant *collision = dynamic_cast<CollisionCompenant *>(this->_entity->getCompenant(CompenantType::COLLISION_COMPENANT));
        if (collision->checkCollision(sf::FloatRect(0, this->_actualGravity, 0, 0)) == CollisionType::Block) {
            this->_actualGravity = 0;
            this->_grounded = true;
        } else {
            this->_grounded = false;
        }
    }
    this->_entity->getSprite().move(0, this->_actualGravity);
}

void GravityCompenant::render(sf::RenderTarget &target)
{
}
