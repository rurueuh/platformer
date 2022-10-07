/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** MouvementCompenant
*/

#pragma once

#include "Compenant.hpp"

class MouvementCompenant : public Compenant {
    public:
        MouvementCompenant(Entity *entity);
        ~MouvementCompenant();
        void remove() override;

        void initVariable() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
};
