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
    sf::FloatRect rect = this->_entity->getSprite().getGlobalBounds();
    this->_offset = sf::FloatRect(2, 2, -4, -4);
    this->_shape.setSize(sf::Vector2f(rect.width + this->_offset.width, rect.height + this->_offset.height));
    this->_shape.setFillColor(sf::Color::Transparent);
    this->_shape.setOutlineColor(sf::Color::Green);
    this->_shape.setOutlineThickness(1);
    this->_shape.setPosition(rect.left, rect.top);
}

void CollisionCompenant::update(const float dt)
{
    sf::FloatRect rect = this->_entity->getSprite().getGlobalBounds();
    rect = sf::FloatRect(rect.left + this->_offset.left, rect.top + this->_offset.top, rect.width + this->_offset.width, rect.height + this->_offset.height);
    this->_shape.setPosition(
        rect.left,
        rect.top
    );
}

bool CollisionCompenant::checkCollision(sf::FloatRect offset)
{
    if (this->_map == nullptr)
        return CollisionType::None;
    sf::FloatRect rect = this->_shape.getGlobalBounds();
    sf::FloatRect rectWithOffset = {rect.left + offset.left, rect.top + offset.top, rect.width + offset.width, rect.height + offset.height};
    if (this->_map->isCollide(rectWithOffset) == true) {
        return CollisionType::Block;
    }
    return CollisionType::None;
}

void CollisionCompenant::render(sf::RenderTarget &target)
{
    target.draw(this->_shape);
}
