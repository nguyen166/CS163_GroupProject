#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <memory>
#include "History.h"
struct TrieNode {
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    std::vector<std::string> definitions;
    bool is_end_of_word = false;
};

class Trie {
public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word, const std::string& definition) {
        TrieNode* node = root.get();
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = std::make_unique<TrieNode>();
            }
            node = node->children[ch].get();
        }
        node->is_end_of_word = true;
        node->definitions.push_back(definition);
    }

    std::vector<std::string> search(const std::string& word) const {
        const TrieNode* node = findNode(word);
        if (node && node->is_end_of_word) {
            return node->definitions;
        }
        return { "Word not found" };
    }

    std::vector<std::string> startsWith(const std::string& prefix) const {
        std::vector<std::string> results;
        const TrieNode* node = findNode(prefix);
        if (node) {
            findAllWords(node, prefix, results);
        }
        return results;
    }

private:
    std::unique_ptr<TrieNode> root;

    const TrieNode* findNode(const std::string& prefix) const {
        const TrieNode* node = root.get();
        for (char ch : prefix) {
            auto it = node->children.find(ch);
            if (it == node->children.end()) {
                return nullptr;
            }
            node = it->second.get();
        }
        return node;
    }

    void findAllWords(const TrieNode* node, const std::string& prefix, std::vector<std::string>& results) const {
        if (node->is_end_of_word) {
            for (const auto& definition : node->definitions) {
                results.push_back(prefix + ": " + definition);
            }
        }
        for (const auto& child : node->children) {
            findAllWords(child.second.get(), prefix + child.first, results);
        }
    }
};

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

Trie loadDictionary(const std::string& filename) {
    Trie trie;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return trie;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('\t');
        if (delimiterPos != std::string::npos) {
            std::string word = trim(line.substr(0, delimiterPos));
            std::string definition = trim(line.substr(delimiterPos + 1));
            trie.insert(word, definition);
        }
    }

    return trie;
}

/*class Word {
private:
    std::string word;
    std::string Searchtime;
    std::string Searchdate;

public:
    Word() {}

    Word(std::string text) {
        word = text;
        std::time_t t = std::time(nullptr);
        std::tm now;
        localtime_s(&now, &t);
        std::ostringstream timeStream;
        timeStream << std::setw(2) << std::setfill('0') << now.tm_hour << ":"
            << std::setw(2) << std::setfill('0') << now.tm_min << ":"
            << std::setw(2) << std::setfill('0') << now.tm_sec;
        Searchtime = timeStream.str();
        std::ostringstream dateStream;
        dateStream << now.tm_year + 1900 << "-"
            << std::setw(2) << std::setfill('0') << now.tm_mon + 1 << "-"
            << std::setw(2) << std::setfill('0') << now.tm_mday;
        Searchdate = dateStream.str();
    }

    std::string getSearchtime() const { return Searchtime; }
    std::string getSearchdate() const { return Searchdate; }
    std::string getWord() const { return word; }

    void setWord(const std::string& text) { word = text; }
    void setDate(const std::string& date) { Searchdate = date; }
    void setTime(const std::string& time) { Searchtime = time; }
};*/

/*class History {
private:
    std::vector<Word> v;

public:
    History() {}

    std::vector<Word> getHistory() const { return v; }

    void loadHistory() {
        v.clear();
        std::ifstream in("history.csv");
        std::string line;
        getline(in, line); 

        while (getline(in, line)) {
            Word word;
            std::stringstream ss(line);
            std::string temp;

            getline(ss, temp, ',');
            word.setWord(temp);

            getline(ss, temp, ',');
            word.setTime(temp);

            getline(ss, temp, ',');
            word.setDate(temp);

            v.push_back(word);
        }

        std::reverse(v.begin(), v.end());
    }

    void saveHistory(const Word& w) {
        std::ofstream out("history.csv", std::ios::app);
        if (!out.is_open()) return;
        out << w.getWord() << "," << w.getSearchtime() << "," << w.getSearchdate() << std::endl;
        out.close();
    }

    void Show() const {
        for (const auto& c : v) {
            std::cout << c.getSearchdate() << " " << c.getSearchtime() << " " << c.getWord() << std::endl;
        }
    }
};*/





class Definition {
private:
    std::string content;
    std::vector<std::string> each;
    std::vector<std::string> result;

public:
    Definition(std::string& content) {
        std::stringstream ss(content);
        std::string word;
        while (ss >> word) {
            each.push_back(word);
        }
    }

    void searchByDefinition() {
        for (char c = 'A'; c <= 'Z'; ++c) {
            std::ifstream file("DataSet/" + std::string(1, c) + ".txt");
            if (!file.is_open()) continue;

            std::string line;
            while (std::getline(file, line)) {
                std::vector<std::string> wordsInLine = splitIntoWords(line);
                if (containsAllWords(wordsInLine)) {
                    result.push_back(line);
                    if (result.size() == 10) return;
                }
            }
        }
    }

    void Show() {
        if (result.empty()) {
            std::cout << "No word matches" << std::endl;
        }
        else {
            for (auto& line : result) {
                std::cout <<"-"<< line << std::endl;
            }
        }
    }

private:
    std::vector<std::string> splitIntoWords(std::string& line) {
        std::vector<std::string> words;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    bool containsAllWords(std::vector<std::string>& wordsInLine) {
        for (auto& word : each) {
            if (std::find(wordsInLine.begin(), wordsInLine.end(), word) == wordsInLine.end()) {
                return false;
            }
        }
        return true;
    }
};






int main() {
    std::string choice;
    std::string input;
    History history;

    do {
        std::cout << "\nDictionary Menu:\n";
        std::cout << "1. Search for a word\n";
        std::cout << "2. Search for words with a prefix\n";
        std::cout << "3. History\n";
        std::cout << "4. Search by definition\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            std::cout << "Enter the word: ";
            std::cin >> input;
            std::string filename = "DataSet/" + std::string(1, std::toupper(input[0])) + ".txt";
            Trie dictionary = loadDictionary(filename);
            for (auto& c : input) c = std::tolower(c);
            std::vector<std::string> definitions = dictionary.search(input);
            if (definitions.size() == 1 && definitions[0] == "Word not found") {
                std::cout << "Definition of '" << input << "': " << definitions[0] << "\n";
            }
            else {
                std::cout << "Definitions of '" << input << "':\n";
                for (const auto& definition : definitions) {
                    std::cout << " - " << definition << "\n";
                }
            }
            Word searchedWord(input);
            history.saveHistory(searchedWord);
        }
        else if (choice == "2") {
            std::cout << "Enter the prefix: ";
            std::cin >> input;
            std::string filename = "DataSet/" + std::string(1, std::toupper(input[0])) + ".txt";
            Trie dictionary = loadDictionary(filename);
            for (auto& c : input) c = std::tolower(c);
            std::vector<std::string> results = dictionary.startsWith(input);
            if (results.empty()) {
                std::cout << "No words found with prefix '" << input << "'.\n";
            }
            else {
                std::cout << "Words with prefix '" << input << "':\n";
                for (const auto& word : results) {
                    std::cout << " - " << word << "\n";
                }
            }
        }
        else if (choice == "3") {
            history.loadHistory();
            history.Show();
        }
        else if (choice == "4") {
            std::cin.ignore();
            std::string input;
            std::cout << "Enter definition:";
            getline(std::cin, input);
            Definition def(input);
            def.searchByDefinition();
            def.Show();
        }
        else if (choice != "5") {
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != "5");

    std::cout << "Exiting the dictionary. Goodbye!\n";
    return 0;
}
