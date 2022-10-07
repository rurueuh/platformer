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
        // Init
        void initSprite(const std::string filepath);
        void initSprite(const std::string filepath, const sf::IntRect rect);

        // Remover
        virtual void removeEntity() = 0;

        // Functions
        virtual void update(const float dt) = 0;
        virtual void render(sf::RenderTarget &target) = 0;


        // automatic update template with compenants
        void autoUpdate(const float dt);
        void autoRender(sf::RenderTarget &target);

        // all entitys static lists
        static std::vector<Entity *> _allEntity;
        static std::vector<Entity *> getAllEntity() { return _allEntity; };

        // compenants

        // getters

        // setters

    protected:
        image_t *_image;
    private:
};
