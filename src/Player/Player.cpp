/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Player
*/

#include "Player.hpp"
#include "MouvementCompenant.hpp"
#include "PlayerControllerCompenant.hpp"

Player::Player() : Entity()
{
    DEBUG("Player init");
    this->initSprite("assets/player.png", {0, 0, this->PLAYER_SIZE, this->PLAYER_SIZE});
    for (int i = 0; i < 1; i++) {
        this->_compenants.push_back(new PlayerControllerCompenant(this));
    }
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
