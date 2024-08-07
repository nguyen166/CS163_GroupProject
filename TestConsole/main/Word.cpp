#include "Word.h"


Word::Word(std::string text) {
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

std::string Word::getSearchtime() const { return Searchtime; }
std::string Word::getSearchdate() const { return Searchdate; }
std::string Word::getWord() const { return word; }

void Word::setWord(const std::string& text) { word = text; }
void Word::setDate(const std::string& date) { Searchdate = date; }
void Word::setTime(const std::string& time) { Searchtime = time; }