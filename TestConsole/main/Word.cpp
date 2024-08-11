#include "Word.h"

Word::Word(const std::string& text) : word(text) {
    std::time_t t = std::time(nullptr);
    std::tm now;
    localtime_s(&now, &t);

    std::ostringstream timeStream;
    timeStream << std::setw(2) << std::setfill('0') << now.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << now.tm_min << ":"
        << std::setw(2) << std::setfill('0') << now.tm_sec;
    searchTime = timeStream.str();

    std::ostringstream dateStream;
    dateStream << now.tm_year + 1900 << "-"
        << std::setw(2) << std::setfill('0') << now.tm_mon + 1 << "-"
        << std::setw(2) << std::setfill('0') << now.tm_mday;
    searchDate = dateStream.str();
}

std::string Word::getWord() const { return word; }
void Word::setWord(const std::string& w) { word = w; }

std::string Word::getSearchtime() const { return searchTime; }
void Word::setTime(const std::string& time) { searchTime = time; }

std::string Word::getSearchdate() const { return searchDate; }
void Word::setDate(const std::string& date) { searchDate = date; }

void Word::writeToStream(std::ofstream& os) const {
    size_t size;

    size = word.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    os.write(word.c_str(), size);

    size = searchTime.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    os.write(searchTime.c_str(), size);

    size = searchDate.size();
    os.write(reinterpret_cast<const char*>(&size), sizeof(size));
    os.write(searchDate.c_str(), size);
}

void Word::readFromStream(std::ifstream& is) {
    size_t size;
    std::vector<char> buffer;

    // Read word
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    buffer.resize(size);
    is.read(buffer.data(), size);
    word.assign(buffer.begin(), buffer.end());

    // Read searchTime
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    buffer.resize(size);
    is.read(buffer.data(), size);
    searchTime.assign(buffer.begin(), buffer.end());

    // Read searchDate
    is.read(reinterpret_cast<char*>(&size), sizeof(size));
    buffer.resize(size);
    is.read(buffer.data(), size);
    searchDate.assign(buffer.begin(), buffer.end());
}
