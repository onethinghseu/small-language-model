#ifndef Banana_H
#define Banana_H

#include <iostream>
#include <vector> 
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <map>
#include <string>

class Banana{

public:
    Banana();
    Banana(const std::string& filename);

    std::string readFiletoContent(const std::string &filename);



private:


};

#endif