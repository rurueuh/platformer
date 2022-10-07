/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Player
*/

#pragma once

#include "Entity.hpp"

class Player : public Entity {
    public:
        Player();
        ~Player();

        void removeEntity() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
};
