/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MoabRedMob
*/

#include "MoabRedMob.hpp"

MoabRedMob::MoabRedMob()
{
    _texture = LoadTexture("asset/bloons/MOAB_red.png");
    load();
}

MoabRedMob::~MoabRedMob()
{
    UnloadTexture(_texture);
}

void MoabRedMob::load()
{
    _widthScale = 0.7;
    _heightScale = 0.7;
    _rotation = 0;

    _speed = 3.2 - (3);
    _mapValue = 2;

    _mapPos = {-1, -1};
    _position = {-1, -1};
    _nextPosition = {-1, -1};
    _time = 0;

    _visible = true;
    _stopMoving = false;

    _hp = 1164;
    _type = Game::Mob::MOAB_RED_MOB;
}
