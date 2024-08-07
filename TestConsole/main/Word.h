#pragma once
#include <string>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <sstream>


class Word {
private:
    std::string word;
    std::string Searchtime;
    std::string Searchdate;

public:
    Word() {}

    Word(std::string text);

    std::string getSearchtime() const;
    std::string getSearchdate() const;
    std::string getWord() const;

    void setWord(const std::string& text);
    void setDate(const std::string& date);
    void setTime(const std::string& time);
};
