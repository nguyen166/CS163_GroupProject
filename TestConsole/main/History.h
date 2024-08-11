#pragma once
#include <iostream>
#include <vector>
#include "Word.h"
#include <string>
#include <fstream>
#include <sstream>

class History {
private:
    std::vector<Word> v;

public:
    History() {}

    std::vector<Word> getHistory() const { return v; }

    void loadHistory();

    void saveHistory(const Word& w);

    void Show() const;
};
