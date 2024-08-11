#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string> 
using namespace std;
class FavouriteWord
{
public:
    void addWord(const string& word, vector<string>& words);
    // Remove word from a vector
    void removeWord(const string& word, vector<string>& words);
    //display word from a vector
    void displayWords(vector<string>& words);
    // Save new voc to a file
    void saveToFile(const string& filename, vector<string>& words);
    //Load word from a file 
    void loadFromFile(const string& filename, vector<string>& words);
};

