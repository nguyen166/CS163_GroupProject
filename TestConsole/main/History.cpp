#include "History.h"
void History::loadHistory() {
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

void History::saveHistory(const Word& w) {
    std::ofstream out("history.csv", std::ios::app);
    if (!out.is_open()) return;
    out << w.getWord() << "," << w.getSearchtime() << "," << w.getSearchdate() << std::endl;
    out.close();
}

void History::Show() const {
    for (const auto& c : v) {
        std::cout << c.getSearchdate() << " " << c.getSearchtime() << " " << c.getWord() << std::endl;
    }
}