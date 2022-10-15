/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Map
*/

#pragma once

#include "SFML.hpp"
#include "Player.hpp"
#include "Exit.hpp"

class Map {
    constexpr static int TILE_SIZE = 32;
    public:
        Map(Player &player, Exit &exit);
        ~Map();

        void initMap(std::string path, Player &player, Exit &exit);
        void initMapSprite();
        void drawMap(sf::RenderTarget &window);
        void updateMap();
        CollisionType::CollisionType isCollide(sf::FloatRect rect);

    protected:
    private:
        sf::Vector2i _size;
        sf::Texture _texture;
        std::vector<std::vector<int>> _map;
        std::vector<std::vector<sf::Sprite>> _mapSprite;
};
