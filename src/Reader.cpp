//reads tick data from a csv file and stores Tick data in a vector and returns the final vector

#include<Reader.hpp>
#include<fstream>
#include<sstream>
#include<iostream>

Reader::Reader(const std::string& filename)
    : filename_(filename) {}                              //stores filename in filename_

std::vector<Tick> Reader::read_all(){
    std::vector<Tick> ticks;                              //vector to store ticks

    std::ifstream file(filename_);                        //tries to open filename_ -> file 
    if(!file.is_open()){                                  //if file cant be opened -> empty ticks returned
        std::cerr << "Failed to open file " 
        << filename_ << std::endl;
        return ticks;
    }

    std::string line;                                     //string variable to store read line

    std::getline(file,line);                              //read 1st row -> header (ignore)
    
    while(std::getline(file,line)){
        std::stringstream ss(line);                       //stringstream object for continuous reading from line
        std::string token;                                //variable to store string data after splitting

        Tick tick;                                        //tick object to store tick data from line

        //timestamp data
        std::getline(ss,token,',');                       //read data till ',' is found and store in token
        tick.timestamp = std::stoll(token);               //convert token (timestamp) to long long and store in tick.timestamp

        //price data
        std::getline(ss,token,',');                       //read data till next ',' is found and store in token
        tick.price = std::stod(token);                    //store read data (token) in tick.price as double

        //quantity data
        std::getline(ss,token,',');                       //read data till next ',' is found and store in token
        tick.quantity = std::stoi(token);                 //store read data (token) in tick.quantity as integer

        ticks.push_back(tick);                            //add new tick data to ticks 
    }

    return ticks;                                         //return final vector containing tick data

}