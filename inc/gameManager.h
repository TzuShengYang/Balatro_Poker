#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "start.h"
#include "loginSystem.h"
#include "mainMenu.h"
#include "quit.h"

class GameManager{
    private:
        string user;

        void initial_setting();
        void run_start();
        void run_login();
        void run_main_menu();
        void run_quit();
        void run_setting();
        void run_store();
        void run_poker();

    public:
        void run_game();
};

#endif