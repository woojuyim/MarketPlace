#pragma once
#include <string>

class User{
public:
    User(std::string username, std::string password);
    
    std::string getUsername(){return username;}
    std::string getPassword(){return password;}
    int getApples(){return numofApples;}
    int getPears(){return numofPears;}
    int getMoney(){return money;}

    void changeApples(int change){numofApples += change;}
    void changePears(int change){numofPears += change;}
    void changeMoney(int change){money += change;}

private:
    std::string username;
    std::string password;
    int numofApples;
    int numofPears;
    int money;
    


};