/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MoabBlue
*/

#ifndef MOABBLUE_HPP_
#define MOABBLUE_HPP_

#include "../AMob.hpp"

class MoabBlueMob : public Game::Mob::AMob {
    public:
        MoabBlueMob();
        ~MoabBlueMob();

    protected:
    private:
    int move_mob();

};

#endif /* !MOABBLUE_HPP_ */
