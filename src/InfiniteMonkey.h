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


    void buildDictionaryfromtext(const std::string &text);
    void buildDictionaryfromFile(const std::string  & infile);

    void printDictionary();

    const std::map<std::string, int>& getDictionary() const;

    void computeFrequency();
    void printFrequency() const;

    std::string startwithKgram() const;

    char generateW_Sample(const std::string &pre_char);

    std::string text_Generate(const std::string &starttext, int length);

    void setK(int k);



private: 
    std::map<std::string, int> dictionary;
    std::map<std::string, double > freq_k;


    std::ifstream readFile(const std::string  & infile );
    std::string readFileContent(std::ifstream &file);

    std::map<std::string, std::map<char, int>> nextChar;
    std::map<std::string, std::map<char, double>> nextChar_freq;

    int k_;


    
};

#endif


