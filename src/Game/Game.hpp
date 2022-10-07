/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#pragma once

#include "SFML.hpp"
#include "State.hpp"
#include "GameState.hpp"

class Game {
    public:
        Game();
        ~Game();

        static Game &getInstance() {
            static Game instance;
            return instance;
        }

        // INIT
        void initWindow();
        void initState();
        void initGameState();

        // REMOVER
        void removeState();

        void run();

    protected:
    private:
        void update();
        void draw();

        sf::Font _font;

        sf::RenderWindow _window;

        std::vector<State *> *_state;

};
