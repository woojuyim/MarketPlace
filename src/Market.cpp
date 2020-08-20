#include "../includes/Market.h"
#include <iostream>
#include <string>

Market::Market(std::string name, int apples, int pears, int appleprice, int pearprice){
    this->name = name;
    this->numofApples = apples;
    this->numofPears = pears;
    this->priceofApples = appleprice;
    this->priceofPears = pearprice;
    this->money = 500;
    this->maxMoney = 1000;
}

