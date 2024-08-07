#include "FavouriteWord.h"


void FavouriteWord::addWord(const std::string& word, std::vector<std::string>& words) {
    if (std::find(words.begin(), words.end(), word) == words.end()) {
        words.push_back(word);
        std::cout << word << " has been added to your favorite words." << std::endl;
    }
    else {
        std::cout << word << " is already in your favorite words." << std::endl;
    }
}

// Remove a word from the favourite list
void FavouriteWord::removeWord(const std::string& word, std::vector<std::string>& words) {
    auto it = std::find(words.begin(), words.end(), word);
    if (it != words.end()) {
        words.erase(it);
        std::cout << word << " has been removed from your favorite words." << std::endl;
    }
    else {
        std::cout << word << " is not in your favorite words." << std::endl;
    }
}

void FavouriteWord::displayWords(const std::vector<std::string>& words) {
    std::cout << "Your favorite words are: " << std::endl;
    for (const auto& word : words) {
        std::cout << "- " << word << std::endl;
    }
}

void FavouriteWord::saveToFile(const std::string& filename, const std::vector<std::string>& words) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& word : words) {
            outFile << word << std::endl;
        }
        outFile.close();
        std::cout << "Words have been saved to " << filename << std::endl;
    }
    else {
        std::cout << "Can't open file " << filename << "." << std::endl;
    }
}

void FavouriteWord::loadFromFile(const std::string& filename, std::vector<std::string>& words) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        words.clear();
        std::string word;
        while (std::getline(inFile, word)) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        inFile.close();
        std::cout << "Words have been loaded from " << filename << std::endl;
    }
    else {
        std::cout << "Can't open file " << filename << "." << std::endl;
    }
}