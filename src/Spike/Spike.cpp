/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Spike
*/

#include "Spike.hpp"
#include "MouvementCompenant.hpp"
#include "PlayerControllerCompenant.hpp"
#include "CollisionCompenant.hpp"
#include "GravityCompenant.hpp"
#include "Map.hpp"

Spike::Spike() : Entity()
{
    DEBUG("Spike init");
    this->initSprite("assets/spike.png", {0, 0, this->SPIKE_SIZE, this->SPIKE_SIZE});
    // this->addCompenant(new PlayerControllerCompenant(this), CompenantType::PLAYER_CONTROLLER_COMPENANT);
    // this->addCompenant(new GravityCompenant(this), CompenantType::GRAVITY_COMPENANT);
    this->addCompenant(new CollisionCompenant(this), CompenantType::COLLISION_COMPENANT);
}

void Spike::removeEntity()
{
    delete this->_image;
    DEBUG("Spike remove");
    this->~Spike();
}

void Spike::update(const float dt)
{
}

void Spike::render(sf::RenderTarget &target)
{
    target.draw(this->_image->sprite);
}
