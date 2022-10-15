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
#include "Spike.hpp"

class GameState : public State {
    public:
        GameState();
        ~GameState();

        void removeState() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;
        void reset();

        Player *_player;
        Exit *_exit;
        std::vector<Spike *> _spikes;
        Map *_map;

        bool updateEntity = false;
    protected:
    private:
};
