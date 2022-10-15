/*
** EPITECH PROJECT, 2022
** platformer
** File description:
** Map
*/

#include "Map.hpp"
#include "Game.hpp"
#include "CollisionCompenant.hpp"

Map::Map(Player &player)
{
    _texture.loadFromFile("assets/map.png");
    this->initMap("assets/map.txt", player);
    this->initMapSprite();
}

void Map::initMap(std::string path, Player &player)
{
    std::ifstream file(path);
    std::string line;
    std::vector<int> tmp;
    int i = 0;

    if (!file.is_open()) {
        std::cerr << "Error: Can't open file" << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '0')
                tmp.push_back(0);
            else if (line[j] == '1')
                tmp.push_back(1);
            else if (line[j] == '2') {
                player.getSprite().setPosition(j * TILE_SIZE, i * TILE_SIZE);
                CollisionCompenant *compenant = (CollisionCompenant *) player.getCompenant(CompenantType::COLLISION_COMPENANT);
                compenant->setMap(this);
                tmp.push_back(2);
            }
        }
        this->_map.push_back(tmp);
        tmp.clear();
        i++;
    }
    this->_size.x = i;
    this->_size.y = this->_map[0].size();
}

void Map::initMapSprite()
{
    sf::Sprite tmp;
    std::vector<sf::Sprite> tmp2;

    for (int i = 0; i < this->_size.x; i++) {
        for (int j = 0; j < this->_size.y; j++) {
            tmp.setTexture(this->_texture);
            tmp.setPosition(j * this->TILE_SIZE, i * this->TILE_SIZE);
            tmp2.push_back(tmp);
        }
        this->_mapSprite.push_back(tmp2);
        tmp2.clear();
    }
}

Map::~Map()
{
}

void Map::drawMap(sf::RenderTarget &window)
{
    for (int i = 0; i < this->_size.x; i++) {
        for (int j = 0; j < this->_size.y; j++) {
            if (this->_map[i][j] == 1)
                window.draw(this->_mapSprite[i][j]);
        }
    }
}

bool Map::isCollide(sf::FloatRect rect)
{
    int x = rect.left / this->TILE_SIZE;
    int y = rect.top / this->TILE_SIZE;
    if (this->_map[y][x] == 1 && this->_mapSprite[y][x].getGlobalBounds().intersects(rect))
        return true;
    return false;
}

void Map::updateMap()
{
}
