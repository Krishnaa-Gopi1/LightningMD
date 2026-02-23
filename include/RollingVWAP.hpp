//definition for RollingVWAP class
//keeps track of volume weighted average price (vwap) for a fixed window size
//vwap = sum of (price*quantity)/sum of (quantity)

#pragma once
#include<deque> //for the buffer_
#include "Tick.hpp" 

class RollingVWAP{                                        //calculates and returns latest VWAP 
    public:
    explicit RollingVWAP(size_t window);                  //initialize the object , takes a window size

    void add_tick(const Tick& tick);                      //function that takes a Tick and adds it to the buffer_
    double get_vwap() const;                              //funtion that returns the rolling vwap for window size

    private:
    size_t window_;                                       //window size
    std::deque<Tick> buffer_;                             //double ended queue that keeps the latest ticks

    double sum_px_qty_;                                   //stores sum of price * quantity of ticks in the buffer
    double sum_qty_;                                      //stores quaantity of ticks in the buffer
};