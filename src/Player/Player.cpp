/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Player
*/

#include "Player.hpp"

Player::Player() : Entity()
{
    DEBUG("Player init");
}

Player::~Player()
{
    DEBUG("Player remove");
}

void Player::removeEntity()
{
    DEBUG("Player remove");
}

void Player::update(const float dt)
{
    DEBUG("Player update");
}

void Player::render(sf::RenderTarget &target)
{
    DEBUG("Player render");
}
