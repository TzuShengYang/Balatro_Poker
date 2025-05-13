#include "loginSystem.h"

#include <iomanip>

using namespace std;

void LoginSystem::initUserFile(){
    ifstream infile(userFile); // open users.json file

    // if the file is "not good", then initialize the .json file
    if (!infile.good()) {
        ofstream outfile(userFile);
        outfile << "{}";
        outfile.close();
    }
}

json LoginSystem::loadUsers(){
    // to find the user in users.json file
    ifstream file(userFile);
    json users;
    file >> users;
    return users;
}

void LoginSystem::saveUsers(const json& users){
    // add the user into ussers.json (have to check whether the user is exist)
    ofstream file(userFile);
    file << users.dump(4);
}

LoginSystem::LoginSystem(){
    userFile = "users.json"; // filename
    initUserFile();
}

bool LoginSystem::registerUser(const string& username, const string& password){
    json users = loadUsers();
    char temp;

    // user not found
    if (users.contains(username)) {
        cout << "Username already EXISTS\n";
        cout << "Press any key to register again...";
        cin >> temp;
        return false;
    }

    //user found in users.json
    users[username] = { {"password", password} };
    saveUsers(users);
    cout << "Register successfully!!\n";
    cout << "Press any key to register again...";
    cin >> temp;
    return true;
}

bool LoginSystem::userExist(const string& username){
    json users = loadUsers();
    char temp;

    // user not found
    if (!users.contains(username)){
        cout << "Username NOT FOUND!\n";
        cout << "Press any key to enter username again...";
        cin >> temp;
        return false;
    }
    return true;
}

bool LoginSystem::loginUser(const string& username, const string& password) {
    json users = loadUsers();
    char temp;
    if (users.contains(username) && users[username]["password"] == password) {
        cout << "Login successfully!!\n";
        cout << "Press any key to start playing game...";
        cin >> temp;
        return true;
    }
    cout << "INCORRECT password!!\n";
    cout << "Press any key to enter password again...";
    cin >> temp;
    return false;
}

bool LoginSystem::validInput(char input){
    // only 0 ~ 9, a~z, A~Z are valid input letter
    return (input > 47 && input < 58) || (input > 64 && input < 91) || (input > 96 && input < 123);
}

bool LoginSystem::loginMenu(){
    char input = 'w';
    bool up = true;
    do {
        system("clear");
        cout << "\n\n";
        cout << "  ██████╗  █████╗ ██╗      █████╗ ████████╗██████╗  ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ \n";
        cout << "  ██╔══██╗██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗\n";
        cout << "  ██████╔╝███████║██║     ███████║   ██║   ██████╔╝██║   ██║    ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝\n";
        cout << "  ██╔══██╗██╔══██║██║     ██╔══██║   ██║   ██╔══██╗██║   ██║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗\n";
        cout << "  ██████╔╝██║  ██║███████╗██║  ██║   ██║   ██║  ██║╚██████╔╝    ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║\n";
        cout << "  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n\n";
        cout << "\n\n";

        //using w and s to control the selected button
        if (input == 'W' || input == 'w'){ 
            up = true;
            cout << "                                    #===============================#\n";
            cout << "                                    |             Log In            |\n";
            cout << "                                    #===============================#\n\n";
            cout << "                                    .- - - - - - - - - - - - - - - -.\n";
            cout << "                                    |            Sign  Up           |\n";
            cout << "                                    '- - - - - - - - - - - - - - - -'\n\n";
        } else if (input == 'S' || input == 's'){
            up = false;
            cout << "                                    .- - - - - - - - - - - - - - - -.\n";
            cout << "                                    |             Log In            |\n";
            cout << "                                    '- - - - - - - - - - - - - - - -'\n\n";
            cout << "                                    #===============================#\n";
            cout << "                                    |            Sign  Up           |\n";
            cout << "                                    #===============================#\n\n";
        } else if (up){
            cout << "                                    #===============================#\n";
            cout << "                                    |             Log In            |\n";
            cout << "                                    #===============================#\n\n";
            cout << "                                    .- - - - - - - - - - - - - - - -.\n";
            cout << "                                    |            Sign  Up           |\n";
            cout << "                                    '- - - - - - - - - - - - - - - -'\n\n";
        } else {
            cout << "                                    .- - - - - - - - - - - - - - - -.\n";
            cout << "                                    |             Log In            |\n";
            cout << "                                    '- - - - - - - - - - - - - - - -'\n\n";
            cout << "                                    #===============================#\n";
            cout << "                                    |            Sign  Up           |\n";
            cout << "                                    #===============================#\n\n";
        }
    } while (cin >> input && (input != '='));

    return up; // return the user choice
}

