#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <string>
using namespace std;

class button{
    public:
        int buttonIndex;
        bool selected;
        string name;
        button();
        button(int idx);
};

#endif