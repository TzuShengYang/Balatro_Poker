#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "start.h"
#include "loginSystem.h"

class GameManager{
    private:
        void initial_setting();
        void run_start();
        void run_login();

    public:
        void run_game();
};

#endif