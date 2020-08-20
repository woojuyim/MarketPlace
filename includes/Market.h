#pragma once
#include <string>

class Market{
public:
    Market(std::string name, int apples, int pears, int appleprice, int pearprice);

    std::string getName(){return name;}

    void changenumofApples(int change){numofApples += change;}
    void changenumofPears(int change){numofPears += change;}
    void changeMoney(int change){money += change;}

    int getMaxMoney(){return maxMoney;}
    int getMoney(){return money;}
    int getApples(){return numofApples;}
    int getPears(){return numofPears;}
    int getApplePrice(){return priceofApples;}
    int getPearPrice(){return priceofPears;}



private:
    int money;
    int maxMoney;
    std::string name;
    int priceofApples;
    int priceofPears;
    int numofApples;
    int numofPears;



};