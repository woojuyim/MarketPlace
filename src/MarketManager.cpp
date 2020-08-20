#include "../includes/MarketManager.h"
#include <iostream>
#include <string>
#include <vector>

MarketManager::MarketManager(){
    Market *market1 = new Market("Under the Bridge", 7, 7, 10, 10);
    Market *market2 = new Market("Great Apple", 20, 0, 5, 10);
    Market *market3 = new Market("Willow Tree", 10, 30, 10, 5);
    Market *market4 = new Market("Garbage Can", 1, 0, 1, 500); 
    markets.push_back(market1);
    markets.push_back(market2);
    markets.push_back(market3);
    markets.push_back(market4);

}
void MarketManager::run(){
    while(true){
        std::cout << "Select a market out of the generated markets \n";
        for(int i=0;i<markets.size();++i){
            std::cout << i + 1 << ". " << markets[i]->getName() << std::endl
                    << "Number of Apples: " << markets[i]->getApples() << " "
                    << "Number of Pears: " << markets[i]->getPears() << "\n\n";
        }
        std::cout << "Press the number of the corresponding market\n";
        int input;
        std::cin >> input;
        if(markets[input - 1] != nullptr){
            currentMarket = markets[input-1];
            break;
        } else{
            std::cout << "Select a number \n";
        }
    }
}
