//defines Engine class and declares functions that handle Ticks

#pragma once
#include<vector>
#include "Tick.hpp"

class Engine{                                             //Engine class definition
    public:                                               //public section
    void process(const std::vector<Tick>& ticks);         //main function that takes in a vector of Ticks and processes them

    private:                                              //private section
    void handle_tick(const Tick& tick);                   //called in the process() function to handle each tick individually
};