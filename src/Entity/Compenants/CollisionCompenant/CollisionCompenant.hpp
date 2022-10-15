/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** ExempleCompenant
*/

#pragma once

#include "Compenant.hpp"
#include "Map.hpp"

class CollisionCompenant : public Compenant {
    public:
        CollisionCompenant(Entity *entityLink, Map *map = nullptr);
        ~CollisionCompenant();
        void remove() override;

        void initVariable() override;
        void setMap(Map *map) { this->_map = map; };
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

        CollisionType::CollisionType checkCollision(sf::FloatRect offset = {0, 0, 0, 0});

    protected:
    private:
        Map *_map;
        sf::RectangleShape _shape;
        sf::FloatRect _offset;
};
