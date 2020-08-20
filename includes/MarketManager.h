#pragma once
#include "market.h"
#include <string>
#include <vector>

class MarketManager{
public:
    MarketManager();
    void run();
    Market* getCurrentMarket(){ return currentMarket;}


private:
    Market* currentMarket;
    std::vector<Market*> markets;


};