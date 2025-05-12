#include "loginSystem.h"

#include <iomanip>

using namespace std;

void LoginSystem::initUserFile(){
    ifstream infile(userFile);
    if (!infile.good()) {
        ofstream outfile(userFile);
        outfile << "{}";
        outfile.close();
    }
}

json LoginSystem::loadUsers(){
    ifstream file(userFile);
    json users;
    file >> users;
    return users;
}

void LoginSystem::saveUsers(const json& users){
    ofstream file(userFile);
    file << users.dump(4);
}

LoginSystem::LoginSystem(){
    userFile = "users.json";
    initUserFile();
}

bool LoginSystem::registerUser(const string& username, const string& password){
    json users = loadUsers();
    char temp;
    if (users.contains(username)) {
        cout << "Username already EXISTS\n";
        cout << "Press any key to register again...";
        cin >> temp;
        return false;
    }
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

        //using w and s to controll the selected button
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

    return up;
}

void LoginSystem::display_UI(){
    
bool up = loginMenu();
    char input = '=';
    if (up){
        string username;
        string password;
        while (true){
            // username and password initializing
            username = "";
            password = "";
            do {
                if (input == '-' && username.length() > 0) username = username.substr(0, username.length() - 1);
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

            if (loginUser(username, password)) break;
        }
    } else if (!up){
        while (true){
            // username and password initializing
            string username = "";
            string password = "";
    
            do {
                if (input == '-' && username.length() > 0) username = username.substr(0, username.length() - 1);
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

            if (registerUser(username, password)) break;
        }
    }
}