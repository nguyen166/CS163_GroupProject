#include "History.h"

void HistoryManager::addHistory(const std::string& word, const std::vector<std::string>& definitions) {
    history.emplace_back(word, definitions);
    std::cout << word << " added to history." << std::endl;
}

void HistoryManager::saveHistory(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open()) {
        size_t size = history.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& pair : history) {
            size_t wordLength = pair.first.length();
            size_t numDefinitions = pair.second.size();

            outFile.write(reinterpret_cast<const char*>(&wordLength), sizeof(wordLength));
            outFile.write(pair.first.c_str(), wordLength);

            outFile.write(reinterpret_cast<const char*>(&numDefinitions), sizeof(numDefinitions));
            for (const auto& definition : pair.second) {
                size_t definitionLength = definition.length();
                outFile.write(reinterpret_cast<const char*>(&definitionLength), sizeof(definitionLength));
                outFile.write(definition.c_str(), definitionLength);
            }
        }

        outFile.close();
        std::cout << "History saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Could not open file " << filename << " for writing." << std::endl;
    }
}

void HistoryManager::loadHistory(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

        for (size_t i = 0; i < size; ++i) {
            size_t wordLength, numDefinitions;
            inFile.read(reinterpret_cast<char*>(&wordLength), sizeof(wordLength));
            std::string word(wordLength, '\0');
            inFile.read(&word[0], wordLength);

            inFile.read(reinterpret_cast<char*>(&numDefinitions), sizeof(numDefinitions));
            std::vector<std::string> definitions(numDefinitions);
            for (size_t j = 0; j < numDefinitions; ++j) {
                size_t definitionLength;
                inFile.read(reinterpret_cast<char*>(&definitionLength), sizeof(definitionLength));
                std::string definition(definitionLength, '\0');
                inFile.read(&definition[0], definitionLength);
                definitions[j] = definition;
            }

            history.emplace_back(word, definitions);
        }

        inFile.close();
        std::cout << "History loaded from " << filename << std::endl;
    }
    else {
        std::cerr << "Could not open file " << filename << " for reading." << std::endl;
    }
}

void HistoryManager::viewHistory() const {
    if (history.empty()) {
        std::cout << "Your search history is empty." << std::endl;
        return;
    }

    std::cout << "Your search history:" << std::endl;
    for (const auto& pair : history) {
        std::cout << "Word: " << pair.first << std::endl;
        for (const auto& definition : pair.second) {
            std::cout << "  - " << definition << std::endl;
        }
    }
}
