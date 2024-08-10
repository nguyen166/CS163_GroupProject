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
