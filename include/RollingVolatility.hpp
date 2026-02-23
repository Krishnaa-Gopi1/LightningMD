//definition for the RollingVolatility class

#pragma once
#include<deque>                                           //for the buffer
#include "Tick.hpp"

class RollingVolatility{                                  //calculates and returns latest volatility
    public:
    explicit RollingVolatility(size_t window);            //to create the object , the window size must be known

    void add_tick(const Tick& tick);                      //adds a new tick to the buffer
    double get_volatility() const;                        //gets the volatility of the ticks in the buffer

    private:
    size_t window_;                                       //window size
    std::deque<Tick> buffer_;                             //double ended queue that keeps the latest ticks

    double sum_px_sq_;                                    //stores sum of (price * price) of ticks in the buffer
    double sum_px_;                                       //stores sum of prices of ticks in the buffer
};