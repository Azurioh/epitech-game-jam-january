/*
** EPITECH PROJECT, 2025
** JAM
** File description:
** JAM
*/

#ifndef JAM_HPP_
#define JAM_HPP_

    #include <memory>
    #include <vector>
    #include <raylib.h>
    #include <memory>

    #include "Scenes/IScene.hh"

    enum SceneType {
        MAIN_MENU,
        SETTINGS_SCENE,
    };

class JAM {
    public:
        JAM();
        ~JAM();
        void gameLoop(void);
        void UpdateWindowSize();

    private:
        int screenWidth;
        int screenHeight;
        std::size_t _currentScene;
        std::vector<std::unique_ptr<Game::IScene>> _scenes;
};

#endif /* !JAM_HPP_ */
