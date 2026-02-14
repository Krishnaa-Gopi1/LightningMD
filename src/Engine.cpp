//defines functions in Engine class 

#include "Engine.hpp"
#include<iostream>

void Engine::process(const std::vector<Tick>& ticks){     //takes vector of Ticks and processes them
    for(const auto& tick : ticks){                        //iterate through each tick
        handle_tick(tick);                                //call individual Tick handler -> handle_tick()
    }
}

void Engine::handle_tick(const Tick& tick){              //handles individual Tick data
    std::cout<< "Timestamp : " << tick.timestamp         //print Tick data
             << " " << "price : " << tick.price
             << " " << "quantity : " << tick.quantity
             << std::endl ;
}