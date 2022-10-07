/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Entity
*/

#pragma once

#include "SFML.hpp"

class Entity {
    public:
        Entity();
        ~Entity();

        // Functions
        virtual void update(const float dt) = 0;
        virtual void render(sf::RenderTarget &target) = 0;

        // automatic update template with compenants
        void autoUpdate(const float dt);
        void autoRender(sf::RenderTarget &target);

        // all entitys static lists
        static std::vector<Entity *> _allEntity;

        // compenants


        // getters

        // setters

    protected:
    private:
};
