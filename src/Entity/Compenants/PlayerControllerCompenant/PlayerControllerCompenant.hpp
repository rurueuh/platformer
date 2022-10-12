/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** PlayerControllerCompenant
*/

#pragma once

#include "Compenant.hpp"
#include "MouvementCompenant.hpp"

class PlayerControllerCompenant : public Compenant {
    public:
        PlayerControllerCompenant(Entity *entityLink);
        ~PlayerControllerCompenant();
        void remove() override;
        void initVariable() override;

        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
        MouvementCompenant *mouvementCompenant;
};
