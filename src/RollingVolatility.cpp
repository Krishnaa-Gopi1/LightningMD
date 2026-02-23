//definition of RollingVolatility class

#include "RollingVolatility.hpp"
#include<cmath>

RollingVolatility::RollingVolatility(size_t window)       //creating RollingVolatility object
    : window_(window),                                    //window size
      sum_px_sq_(0.0),                                    //squared price sum is initialized as 0
      sum_px_(0.0) {}                                     //sum of prices is initialized as 0

void RollingVolatility::add_tick(const Tick& tick){       //adds tick to buffer and calculates rolling volatility
    buffer_.push_back(tick);                              //add new tick to buffer
    sum_px_sq_ += tick.price*tick.price;                  //update rolling square sum of price
    sum_px_ += tick.price;                                //update rolling sum of square

    if(buffer_.size() > window_){                         //if buffer size exceeds window size
        const Tick& old = buffer_.front();                //store the oldest tick in the buffer in old
        sum_px_sq_ -= old.price*old.price;                //update rolling sum of square of price
        sum_px_ -= old.price;                             //update rolling sum of price
        buffer_.pop_front();                              //remove oldest tick from the buffer
    }
}

double RollingVolatility::get_volatility() const{         //calculates rolling volatility
    size_t n = buffer_.size();                            //store size of buffer in n

    if(n<2) return 0.0;                                   //if less than  2 ticks in buffer return 0
    
    double mean = sum_px_ /n;                             //calculate mean
    double variance = (sum_px_sq_ /n ) - (mean*mean);     //calculate variance
    return std::sqrt(variance);                           //return standard deviation
    
}