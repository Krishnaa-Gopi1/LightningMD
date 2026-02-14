//defines Reader class
//takes a filename
//read_all() -> function to read all ticks froma  file and store it in a vector

#pragma once
#include<string>
#include<vector>
#include "Tick.hpp"

class Reader{                                              //Reader class definition
    public:
    explicit Reader(const std::string& filename);

    std::vector<Tick> read_all();                          //read_all() function declaration

    private:
    std::string filename_;                                 //keeping filename private
};