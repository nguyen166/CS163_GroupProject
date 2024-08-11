#include "History.h"

void History::loadHistory() {
    v.clear();
    std::ifstream in("history.bin", std::ios::binary);
    if (!in.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    Word word;
    while (in >> word) {
        v.push_back(word);
    }

    std::reverse(v.begin(), v.end());
}

void History::saveHistory(const Word& w) {
    std::ofstream out("history.bin", std::ios::binary | std::ios::app);
    if (!out.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    out << w;
    out.close();
}

void History::Show() const {
    for (const auto& c : v) {
        std::cout << c.getSearchdate() << " " << c.getSearchtime() << " " << c.getWord() << std::endl;
    }
}
