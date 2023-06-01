#include <iostream>
#include<string>
#include "Huffman.h"

int main() {
	std::string data;
	std::cout << "What do you want to encode?: ";
	std::getline(std::cin, data);

	Huffman huffman(data.c_str());

	huffman.run();
	return 0;
}