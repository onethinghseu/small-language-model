#include <iostream>
#include <vector> 
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <list>
#include <array>
#include <algorithm> 
#include <map>
#include <string>
#include <random>

using namespace std;

#include "Banana.h"

Banana::Banana(){}

std::string Banana::readFiletoContent(const std::string &filename ){
        std::ifstream file(filename);
        std::string content;

        if (!file) {
        cerr << "Error: cannot open file " << filename << std::endl;
        }

        char ch;

        while (file.get(ch)) {
            content += ch;  // 保留空白與換行
        }
        return content;
    }