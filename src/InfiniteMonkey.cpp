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

#include "InfiniteMonkey.h"

InfiniteMonkey::InfiniteMonkey(){}




// this is from old verison where there is no individual .cpp for reading file
// void InfiniteMonkey::buildDictionaryfromFile(const std::string  & infile ){
//         std::ifstream file = readFile(infile);
//         std::string content = readFileContent(file);

//         buildDictionaryfromtext(content);
        
//     }

void InfiniteMonkey::buildDictionaryfromtext(const std::string &text){
    
    dictionary.clear();
    nextChar.clear();

    int n = k_;
    for (size_t i = 0; i < text.size() - 1; i++) { 
        std::string key = text.substr(i, n);
        dictionary[key]++;
        char next = text[i + n]; 
        nextChar[key][next]++;
    }
}


void InfiniteMonkey::printDictionary(){
        for (const auto& [key, count] : dictionary) {
            if (key == " ")
                std::cout << "[space] : " << count << std::endl;
            else
                std::cout << key << " : " << count << std::endl;
        }
        for (const auto& [key, innerMap] : nextChar) {
        std::cout << key << " → ";
        for (const auto& [key2, count] : innerMap) {
            if (key2 == ' ')
                std::cout << "[space]:" << count << " ";
            else
                std::cout << key2 << ":" << count << " ";
        }
        std::cout<<std::endl;
    }
}


const std::map<std::string, int>& InfiniteMonkey::getDictionary() const { return dictionary; }

void InfiniteMonkey::computeFrequency(){
    freq_k.clear();
    nextChar_freq.clear();
    int total = 0; 
    
    for (const auto& [key, count] : dictionary){
        total += count;
    }

    for (const auto& [key, count] : dictionary){
        freq_k[key] = static_cast<double>(count) / total;
    }

    for (const auto& [key,innerMap]:nextChar){
        int next_total = 0 ;
        for (const auto& [key2, count]:innerMap){

            next_total += count;
        }

        for (const auto& [key2, count]:innerMap){
            nextChar_freq[key][key2] = static_cast<double>(count) / next_total;
        } 
    }
        

}

void InfiniteMonkey::printFrequency() const {
    std::cout << "=== Character Frequency ===" << std::endl;
    for (const auto& [key, freq_k] : freq_k) {
        if (key == " ")
            std::cout << "[space] : " << std::fixed << std::setprecision(4) << freq_k << std::endl;
        else
            std::cout << key << " : " << std::fixed << std::setprecision(4) << freq_k << std::endl;
    }

    std::cout << "=== Next word Frequency ===" << std::endl;
    for (const auto& [key,innerMap]:nextChar_freq){
        if (key == " ")
            std::cout << "[space] : " << std::endl;
        else
            std::cout << key << " : " << std::endl;
    
        for (const auto& [key2, freq]:innerMap){
            if (key2 == ' ')
                std::cout << "[space] : " << freq <<std::endl;
            else
            std::cout<<key2<<":"<< freq << std::endl;
        } 
    }
    

}

std::string InfiniteMonkey::startwithKgram()const{
    // if k gram map is not built
    if (freq_k.empty()) {
        throw std::runtime_error("No k-grams available for sampling.");
    }


    // two vectors taking the maping of key and prob,sharing the index  
    const int fullklength = freq_k.size();
    std::vector<std::string> full_k(fullklength);
    std::vector<double> full_k_freq(fullklength);

    for (const auto& [key, value] : freq_k) {
        full_k.push_back(key);
        full_k_freq.push_back(static_cast<double>(value));
    }

    //random number 
    static std::random_device rd; //random seed  
    static std::mt19937 gen(rd()); //random number generate 


    std::discrete_distribution<> dist(full_k_freq.begin(), full_k_freq.end());
    int random_index = dist(gen);
    //std::cout << "start from:" << full_k[random_index] << std::endl;
    return full_k[random_index];
}

char InfiniteMonkey::generateW_Sample(const std::string &pre_char){

    // const int fullklength = .size();
    // std::vector<std::string> full_k(fullklength);
    // std::vector<double> full_k_freq(fullklength);


    //find pretext in the dictoianry
    // auto next = nextChar.find(pre_char);
    
    // std::cout<<next<<std::endl;
    auto next = nextChar_freq.find(pre_char); 

    if (next == nextChar_freq.end()) {
        std::cerr << "next Key not found: " << pre_char << std::endl;
        return '\0';  // 或選擇重新抽樣
    }

    //std::cout<<"pre is:"<<pre_char<<std::endl;


    auto &innerMap = next->second;

    std::vector<std::string>  next_w_possible;
    std::vector<double> next_w_possible_freq;

    for (auto it = innerMap.begin(); it != innerMap.end(); ++it) {
            
        auto ch = it->first;
        auto freq = it->second;

        next_w_possible.push_back(std::string(1, ch));
        next_w_possible_freq.push_back(static_cast<double>(freq));

        // std::cout << ch << " : " << count << std::endl;
        }

    // for (size_t i = 0; i<next_w_possible.size();i++){
    //     std::cout<<next_w_possible[i]<<std::endl;
    //     std::cout<<next_w_possible_freq[i]<<std::endl;
    // }



    //random number 
    static std::random_device rd; //random seed  
    static std::mt19937 gen(rd()); //random number generate

    std::discrete_distribution<> dist(next_w_possible_freq.begin(), next_w_possible_freq.end());
    int random_index = dist(gen);
    // std::cout << "next is:" << next_w_possible[random_index] << std::endl;


    std::string next_w = next_w_possible[random_index];

    return next_w[0];
}

void InfiniteMonkey::setK(int k) {
    k_ = k;
}


std::string InfiniteMonkey::text_Generate(const std::string &starttext, int length){

    
    //start 

    std::string current_w = starttext;
    std::string result_text = starttext;

    for (int i = 0; i < length-k_; ++i) {
    try {
        char next = generateW_Sample(current_w);
        result_text += next;
        current_w = current_w.substr(1) + next;
    } catch (const std::runtime_error &) {
        std::cout << "error in the text generation" << std::endl;
        break;
    }
    }

    return result_text;


}








