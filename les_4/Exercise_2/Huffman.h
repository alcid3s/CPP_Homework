#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include <iostream>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>

constexpr const int UniqueSymbols = 1 << CHAR_BIT;

struct NodeCmp {
	bool operator()(std::shared_ptr<const INode> lhs, std::shared_ptr<const INode> rhs) const {
		return lhs->frequency > rhs->frequency;
	}
};

class Huffman {
public:
	Huffman(const char* text);
	~Huffman();

	void run();

private:
	std::shared_ptr<INode> BuildTree(const int(&frequencies)[UniqueSymbols]);
	void GenerateCodes(const std::shared_ptr<INode> node, const std::vector<bool>& prefix, std::map<char, std::vector<bool>>& outCodes);
	std::string decodeText(const std::shared_ptr<INode> node, const std::string& encodedText);
	double calculateStorageGain(const std::string& originalText, const std::string& encodedText);
	void encodeFile(const std::string& inputFile, const std::string& outputFile, const std::map<char, std::vector<bool>>& codes);
	void decodeFile(const std::shared_ptr<INode> root, const std::string& inputFile, const std::string& outputFile);
	
private:
	const char* text;
};