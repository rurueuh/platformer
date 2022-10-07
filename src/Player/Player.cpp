/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Player
*/

#include "Player.hpp"
#include "MouvementCompenant.hpp"

Player::Player() : Entity()
{
    DEBUG("Player init");
    this->initSprite("assets/player.png", {151, 12, 81, 108});
    this->_compenants.push_back(new MouvementCompenant(this));
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
