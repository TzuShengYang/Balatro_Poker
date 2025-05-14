#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "button.h"

#include <vector>
#include <string>

using namespace std;


class MainMenu{
    private:
        vector<button> buttons;
        int currentIndex;
        int buttonsNumber;
        string username;

        void display_user_UI();
        void display_buttons();
    public:
        MainMenu();
        int display_UI(string UESRNAME);
};

#endif