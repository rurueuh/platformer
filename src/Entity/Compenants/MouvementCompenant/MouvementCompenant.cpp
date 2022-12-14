/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** MouvementCompenant
*/

#include "MouvementCompenant.hpp"
#include "CollisionCompenant.hpp"
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
    this->_velocity = sf::Vector2f(0, 0);
    this->_maxVelocity = sf::Vector2f(10, 10);
    this->_acceleration = 75;
    this->_deceleration = 75;
    this->_isMovingX = false;
    this->_isMovingY = false;
}

void MouvementCompenant::update(const float dt)
{
    this->_velocity.x = std::clamp(this->_velocity.x, -this->_maxVelocity.x, this->_maxVelocity.x);
    // this->_velocity.y = std::clamp(this->_velocity.y, -this->_maxVelocity.y, this->_maxVelocity.y);
    if (!this->_isMovingX) {
        if (this->_velocity.x > 0) {
            this->_velocity.x -= this->_deceleration * dt;
            if (this->_velocity.x < 0)
                this->_velocity.x = 0;
        } else if (this->_velocity.x < 0) {
            this->_velocity.x += this->_deceleration * dt;
            if (this->_velocity.x > 0)
                this->_velocity.x = 0;
        }
    }
    if (!this->_isMovingY) {
        if (this->_velocity.y > 0) {
            this->_velocity.y -= this->_deceleration * dt;
            if (this->_velocity.y < 0)
                this->_velocity.y = 0;
        } else if (this->_velocity.y < 0) {
            this->_velocity.y += this->_deceleration * dt;
            if (this->_velocity.y > 0)
                this->_velocity.y = 0;
        }
    }
    CollisionCompenant *compenant = (CollisionCompenant *) this->_entity->getCompenant(CompenantType::COLLISION_COMPENANT);
    if (compenant != nullptr) {
        if (compenant->checkCollision(sf::FloatRect(this->_velocity.x, this->_velocity.y, 0, 0)) == CollisionType::Block) {
            this->_velocity.x = 0;
            this->_velocity.y = 0;
        }
    }
    this->_entity->getSprite().move(this->_velocity);
}

void MouvementCompenant::render(sf::RenderTarget &target)
{
}
