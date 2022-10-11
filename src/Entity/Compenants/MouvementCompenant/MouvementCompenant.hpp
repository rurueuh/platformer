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

        void setMoving(bool moving = true) { this->_isMoving = moving; }

    protected:
    private:
        sf::Vector2f _velocity;
        sf::Vector2f _maxVelocity;
        float _acceleration;
        float _deceleration;
        bool _isMoving;
        
};
