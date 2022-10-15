/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** GravityCompenant
*/

#pragma once

#include "Compenant.hpp"

class GravityCompenant : public Compenant {
    public:
        GravityCompenant(Entity *entityLink);
        ~GravityCompenant();
        void remove() override;

        bool isGrounded() const { return _grounded; };
        void initVariable() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
        float _force = 0.3;
        float _actualGravity = 0;
        float _maxGravity = 20;
        bool _grounded = false;
};
