#include <algorithm>
#include <iostream>
#include <parser.hpp>

void WordCountParser::process(string word) {
    std::transform(word.begin(), word.end(), word.begin(), tolower);
    this->word_dict[word]++;
}

void WordCountParser::display() {
    for (pair<const string, ll> p : this->word_dict) {
        std::cout << "WORD: " + p.first << " | COUNT: " << p.second
                  << std::endl;
    }
}

void WordRankParser::process(string word) {}
void WordRankParser::display() {}
