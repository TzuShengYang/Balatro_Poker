#include "gameManager.h"

using namespace std;

void GameManager::run_game(){
    initial_setting();
    run_start();
}

void GameManager::initial_setting(){
    system("stty -icanon -echo");
}

void GameManager::run_start(){
    start start_UI;
    start_UI.display();
    run_login();
}

void GameManager::run_login(){
    LoginSystem loginSystem_UI;
    user = loginSystem_UI.display_UI();
    if (user == "_") run_start();
    else run_main_menu();
}

void GameManager::run_main_menu(){
    MainMenu mainMenu_UI;
    int choice = mainMenu_UI.display_UI(user);
    switch (choice){
        case 0:
            run_quit();
            break;
        /*
        case 1:
            run_poker();
            break;
        case 2:
            run_store();
            break;
        case 3:
            run_setting();
            break;
        */
        default:
            break;
    }
}

void GameManager::run_quit(){
    Quit quit_UI;
    int choice = quit_UI.display_UI();
    if (choice){
        run_main_menu();
    }
}
