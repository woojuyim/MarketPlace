#include "../includes/MarketPlace.h"
#include <iostream>


MarketPlace::MarketPlace(MarketManager *m, User *u){
    this->manager = m;
    this->u = u;
    manager->run();
    this->m = manager->getCurrentMarket();

}
bool MarketPlace::calculateSell(int numofsell, bool isApple){
    if(isApple){
        int moneyspent = numofsell *  m->getApplePrice();
        if(moneyspent <= m->getMoney() && numofsell <= u->getApples()){
            return true;
        } else{
            return false;
        }
    }
    else{
        int moneyspent = numofsell *  m->getPearPrice();
        if(moneyspent <= m->getMoney() && numofsell <= u->getApples()){
            return true;
        } else{
            return false;
        }
    }
}
bool MarketPlace:: calculateDeal(int numofbuy, bool isApple){
    if(isApple){
        int moneyspent = numofbuy *  m->getApplePrice();
        if(moneyspent <= u->getMoney() && numofbuy <= m->getApples()){
            return true;
        } else{
            return false;
        }
    }
    else{
        int moneyspent = numofbuy *  m->getPearPrice();
        if(moneyspent <= u->getMoney() && numofbuy <= m->getPears()){
            return true;
        } else{
            return false;
        }
    }
}
void MarketPlace::buy(){
    std::cout << "Current number of Apples: " << m->getApples() << " Current number of Pears: " << m->getPears() << "\n";
    std::cout << "Your money: " << u->getMoney() << "\n";
    std::cout << "Prices of apples: " << m->getApplePrice() << " Prices of pears: " << m->getPearPrice() << "\n";
    std::cout << "What do you want to buy? \n"
            << "1. Apples       2. Pears \n";
    int x;
    std::cin >> x;
    if(x == 1){
        int input;
        std::cout << "How many do you want to buy? \n";
        std::cin >> input;
        if(calculateDeal(input, true)){
            m->changenumofApples(-1 * input);
            u->changeMoney(-1 * input * m->getApplePrice());
            m->changeMoney(input * m->getApplePrice());
            u->changeApples(input);            
            std::cout << "Thank you for the deal! \n\n";
        } else{
            std::cout << "Transaction Failed! Check your money or the market's supply of apples! \n\n";
        }
    } else if(x==2){
        int input;
        std::cout << "How many do you want to buy? \n";
        std::cin >> input;
        if(calculateDeal(input, false)){
            m->changenumofPears(-1 * input);
            u->changeMoney(-1 * input * m->getPearPrice());
            m->changeMoney(input * m->getPearPrice());
            u->changePears(input);        
            std::cout << "Thank you for the deal! \n\n";
        } else{
            std::cout << "Transaction Failed! Check your money or the market's supply of pears!\n\n";
        }
    } 
}
void MarketPlace::sell(){
    std::cout << "Your number of Apples: " << u->getApples()<< " Your number of Pears: " << u->getPears() << "\n";
    std::cout << "Market's money: " << m->getMoney() << "\n";
    std::cout << "Prices of apples: " << m->getApplePrice() << " Prices of pears: " << m->getPearPrice() << "\n";
    std::cout << "What do you want to sell? \n"
            << "1. Apples       2. Pears \n";
    int x;
    std::cin >> x;
    if(x == 1){
        int input;
        std::cout << "How many do you want to sell? \n";
        std::cin >> input;
        if(calculateSell(input, true)){
            u->changeApples(-1 * input);
            m->changeMoney(-1 * input * m->getApplePrice());
            u->changeMoney(input * m->getApplePrice());
            m->changenumofApples(input);            
            std::cout << "Thank you for the deal! \n\n";
        } else{
            std::cout << "Transaction Failed! Check market's money or your supply of apples! \n\n";
        }
    } else if(x==2){
        int input;
        std::cout << "How many do you want to sell? \n";
        std::cin >> input;
        if(calculateSell(input, false)){
           u->changePears(-1 * input);
            m->changeMoney(-1*input * m->getPearPrice());
            u->changeMoney(input * m->getPearPrice());
            m->changenumofPears(input);                 
            std::cout << "Thank you for the deal! \n\n";
        } else{
            std::cout << "Transaction Failed! Check market's money or your supply of pears! \n\n";
        }
    } 
}
void MarketPlace::run(){
    int x; 
    while(true){
        std::cout << "Current market is " << m->getName() << "\n";
        std::cout << "What do you want to do? \n"
                << "1. Buy      2. Sell     3. Change Market      4. Log off\n";
        std::cin>>x;
        if(x == 1){
            buy();
        } else if(x==2){
            sell();
        } else if(x==3){
            manager->run();
            m=manager->getCurrentMarket();
        } else if(x==4){
            break;  
        } else{
            std::cout << "Press 1, 2, or 3 \n";
        }
    }
    
}