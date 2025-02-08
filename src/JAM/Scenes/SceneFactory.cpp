/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** SceneFactory
*/

#include "SceneFactory.hh"
#include "LevelsScenes/LevelScene.hpp"

Game::SceneFactory::SceneFactory()
{
}

Game::SceneFactory::~SceneFactory()
{
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createMainMenu()
{
    return std::unique_ptr<Game::MainMenu>(new Game::MainMenu);
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createLevels()
{
    return std::unique_ptr<Game::LevelsPage>(new Game::LevelsPage);
}

std::unique_ptr<Game::IScene> Game::SceneFactory::createLevelScene(int levelNumber)
{
    return std::make_unique<Game::LevelScene>(levelNumber);
}
