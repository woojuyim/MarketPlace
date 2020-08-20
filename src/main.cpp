#include "../includes/UserManager.h"
#include "../includes//MarketManager.h"
#include "../includes/MarketPlace.h"
#include <thread>
#include <exception>
#include <iostream>

int main(){
    std::cout << "Welcome to the MarketPlace! \n" 
            << "Generating Markets... \n";
    MarketManager manager;
    UserManager um;
    //User *user = new User("1", "1");
    while(true){
        um.run();
        if(um.getcurrentUser() == nullptr){
            throw "NULLPTR BREAK";
        }
        MarketPlace mp(&manager, um.getcurrentUser());
        // MarketPlace mp(&manager, user);
        mp.run();
        std::cout << "Do you want to continue and log in to another account \n"
                << "1. Yes      2. No \n";
        int x;
        std::cin >> x;
        if(x == 2){
            break;
        }
    }
    std::cout << "Thank you for using the MarketPlace!!! \n";
    return 0;
}