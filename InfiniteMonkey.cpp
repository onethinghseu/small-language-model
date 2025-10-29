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

using namespace std;

#include "InfiniteMonkey.h"


InfiniteMonkey::InfiniteMonkey(){}

void InfiniteMonkey::buildDictionary(const std::string  & infile ){
        std::ifstream file(infile);
        if (!file) {
        cerr << "Error: cannot open file " << infile << std::endl;
        return;
        }

        char ch;
        while (file.get(ch)){
            std::string key(1, ch);
            auto it = dictionary.find(key);
            
            if (it != dictionary.end()) {
            it->second += 1;  // 已存在 → 次數 +1
            } else {
            dictionary.insert({key, 1});// 不存在 → 插入初始次數 1

            } 
        }
        

        
    }



void InfiniteMonkey::printDictionary(){
        for (const auto& [key, count] : dictionary) {
            if (key == "\n")
                std::cout << "\\n : " << count << std::endl;
            else if (key == " ")
                std::cout << "[space] : " << count << std::endl;
            else
                std::cout << key << " : " << count << std::endl;
        }
    }


