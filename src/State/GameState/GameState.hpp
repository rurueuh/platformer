/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** GameState
*/

#pragma once

#include "State.hpp"
#include "Player.hpp"
#include "Map.hpp"

class GameState : public State {
    public:
        GameState();
        ~GameState();

        void removeState() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

        Player _player;
        Map *_map;
    protected:
    private:
};
