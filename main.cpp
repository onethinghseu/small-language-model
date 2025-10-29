# include "InfiniteMonkey.h"

int main(){

    // int k = argv[0];
    // int m = argv[2]; // this is the number out output

    const std::string filename = "banana.txt";

    InfiniteMonkey test;
    test.buildDictionary(filename);
    test.printDictionary();

    return 0; 
}