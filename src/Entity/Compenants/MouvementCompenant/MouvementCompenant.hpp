/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** MouvementCompenant
*/

#pragma once

#include "Compenant.hpp"

class MouvementCompenant : public Compenant {
    public:
        MouvementCompenant(Entity *entityLink);
        ~MouvementCompenant();
        void remove() override;

        void initVariable() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;


        // getter
        float getAcceleration() const { return this->_acceleration; }
        float getDeceleration() const { return this->_deceleration; }
        sf::Vector2f getVelocity() const { return this->_velocity; }
        sf::Vector2f getMaxVelocity() const { return this->_maxVelocity; }

        // setter
        void setMovingX(bool moving = true) { this->_isMovingX = moving; }
        void setMovingY(bool moving = true) { this->_isMovingY = moving; }
        void setVelocity(sf::Vector2f velocity) { this->_velocity = velocity; }
        void addVelocity(sf::Vector2f velocity) { this->_velocity += velocity; }

    protected:
    private:
        sf::Vector2f _velocity;
        sf::Vector2f _maxVelocity;
        float _acceleration;
        float _deceleration;
        bool _isMovingX;
        bool _isMovingY;
        
};
