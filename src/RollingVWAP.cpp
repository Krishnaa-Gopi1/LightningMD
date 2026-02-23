//definition of the RollingVWAP class

#include "RollingVWAP.hpp"

RollingVWAP::RollingVWAP(size_t window)                   //create the object
    : window_(window),                                    //window_ -> buffer size
      sum_px_qty_(0.0),                                   //the sum of price * quantity of ticks in the buffer is 0 in the beginning
      sum_qty_(0.0) {}                                    //the sum of quantity of ticks in the buffer is 0 in the beginning

void RollingVWAP::add_tick(const Tick& tick){             //adds a tick to the buffer and updates rolling values
  buffer_.push_back(tick);                                //adds the new tick to the buffer

  sum_px_qty_ += tick.price*tick.quantity;                //updates the rolling sum*quantity by including the new tick
  sum_qty_ += tick.quantity;                              //updates the rolling quatity by inlcuding the new tick

  if(buffer_.size() > window_){                           //if the number of ticks in the buffer is greater than the window size
    const Tick& old = buffer_.front();                    //creates a copy of the oldest tick in the buffer
    sum_px_qty_ -= old.price*old.quantity;                //removes the oldest tick's price*quantity from the rolling sum
    sum_qty_ -= old.quantity;                             //removes the oldest tick's quantity fromt the rolling sum
    buffer_.pop_front();                                  //remove the oldest tick from the buffer
  }
}

double RollingVWAP::get_vwap() const{                     //calculates and returns the rolling vwap
  if(sum_qty_ == 0.0) return 0.0;                         //if the total quantity is 0 returns 0
  else return sum_px_qty_/sum_qty_;                       //else returns sum of (price*quantity) / sum of (quantity)
}