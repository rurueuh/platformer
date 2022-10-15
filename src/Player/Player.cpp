/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Player
*/

#include "Player.hpp"
#include "MouvementCompenant.hpp"
#include "PlayerControllerCompenant.hpp"
#include "CollisionCompenant.hpp"
#include "GravityCompenant.hpp"
#include "Map.hpp"

Player::Player() : Entity()
{
    DEBUG("Player init");
    this->initSprite("assets/player.png", {0, 0, this->PLAYER_SIZE, this->PLAYER_SIZE});
    for (int i = 0; i < 1; i++) {
        this->addCompenant(new PlayerControllerCompenant(this), CompenantType::PLAYER_CONTROLLER_COMPENANT);
    }
    this->addCompenant(new GravityCompenant(this), CompenantType::GRAVITY_COMPENANT);
    this->addCompenant(new CollisionCompenant(this), CompenantType::COLLISION_COMPENANT);
}

void Player::removeEntity()
{
    delete this->_image;
    DEBUG("Player remove");
    this->~Player();
}

void Player::update(const float dt)
{
}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->_image->sprite);
}
