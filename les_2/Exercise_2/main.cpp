#include <iostream>
#include <string>
#include <vector>

bool checkATG(const std::string input, const int i) {
    return input[i] == 'A' && input[i + 1] == 'T' && input[i + 2] == 'G';
}
bool checkTAG(const std::string input, const int i) {
    return input[i] == 'T' && input[i + 1] == 'A' && input[i + 2] == 'G';
}
bool checkTTA(const std::string input, const int i) {
    return input[i] == 'T' && input[i + 1] == 'T' && input[i + 2] == 'A';
}
bool checkTGA(const std::string input, const int i) {
    return input[i] == 'T' && input[i + 1] == 'G' && input[i + 2] == 'A';
}

int main() {
    std::cout << "Enter a genome string: ";
    
    // get user input
    std::string input;
    std::getline(std::cin, input);
    
    // default genome
    if (input.empty()) {
        input = "TTATGTTTTAAGGATGGGGCGTTAGTT";
    }

    bool startGeneFound = false;
    std::vector<std::string> genes;
    std::string gene;
    for (size_t i = 0; i < input.length(); i++) {
        // check for ATG
        if (checkATG(input, i) && !startGeneFound) {
            if (i + 3 < input.length()) {
                i += 3;
            }
            startGeneFound = true;
        }

        // saving gene to string
        if (startGeneFound) {
            gene += input[i];

            // check if this was the last character for the gene
            if (checkTAG(input, i) || checkTTA(input, i) || checkTGA(input, i)) {
                if (i + 3 < input.length()) {
                    i += 3;
                }
                startGeneFound = false;
                genes.push_back(gene);
                gene.clear();
            }
        }
    }

    if (genes.size() != 0)
        for (size_t i = 0; i < genes.size(); i++) {
            std::cout << genes[i].c_str() << "\n";
        }
    else
        std::cout << "no gene found\n";
    return 0;
}