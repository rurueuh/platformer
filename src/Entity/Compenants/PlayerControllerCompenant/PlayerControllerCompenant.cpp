/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** PlayerControllerCompenant
*/

#include "PlayerControllerCompenant.hpp"
#include "GravityCompenant.hpp"

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

void PlayerControllerCompenant::jump()
{
    constexpr int jumpForce = 25;
    static sf::Clock clock;
    if (clock.getElapsedTime().asSeconds() > 0.5) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            clock.restart();
            if (this->_entity->getCompenant(CompenantType::GRAVITY_COMPENANT) != nullptr) {
                GravityCompenant *gravity = dynamic_cast<GravityCompenant *>(this->_entity->getCompenant(CompenantType::GRAVITY_COMPENANT));
                if (gravity->isGrounded()) {
                    this->mouvementCompenant->setVelocity(sf::Vector2f(this->mouvementCompenant->getVelocity().x, -jumpForce));
                }
            }
        }
    }
}

void PlayerControllerCompenant::update(const float dt)
{
    this->mouvementCompenant->update(dt);
    bool isMoving = false;
    bool goLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    bool goRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    
    this->jump();
    float speed = this->mouvementCompenant->getAcceleration() * dt;
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
