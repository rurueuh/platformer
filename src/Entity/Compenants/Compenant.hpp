/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Compenant
*/

#pragma once

#include "SFML.hpp"
#include "Entity.hpp"

class Compenant {
    public:
        Compenant(Entity *entity);
        ~Compenant();

        virtual void remove() = 0;
        virtual void initCompenant(bool drawable = true, bool updateable = true, bool active = true) {
            this->_active = active; this->_updateable = updateable; this->_drawable = drawable;
        };
        virtual void initVariable() = 0;

        void setActive(bool active = true) { _active = active; }
        void setDrawable(bool drawable = true) { _drawable = drawable; }
        void setUpdateable(bool updateable = true) { _updateable = updateable; }

        bool isActive() const { return _active; }
        bool isDrawable() const { return _drawable; }
        bool isUpdateable() const { return _updateable; }

        virtual void update(const float dt) = 0;
        virtual void render(sf::RenderTarget &target) = 0;

    protected:
        bool _active = true;
        bool _drawable = true;
        bool _updateable = true;

        Entity *_entity = nullptr;
    private:
};
