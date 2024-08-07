#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string> 
class FavouriteWord
{
public:
    // Add a word to the favourite list
    void addWord(const std::string& word, std::vector<std::string>& words);

    // Remove a word from the favourite list
    void removeWord(const std::string& word, std::vector<std::string>& words);

    void displayWords(const std::vector<std::string>& words);

    void saveToFile(const std::string& filename, const std::vector<std::string>& words);

    void loadFromFile(const std::string& filename, std::vector<std::string>& words);
};

