//defines Engine class and declares functions that handle Ticks

#pragma once
#include<vector>
#include "Tick.hpp"
#include "RollingVWAP.hpp"
#include "RollingVolatility.hpp"

class Engine{                                             //Engine class definition
    public:                                               //public section
    explicit Engine(size_t window);                       //creating an Engine object requires window size
    void process(const std::vector<Tick>& ticks);         //main function that takes in a vector of Ticks and processes them

    private:                                              //private section
    void handle_tick(const Tick& tick);                   //called in the process() function to handle each tick individually
    RollingVWAP vwap_;                                    //RollingVWAP object to use through Engine
    RollingVolatility vol_;                               //RollingVolatility object to use through Engine
};