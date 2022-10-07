/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** EntityInit
*/

#include "Entity.hpp"

void Entity::initSprite(const std::string textureFile)
{
    this->_image = new image_t;
    if (!this->_image->texture.loadFromFile(textureFile))
        ERROR("Error loading texture file : " + textureFile);
    this->_image->sprite.setTexture(this->_image->texture);
    DEBUG("Entity sprite init");
}

void Entity::initSprite(const std::string textureFile, const sf::IntRect rect)
{
    this->initSprite(textureFile);
    this->_image->sprite.setTextureRect(rect);
    DEBUG("Entity sprite init with rect");
}