#include "../includes/UserManager.h"
#include "../includes/User.h"
#include <iostream>
#include <string>
#include <vector>
UserManager::UserManager(){
    this->currentUser = nullptr;
}
UserManager::~UserManager(){
    for(auto user: Users){
        delete user;
    }
}
void UserManager::create(){
    std::string username, password;
    std::cout << "Enter a username \n";
    std::cin >> username;
    std::cout << "Enter a password \n";
    std::cin >> password;
    for(auto user: Users){
        if(user->getUsername() == username || user->getPassword() == password){
            std::cout << "Account already exists with that username or password \n";
            return;
        }
    }
    std::cout << "Account Created \n";
    User *user = new User(username, password);
    Users.push_back(user);
    
}
void UserManager::login(){
     std::string username, password;
    std::cout << "Enter a username \n";
    std::cin >> username;
    std::cout << "Enter a password \n";
    std::cin >> password;
    for(auto user: Users){
        if(user->getUsername() == username && user->getPassword() == password){
            std::cout << "User found\n";
            currentUser = user;
            return;
        }
    }
    std::cout << "User not found. Create an account or enter the right credentials \n";
    return;
}
void UserManager::run(){
    while(true){
        int x;
        std::cout << "Please create an account or login \n"
                << "Press 1 to create or press 2 to login \n";
        std::cin >> x;
        if(x == 1){
            create();
        } else if(x == 2){
            login();
            if(currentUser != nullptr){
                break;
            }
        } else{
            std::cout << "Press 1 or 2 \n";
        }
    }

}