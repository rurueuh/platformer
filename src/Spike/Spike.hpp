/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Spike
*/

#pragma once

#include "Entity.hpp"

class Spike : public Entity {
    constexpr static int SPIKE_SIZE = 32;
    public:
        Spike();
        ~Spike() = default;

        void removeEntity() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
};
