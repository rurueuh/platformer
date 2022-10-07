/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** State
*/

#pragma once

#include "SFML.hpp"

class State {
    public:
        State();
        ~State();

        virtual void removeState() = 0;
        virtual void update(const float dt) = 0;
        virtual void render(sf::RenderTarget &target) = 0;

    protected:
    private:
};
