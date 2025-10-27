#include <fstream>
#include <gr_types.hpp>
#include <iostream>
#include <reader.hpp>
#include <regex>
#include <string>

Reader::Reader(const std::string path) { this->path = path; }

void Reader::read_file() {
    std::ifstream inp(path);

    if (inp.fail()) {
        std::cerr << "Error: Failed to open file." << std::endl;
        return;
    }

    std::string line;

    while (getline(inp, line)) {
        std::regex words_regex("[^\\s]+");

        std::regex_iterator words_begin =
            std::sregex_iterator(line.begin(), line.end(), words_regex);
        std::regex_iterator words_end = std::sregex_iterator();

        for (std::regex_iterator i = words_begin; i != words_end; i++) {
            std::string match_str = i->str();
            this->word_dict[match_str]++;
        }
    }
}

void Reader::display_word_dict() {
    for (std::pair<const std::string, ll> p : this->word_dict) {
        std::cout << "WORD: " + p.first << " || HAS COUNT: " << p.second
                  << std::endl;
    }
}
