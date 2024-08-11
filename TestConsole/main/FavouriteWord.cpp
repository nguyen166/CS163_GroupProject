#include "FavouriteWord.h"


void FavouriteWord::addWord(const string& word, vector<string>& words) {
    if (find(words.begin(), words.end(), word) == words.end()) {
        words.push_back(word);
        cout << word << " has been added to your favorite words." << endl;
    }
    else {
        cout << word << " is already in your favorite words." << endl;
    }
}
// Remove word from a vector
void FavouriteWord::removeWord(const string& word, vector<string>& words) {
    auto it = find(words.begin(), words.end(), word);
    if (it != words.end()) {
        words.erase(it);
        cout << word << " has been removed from your favorite words." << endl;
    }
    else {
        cout << word << " is not in your favorite words." << endl;
    }
}
//display word from a vector
void FavouriteWord::displayWords(vector<string>& words) {
    cout << "Your favorite words are:" << endl;
    for (const auto& word : words) {
        cout << "- " << word << endl;
    }
}
// Save new voc to a file
void FavouriteWord::saveToFile(const string& filename, vector<string>& words) {
    ofstream outFile(filename, ios::binary);
    if (outFile.is_open()) {
        for (const auto& word : words) {
            size_t length = word.size();
            outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
            outFile.write(word.c_str(), length);
        }
        outFile.close();
        cout << "Words have been saved to " << filename << " as binary data." << endl;
    }
    else {
        cout << "Can't open file " << filename << "." << endl;
    }
}
//Load word from a file 
void FavouriteWord::loadFromFile(const string& filename, vector<string>& words) {
    ifstream inFile(filename, ios::binary);
    if (inFile.is_open()) {
        words.clear();
        while (!inFile.eof()) {
            size_t length;
            inFile.read(reinterpret_cast<char*>(&length), sizeof(length));

            if (inFile.eof()) break;

            string word(length, '\0');
            inFile.read(&word[0], length);
            words.push_back(word);
        }
        inFile.close();
        cout << "Words have been loaded from " << filename << " as binary data." << endl;
    }
    else {
        cout << "Can't open file " << filename << "." << endl;
    }
}