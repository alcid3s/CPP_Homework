#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) {
    std::string str = s;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    

    for (size_t i = 0; i < str.length() / 2; i++) {

        /* get the length of the string and check from end to middle
        if that is the same as the begin from the middle. If one is off
        it isn't a palindrome. */
        if (str[(str.length() - 1) - i] != str[i])
            return false;
    }
    return true;
}

int main() {
    std::cout << "Enter a string: ";

    // get user input
    std::string input;
    std::getline(std::cin, input);

    // check if input is palindrome
    if (isPalindrome(input))
        std::cout << input << " is a palindrome\n";
    else
        std::cout << input << " is not a palindrome\n";
    return 0;
}