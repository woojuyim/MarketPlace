#pragma 
#include "MarketManager.h"
#include "User.h"
#include <vector>
#include <string>
class UserManager{
public:
    UserManager();
    ~UserManager();

    void run();
    void create();
    void login();
    void setMarkets(MarketManager* manager){this->manager = manager;}

    User* getcurrentUser(){return currentUser;}
    std::vector<User*> getUsers(){return Users;}




private:
    MarketManager* manager;
    User* currentUser;
    std::vector<User*> Users;




};