#include "Huffman.h"

Huffman::Huffman(const char* data) : text(data) {
	// Creating a frequency table
	int frequencies[UniqueSymbols] = { 0 };
	const char* text = data;
	while (*text != '\0')
		++frequencies[*text++];

	for (int i = 0; i < UniqueSymbols; i++) {
		if (frequencies[i] != 0)
			std::cout << static_cast<char>(i) << " : " << frequencies[i] << std::endl;
	}
	std::cout << std::endl;

	auto root = BuildTree(frequencies);

	std::map<char, std::vector<bool>> codes;
	GenerateCodes(root, std::vector<bool>(), codes);

	for (auto& code : codes) {
		std::cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(),
			std::ostream_iterator<bool>(std::cout));
		std::cout << '\n';
	}
}

Huffman::~Huffman() {

}

std::shared_ptr<INode> Huffman::BuildTree(const int(&frequencies)[UniqueSymbols]) {

	auto cmp = [](std::shared_ptr<const INode> lhs, std::shared_ptr<const INode> rhs) {
		return lhs->frequency > rhs->frequency;
	};

	std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees;

	for (int i = 0; i < UniqueSymbols; ++i) {
		if (frequencies[i] != 0)
			trees.push(std::shared_ptr<INode>(new LeafNode(frequencies[i], (char)i)));
	}


	std::cout << "\n Only leaf nodes:\n";
	std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees2{ trees };
	while (!trees2.empty()) {
		trees2.top()->printNode();
		trees2.pop();
		std::cout << " ";
	}
	std::cout << '\n';


	std::cout << "\n Connected nodes:\n";
	while (trees.size() > 1) {
		std::shared_ptr<INode> childR = trees.top();
		trees.pop();

		std::shared_ptr<INode> childL = trees.top();
		trees.pop();

		std::shared_ptr<INode> parent = std::shared_ptr<INode>(new InternalNode(childR, childL));
		trees.push(parent);


		std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees3{ trees };
		while (!trees3.empty()) {
			trees3.top()->printNode();
			trees3.pop();
			std::cout << " ";
		}
		std::cout << '\n';

	}
	return trees.top();
}

void Huffman::GenerateCodes(const std::shared_ptr<INode> node, const std::vector<bool>& prefix, std::map<char, std::vector<bool>>& outCodes) {
	if (auto lf = std::dynamic_pointer_cast<const LeafNode>(node)) {
		outCodes[lf->symbol] = prefix;
	}
	else if (auto in = std::dynamic_pointer_cast<const InternalNode>(node)) {
		std::vector<bool> leftPrefix = prefix;
		leftPrefix.push_back(false);
		GenerateCodes(in->left, leftPrefix, outCodes);

		std::vector<bool> rightPrefix = prefix;
		rightPrefix.push_back(true);
		GenerateCodes(in->right, rightPrefix, outCodes);
	}
}

std::string Huffman::decodeText(const std::shared_ptr<INode> node, const std::string& encodedText) {
	std::string decodedText;
	std::shared_ptr<INode> current = node;

	for (char bit : encodedText) {
		if (bit == '0') {
			if (auto internalNode = std::dynamic_pointer_cast<const InternalNode>(current)) {
				current = internalNode->left;
			}
		}
		else if (bit == '1') {
			if (auto internalNode = std::dynamic_pointer_cast<const InternalNode>(current)) {
				current = internalNode->right;
			}
		}

		if (auto leafNode = std::dynamic_pointer_cast<const LeafNode>(current)) {
			decodedText += leafNode->symbol;
			current = node;
		}
	}

	return decodedText;
}

double Huffman::calculateStorageGain(const std::string& originalText, const std::string& encodedText) {
	double originalLength = originalText.length() * CHAR_BIT;
	double encodedLength = encodedText.length();
	double storageGain = (1 - encodedLength / originalLength) * 100;

	return storageGain;
}

void Huffman::encodeFile(const std::string& inputFile, const std::string& outputFile, const std::map<char, std::vector<bool>>& codes) {
	std::ifstream input(inputFile, std::ios::binary);
	std::ofstream output(outputFile, std::ios::binary);

	char ch;
	while (input.get(ch)) {
		const std::vector<bool>& code = codes.at(ch);
		for (bool bit : code) {
			output.put(bit ? '1' : '0');
		}
	}

	input.close();
	output.close();
}

void Huffman::decodeFile(const std::shared_ptr<INode> root, const std::string& inputFile, const std::string& outputFile) {
	std::ifstream input(inputFile, std::ios::binary);
	std::ofstream output(outputFile, std::ios::binary);

	std::string encodedText((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
	std::string decodedText = decodeText(root, encodedText);

	output << decodedText;

	input.close();
	output.close();
}

void Huffman::run() {
	// Build frequency table
	int frequencies[UniqueSymbols] = { 0 };
	const char* ptr = text;
	while (*ptr != '\0')
		++frequencies[*ptr++];

	auto root = BuildTree(frequencies);

	std::map<char, std::vector<bool>> codes;
	GenerateCodes(root, std::vector<bool>(), codes);

	// Encode and decode a sample text
	std::string originalText = text;
	std::string encodedText;
	for (char ch : originalText) {
		const std::vector<bool>& code = codes[ch];
		for (bool bit : code) {
			encodedText += (bit ? '1' : '0');
		}
	}

	std::cout << "Original text: " << originalText << std::endl;
	std::cout << "Encoded text: " << encodedText << std::endl;

	std::string decodedText = decodeText(root, encodedText);
	std::cout << "Decoded text: " << decodedText << std::endl;

	double storageGain = calculateStorageGain(originalText, encodedText);
	std::cout << "Storage gain: " << storageGain << "%" << std::endl;

	// Test file I/O operations
	std::string inputFile = "input.txt";
	std::string encodedFile = "encoded.txt";
	std::string decodedFile = "decoded.txt";

	// Write the original text to the input file
	std::ofstream input(inputFile);
	input << originalText;
	input.close();

	// Encode the input file and write the encoded text to the encoded file
	encodeFile(inputFile, encodedFile, codes);

	// Decode the encoded file and write the decoded text to the output file
	decodeFile(root, encodedFile, decodedFile);

	// Read the decoded text from the output file
	std::ifstream output(decodedFile);
	std::string fileDecodedText((std::istreambuf_iterator<char>(output)), std::istreambuf_iterator<char>());
	output.close();

	std::cout << "Decoded text from file: " << fileDecodedText << std::endl;
}