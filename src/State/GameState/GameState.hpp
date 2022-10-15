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
#include "Exit.hpp"

class GameState : public State {
    public:
        GameState();
        ~GameState();

        void removeState() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

        Player _player;
        Exit _exit;
        Map *_map;
    protected:
    private:
};
