#include "mainMenu.h"

#include <iostream>
#include <iomanip>

using namespace std;

/* return 0: quit game
 *   ..   1: setting
 *   ..   2: store
 *   ..   3: play game
 */

 MainMenu::MainMenu(){
    for (int i = 0;i < 4;i++){
        buttons.push_back(button(i));
    }
    buttons[0].name = "quit";
    buttons[1].name = "play";
    buttons[2].name = "store";
    buttons[3].name = "setting";

    currentIndex = 0;
    buttonsNumber = 4;
 }

 void MainMenu::display_user_UI(){
    cout << "\n\n";
    cout << "User:                         ██████╗  █████╗ ██╗      █████╗ ████████╗██████╗  ██████╗ \n";
    cout << setw(30) << username << "██╔══██╗██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗\n";
    cout << "                              ██████╔╝███████║██║     ███████║   ██║   ██████╔╝██║   ██║\n";
    cout << "                              ██╔══██╗██╔══██║██║     ██╔══██║   ██║   ██╔══██╗██║   ██║\n";
    cout << "                              ██████╔╝██║  ██║███████╗██║  ██║   ██║   ██║  ██║╚██████╔╝\n";
    cout << "                              ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ \n";
    cout << "                                      ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ \n";
    cout << "                                      ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗\n";
    cout << "                                      ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝\n";
    cout << "                                      ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗\n";
    cout << "                                      ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║\n";
    cout << "                                      ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n";
    cout << "\n\n\n\n";
 }

 void MainMenu::display_buttons(){
    switch(currentIndex){
        case 0:
            cout << "               #===============#       .- - - - - - - -.       .- - - - - - - -.       .- - - - - - - -.\n";
            cout << "               |      QUIT     |       |      PLAY     |       |     STORE     |       |    SETTING    |\n";
            cout << "               #===============#       '- - - - - - - -'       '- - - - - - - -'       '- - - - - - - -'\n";
            break;
        case 1:
            cout << "               .- - - - - - - -.       #===============#       .- - - - - - - -.       .- - - - - - - -.\n";
            cout << "               |      QUIT     |       |      PLAY     |       |     STORE     |       |    SETTING    |\n";
            cout << "               '- - - - - - - -'       #===============#       '- - - - - - - -'       '- - - - - - - -'\n";
            break;
        case 2:
            cout << "               .- - - - - - - -.       .- - - - - - - -.       #===============#       .- - - - - - - -.\n";
            cout << "               |      QUIT     |       |      PLAY     |       |     STORE     |       |    SETTING    |\n";
            cout << "               '- - - - - - - -'       '- - - - - - - -'       #===============#       '- - - - - - - -'\n";
            break;
        case 3:
            cout << "               .- - - - - - - -.       .- - - - - - - -.       .- - - - - - - -.       #===============#\n";
            cout << "               |      QUIT     |       |      PLAY     |       |     STORE     |       |    SETTING    |\n";
            cout << "               '- - - - - - - -'       '- - - - - - - -'       '- - - - - - - -'       #===============#\n";
            break;
        default:
            break;
    }
 }

int MainMenu::display_UI(string USERNAME){
    char input = 'i';
    username = USERNAME;

    do {
        if (input == 'd' && currentIndex < 3) currentIndex++;
        else if (input == 'a' && currentIndex > 0) currentIndex--;

        system("clear");
        display_user_UI();
        display_buttons();

    } while (cin >> input && input != '=');

    return currentIndex;
}