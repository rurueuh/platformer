/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Exit
*/

#include "Exit.hpp"
#include "MouvementCompenant.hpp"
#include "PlayerControllerCompenant.hpp"
#include "CollisionCompenant.hpp"
#include "GravityCompenant.hpp"
#include "Map.hpp"

Exit::Exit() : Entity()
{
    DEBUG("Exit init");
    this->initSprite("assets/exit.png", {0, 0, this->EXIT_SIZE, this->EXIT_SIZE});
    // this->addCompenant(new PlayerControllerCompenant(this), CompenantType::PLAYER_CONTROLLER_COMPENANT);
    this->addCompenant(new GravityCompenant(this), CompenantType::GRAVITY_COMPENANT);
    this->addCompenant(new CollisionCompenant(this), CompenantType::COLLISION_COMPENANT);
}

void Exit::removeEntity()
{
    delete this->_image;
    DEBUG("Exit remove");
    this->~Exit();
}

void Exit::update(const float dt)
{
}

void Exit::render(sf::RenderTarget &target)
{
    target.draw(this->_image->sprite);
}