string LoginSystem::display_UI(){
    
bool up = loginMenu();
    char input = '=';

    // Login choice
    if (up){
        string username;
        string password;
        while (true){
            // username and password initializing
            username = "";
            password = "";
            do {
                if (input == '-' && username.length() > 0) username = username.substr(0, username.length() - 1); // using '-' to delete the input
                else if (input == '`' && username.length() == 0) return "_"; // using '`' to back to the starting menu when no input
                else if (validInput(input)) username += input;
    
                system("clear");
                cout << "\n\n";
                cout << "  ██████╗  █████╗ ██╗      █████╗ ████████╗██████╗  ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ \n";
                cout << "  ██╔══██╗██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗\n";
                cout << "  ██████╔╝███████║██║     ███████║   ██║   ██████╔╝██║   ██║    ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝\n";
                cout << "  ██╔══██╗██╔══██║██║     ██╔══██║   ██║   ██╔══██╗██║   ██║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗\n";
                cout << "  ██████╔╝██║  ██║███████╗██║  ██║   ██║   ██║  ██║╚██████╔╝    ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║\n";
                cout << "  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n\n";
                cout << "\n\n                                   Only English letters or numbers are allowed.\n\n";
                cout << "                                             #===============================#\n";
                cout << "                              ACCOUNT NAME:  |" << setw(31) << left << username << "|\n";
                cout << "                                             #===============================#\n\n";
    
            } while (cin >> input && (input != '='));

            if (userExist(username)) break;
        }
        while (true){
            do {
                if (input == '-' && password.length() > 0) password = password.substr(0, password.length() - 1);
                else if (validInput(input)) password += input;
    
                system("clear");
                cout << "\n\n";
                cout << "  ██████╗  █████╗ ██╗      █████╗ ████████╗██████╗  ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ \n";
                cout << "  ██╔══██╗██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗\n";
                cout << "  ██████╔╝███████║██║     ███████║   ██║   ██████╔╝██║   ██║    ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝\n";
                cout << "  ██╔══██╗██╔══██║██║     ██╔══██║   ██║   ██╔══██╗██║   ██║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗\n";
                cout << "  ██████╔╝██║  ██║███████╗██║  ██║   ██║   ██║  ██║╚██████╔╝    ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║\n";
                cout << "  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n\n";
                cout << "\n\n                                   Only English letters or numbers are allowed.\n\n";
                cout << "                                             #===============================#\n";
                cout << "                              ACCOUNT NAME:  |" << setw(31) << left << username << "|\n";
                cout << "                                             #===============================#\n\n";
                cout << "                                             #===============================#\n";
                cout << "                                  PASSWORD:  |" << setw(31) << left << password << "|\n";
                cout << "                                             #===============================#\n\n";
    
            } while (cin >> input && (input != '='));

            if (loginUser(username, password)) return username;
        }
    } else if (!up){
        while (true){
            // username and password initializing
            string username = "";
            string password = "";
    
            do {
                if (input == '-' && username.length() > 0) username = username.substr(0, username.length() - 1); // using '-' to delete the input
                else if (input == '`' && username.length() == 0) return "_"; // using '`' to back to the starting menu when no input
                else if (validInput(input)) username += input;
    
                system("clear");
                cout << "\n\n";
                cout << "  ██████╗  █████╗ ██╗      █████╗ ████████╗██████╗  ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ \n";
                cout << "  ██╔══██╗██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗\n";
                cout << "  ██████╔╝███████║██║     ███████║   ██║   ██████╔╝██║   ██║    ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝\n";
                cout << "  ██╔══██╗██╔══██║██║     ██╔══██║   ██║   ██╔══██╗██║   ██║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗\n";
                cout << "  ██████╔╝██║  ██║███████╗██║  ██║   ██║   ██║  ██║╚██████╔╝    ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║\n";
                cout << "  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n\n";
                cout << "\n\n                                   Only English letters or numbers are allowed.\n\n";
                cout << "                                             #===============================#\n";
                cout << "                              ACCOUNT NAME:  |" << setw(31) << left << username << "|\n";
                cout << "                                             #===============================#\n\n";
    
            } while (cin >> input && (input != '='));
    
            do {
                if (input == '-' && password.length() > 0) password = password.substr(0, password.length() - 1);
                else if (validInput(input)) password += input;
    
                system("clear");
                cout << "\n\n";
                cout << "  ██████╗  █████╗ ██╗      █████╗ ████████╗██████╗  ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ \n";
                cout << "  ██╔══██╗██╔══██╗██║     ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗\n";
                cout << "  ██████╔╝███████║██║     ███████║   ██║   ██████╔╝██║   ██║    ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝\n";
                cout << "  ██╔══██╗██╔══██║██║     ██╔══██║   ██║   ██╔══██╗██║   ██║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗\n";
                cout << "  ██████╔╝██║  ██║███████╗██║  ██║   ██║   ██║  ██║╚██████╔╝    ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║\n";
                cout << "  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n\n\n";
                cout << "\n\n                                   Only English letters or numbers are allowed.\n\n";
                cout << "                                             #===============================#\n";
                cout << "                              ACCOUNT NAME:  |" << setw(31) << left << username << "|\n";
                cout << "                                             #===============================#\n\n";
                cout << "                                             #===============================#\n";
                cout << "                                  PASSWORD:  |" << setw(31) << left << password << "|\n";
                cout << "                                             #===============================#\n\n";
    
            } while (cin >> input && (input != '='));

            if (registerUser(username, password)) return username;
        }
    }
}