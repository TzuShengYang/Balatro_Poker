#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "start.h"
#include "loginSystem.h"
#include "mainMenu.h"

class GameManager{
    private:
        string user;

        void initial_setting();
        void run_start();
        void run_login();
        void run_main_menu();

    public:
        void run_game();
};

#endif