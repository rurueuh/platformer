/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Exit
*/

#pragma once

#include "Entity.hpp"

class Exit : public Entity {
    constexpr static int EXIT_SIZE = 32;
    public:
        Exit();
        ~Exit() = default;

        void removeEntity() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
};
