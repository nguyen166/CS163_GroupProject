#ifndef FAVORITE_H
#define FAVORITE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>

class FavoriteManager {
    std::vector<std::pair<std::string, std::vector<std::string>>> favorites;

public:
    void addFavorite(const std::string& word, const std::vector<std::string>& definitions);
    void saveFavorites(const std::string& filename) const;
    void loadFavorites(const std::string& filename);
    void viewFavorites() const;
};

#endif // FAVORITE_H
