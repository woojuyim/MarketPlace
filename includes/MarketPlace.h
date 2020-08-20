#pragma once
#include "MarketManager.h"
#include "Market.h"
#include "User.h"
#include <iostream>
#include <string>

class MarketPlace{
public:
    MarketPlace(MarketManager *m, User *u);
    void run();
    void buy();
    void sell();
    bool calculateDeal(int numofbuy, bool isApple);
    bool calculateSell(int numofsell, bool isApple);



private:
    MarketManager *manager;
    User *u;
    Market* m;

};