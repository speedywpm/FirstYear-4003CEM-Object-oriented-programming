#include "lab_vowels.h"
#include <iostream>

int main()
{
    // get word from user
    std::cout << "Enter a word: ";
    std::string userInput;
    std::cin >> userInput;

    // get vowel count
    int vowels = count_vowels( userInput );

    // display results
    std::cout << userInput << " contains " << vowels << " vowel/s" << std::endl;

    return 0;
}
