#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    srand(time(0));
    std::vector<std::string> words = { "write", "that", "school" };

    // getting random word
    std::string wordToGuess = words[rand() % words.size()];

    // setting word to lowercase if needed.
    std::transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::tolower);

    std::string wordResult;
    for (size_t i = 0; i < wordToGuess.length(); i++) {
        wordResult += '*';
    }

    bool wordGuessed = false;
    int misses = 0;

    while (!wordGuessed) {
        std::cout << "(Guess) Enter a letter in the word " << wordResult << " > ";

        // get user input
        std::string input;
        std::getline(std::cin, input);

        // get only the first character the user gave. Skip the rest
        char charInput = tolower(input[0]);

        bool found = false;
        for (size_t i = 0; i < wordToGuess.length(); i++) {
            if (wordToGuess[i] == charInput) {
                wordResult[i] = charInput;
                found = true;
            }
        }

        if (!found)
            misses++;

        // if no asterix is in the word the word is guessed correctly.
        if (wordResult.find('*') == std::string::npos) {
            wordGuessed = true;
        }
    }

    std::cout << "The word is " << wordResult << ". You missed " << misses << ((misses == 1) ? " time.\n" : " times.\n");
    return 0;
}