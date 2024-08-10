#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

class HistoryManager {
    std::vector<std::pair<std::string, std::vector<std::string>>> history;

public:
    void addHistory(const std::string& word, const std::vector<std::string>& definitions);
    void saveHistory(const std::string& filename) const;
};

#endif // HISTORY_H
