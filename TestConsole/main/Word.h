#pragma once
#include <string>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include <vector>

class Word {
private:
    std::string word;
    std::string searchTime;
    std::string searchDate;

public:
    // Constructors
    Word() = default;
    Word(const std::string& text);

    // Getters and setters
    std::string getWord() const;
    void setWord(const std::string& w);

    std::string getSearchtime() const;
    void setTime(const std::string& time);

    std::string getSearchdate() const;
    void setDate(const std::string& date);

    // Serialization and deserialization
    void writeToStream(std::ofstream& os) const;
    void readFromStream(std::ifstream& is);
};
