#include "Favorite.h"

void FavoriteManager::addFavorite(const std::string& word, const std::vector<std::string>& definitions) {
    for (const auto& pair : favorites) {
        if (pair.first == word) {
            std::cout << word << " is already in your favorites list." << std::endl;
            return;
        }
    }

    favorites.emplace_back(word, definitions);
    std::cout << word << " added to Favorites." << std::endl;
}

void FavoriteManager::saveFavorites(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary);

    if (outFile.is_open()) {
        size_t size = favorites.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& pair : favorites) {
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
        std::cout << "Favorites saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Could not open file " << filename << std::endl;
    }
}
