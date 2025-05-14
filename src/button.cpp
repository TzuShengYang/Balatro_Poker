#include "button.h"

using namespace std;

button::button(){

}

button::button(int idx){
    buttonIndex = idx;
    if (idx) selected = false;
    else selected = true;
}