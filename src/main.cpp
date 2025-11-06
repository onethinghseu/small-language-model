# include "InfiniteMonkey.h"
# include "Banana.h"



int main(int argc, char** argv){

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <k> <input.txt> <output length>\n";
        return 1;
    }


    // int m = argv[2]; // this is the number out output

    // const std::string filename = "harrypotter.txt";

    InfiniteMonkey monkey;
    Banana banana;

    monkey.setK(std::stoi(argv[3]));


    std::string content = banana.readFiletoContent(argv[2]);

    // test.printDictionary();
    monkey.buildDictionaryfromtext(content);
    monkey.computeFrequency();
    // test.printFrequency();

    std::string startfromK = monkey.startwithKgram();
    // std::cout<<"startfromK is"<<startfromK<<std::endl;

    // test.generateW_Sample(startfromK);

    std::string result = monkey.text_Generate(startfromK,std::stoi(argv[1]));

    std::cout<<"generating text : "<<result<<std::endl;
    // save to text 
    std::ofstream out("output.txt");
    if (!out) {
        std::cerr << "Error: cannot open output file " << std::endl;
        return 1;
    }

    out << "=== Generated Text ===\n";
    out << result << "\n";

    out.close();


    return 0; 
}