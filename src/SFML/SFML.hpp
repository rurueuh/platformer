/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** SFML
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include "../../lib/lib.hpp"

#define DEBUG(x) std::cout << "DEBUG : " <<  x << std::endl;
#define ERROR(x) throw std::runtime_error((std::string) "ERROR : " + x);

typedef struct {
    sf::Sprite sprite;
    sf::Texture texture;
} image_t;

enum CompenantType {
    PLAYER_CONTROLLER_COMPENANT,
    COLLISION_COMPENANT,
    MOUVEMENT_COMPENANT,
    GRAVITY_COMPENANT,
};

namespace CollisionType {
    enum CollisionType {
        None = 0,
        Block,
        Exit,
    };
}
