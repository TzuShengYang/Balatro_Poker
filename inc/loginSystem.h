#ifndef _LOGINSYSTEM_H_
#define _LOGINSYSTEM_H_

#include "json.hpp"

#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

class LoginSystem{
private:
    string userFile;

    void initUserFile();
    json loadUsers();
    void saveUsers(const json& users);

    bool registerUser(const string& username, const string& password);
    bool loginUser(const string& username, const string& password);
    bool validInput(char input);

    bool userExist(const string& username);

public:
    LoginSystem();
    string display_UI();
    bool loginMenu();
};

#endif