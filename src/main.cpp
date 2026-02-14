//reads data from a csv file and processes it 
//uses Reader and Engine class to do this

#include "Reader.hpp"
#include "Engine.hpp"

int main(){

    Reader reader("../data/sample_ticks.csv");               //Reader object for the file "sample_ticks.csv"
    auto ticks = reader.read_all();                       //reads the csv file and stores Tick data in a vector

    Engine engine;                                        //Engine object created
    engine.process(ticks);                                //processes Tick data stored in "ticks" vector
}