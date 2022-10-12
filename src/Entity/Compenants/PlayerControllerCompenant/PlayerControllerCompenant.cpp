/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** PlayerControllerCompenant
*/

#include "PlayerControllerCompenant.hpp"

PlayerControllerCompenant::PlayerControllerCompenant(Entity *entityLink) : Compenant(entityLink)
{
    this->initCompenant(true, true, true);
    this->initVariable();
    DEBUG("PlayerControllerCompenant init");
}

PlayerControllerCompenant::~PlayerControllerCompenant()
{
    DEBUG("PlayerControllerCompenant remove");
}

void PlayerControllerCompenant::remove()
{
    this->~PlayerControllerCompenant();
    delete this->mouvementCompenant;
}

void PlayerControllerCompenant::initVariable()
{
    this->mouvementCompenant = new MouvementCompenant(this->_entity);
}

void PlayerControllerCompenant::update(const float dt)
{
    // DEBUG("MouvementCompenant update");
    this->mouvementCompenant->update(dt);
    bool isMoving = false;
    bool goUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    bool goDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool goLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    bool goRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    float speed = this->mouvementCompenant->getAcceleration() * dt;
    if (goUp) {
        this->mouvementCompenant->addVelocity(sf::Vector2f(0, -speed));
        this->mouvementCompenant->setMovingY(true);
    } else if (goDown) {
        this->mouvementCompenant->addVelocity(sf::Vector2f(0, speed));
        this->mouvementCompenant->setMovingY(true);
    } else {
        this->mouvementCompenant->setMovingY(false);
    }
    if (goLeft) {
        this->mouvementCompenant->addVelocity(sf::Vector2f(-speed, 0));
        this->mouvementCompenant->setMovingX(true);
    } else if (goRight) {
        this->mouvementCompenant->addVelocity(sf::Vector2f(speed, 0));
        this->mouvementCompenant->setMovingX(true);
    } else {
        this->mouvementCompenant->setMovingX(false);
    }
}

void PlayerControllerCompenant::render(sf::RenderTarget &target)
{
    this->mouvementCompenant->render(target);
}
