/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** ExempleCompenant
*/

#pragma once

#include "Compenant.hpp"

class ExempleCompenant : public Compenant {
    public:
        ExempleCompenant(Entity *entityLink);
        ~ExempleCompenant();
        void remove() override;

        void initVariable() override;
        void update(const float dt) override;
        void render(sf::RenderTarget &target) override;

    protected:
    private:
};
