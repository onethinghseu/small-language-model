#ifndef INFINITE_MONKEY_H
#define INFINITE_MONKEY_H

#include <iostream>
#include <vector> 
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <map>
#include <string>



class InfiniteMonkey{
public:
    
    InfiniteMonkey(); //default
    InfiniteMonkey(const std::string& filename); 


    
    void buildDictionary(const std::string& infile);
    void printDictionary();


    //paprametters 

    // void set_k (int val);
    // void set_m (int val);




    // //dictionary 






    // //operators     

    // void::process()

    // float::Prob_cal (int );



private: 
    std::map<std::string, int> dictionary;
};

#endif


