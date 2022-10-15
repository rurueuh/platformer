/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** ExempleCompenant
*/

#include "CollisionCompenant.hpp"

CollisionCompenant::CollisionCompenant(Entity *entityLink, Map *map) : Compenant(entityLink)
{
    this->initCompenant(true, true, true);
    this->_map = map;
    this->initVariable();
    DEBUG("CollisionCompenant created");
}

CollisionCompenant::~CollisionCompenant()
{
    DEBUG("CollisionCompenant destroyed");
}

void CollisionCompenant::remove()
{
    DEBUG("CollisionCompenant removed");
}

void CollisionCompenant::initVariable()
{
    this->_rect = this->_entity->getSprite().getGlobalBounds();
    this->_shape.setSize(sf::Vector2f(this->_rect.width, this->_rect.height));
    this->_shape.setFillColor(sf::Color::Transparent);
    this->_shape.setOutlineColor(sf::Color::Green);
    this->_shape.setOutlineThickness(1);
    this->_shape.setPosition(this->_rect.left, this->_rect.top);
}

void CollisionCompenant::update(const float dt)
{
    this->_rect = this->_entity->getSprite().getGlobalBounds();
    this->_shape.setPosition(this->_rect.left, this->_rect.top);
}

bool CollisionCompenant::checkCollision(sf::FloatRect offset)
{
    if (this->_map == nullptr)
        return false;

    sf::FloatRect rectWithOffset = {this->_rect.left + offset.left, this->_rect.top + offset.top, this->_rect.width + offset.width, this->_rect.height + offset.height};
    if (this->_map->isCollide(rectWithOffset) == true) {
        return true;
    }
    return false;
}

void CollisionCompenant::render(sf::RenderTarget &target)
{
    target.draw(this->_shape);
}
