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
    run_main_menu();
}

void GameManager::run_main_menu(){
    MainMenu mainMenu_UI;
    int choice = mainMenu_UI.display_UI();
}
