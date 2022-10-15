/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** ExempleCompenant
*/

#pragma once

#include "Compenant.hpp"
#include "Map.hpp"

namespace CollisionType {
    enum CollisionType {
        None = 0,
        Block,
    };
}

class CollisionCompenant : public Compenant {
    public:
        CollisionCompenant(Entity *entityLink, Map *map = nullptr);
        ~CollisionCompenant();
        void remove() override;

        void initVariable() override;
        void setMap(Map *map) { this->_map = map; };
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

        bool checkCollision(sf::FloatRect offset);

    protected:
    private:
        Map *_map;
        sf::RectangleShape _shape;
        sf::FloatRect _offset;
};
