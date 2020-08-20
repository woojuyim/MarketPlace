#include "../includes/User.h"

#include <string>

User::User(std::string username, std::string password){
    this->username = username;
    this->password = password;
    this->money = 100;
    numofPears = 0;
    numofApples = 0;

}