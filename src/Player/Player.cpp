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
#include "Game.hpp"

Player::Player() : Entity()
{
    DEBUG("Player init");
    this->initSprite("assets/player.png", {0, 0, this->PLAYER_SIZE, this->PLAYER_SIZE});
    this->addCompenant(new PlayerControllerCompenant(this), CompenantType::PLAYER_CONTROLLER_COMPENANT);
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
    CollisionCompenant *collision = static_cast<CollisionCompenant *>(this->getCompenant(CompenantType::COLLISION_COMPENANT));
    if (collision->checkCollision() == CollisionType::Exit) {
        Game::getInstance().getWindow().close();
    } else if (collision->checkCollision() == CollisionType::Spike) {
        DEBUG("Spike");
        GameState *gameState = static_cast<GameState *>(Game::getInstance().getState());
        gameState->reset();
    }
}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->_image->sprite);
}
