//defines functions in Engine class 

#include "Engine.hpp"
#include<iostream>

Engine::Engine(size_t window)                             //new Engine object initialization
    : vwap_(window),                                      //RollingVWAP object takes window size
      vol_(window) {}                                     //RollingVolatility object takes window size


void Engine::process(const std::vector<Tick>& ticks){     //takes vector of Ticks and processes them
    for(const auto& tick : ticks){                        //iterate through each tick
        handle_tick(tick);                                //call individual Tick handler -> handle_tick()
    }
}

void Engine::handle_tick(const Tick& tick){              //handles individual Tick data
    vwap_.add_tick(tick);                                //adds tick to buffer and updates rolling VWAP
    vol_.add_tick(tick);                                 //adds tick to buffer and updates rolling volatility
    std::cout<< "Timestamp : " << tick.timestamp         //print Tick data
             << " " << "price : " << tick.price
             << " " << "quantity : " << tick.quantity
             << " " << "VWAP : " << vwap_.get_vwap()     //print VWAP
             << " " << "volatility : " << vol_.get_volatility() //print volatility
             << std::endl ;
}