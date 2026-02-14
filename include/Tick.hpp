//defines a Tick 
//Tick is the minimum price increase or decrease of a security

#pragma once
#include<string>
#include<cstdint>

struct Tick{
    std::int64_t timestamp;
    double price;
    int quantity;
};
