#include <cctype>
#include <fstream>
#include <gr_types.hpp>
#include <iostream>
#include <parser.hpp>
#include <reader.hpp>
#include <regex>
#include <string>

void Reader::display_parser_metrics() { this->parser->display(); }

Reader::Reader(const std::string path_, ParserTypes parser_type) : path(path_) {
    switch (parser_type) {
    case WordCount:
        this->parser = new WordCountParser();
        break;
    case WordRank:
        this->parser = new WordRankParser();
    }
}

void Reader::read() {
    std::ifstream inp(path);

    if (inp.fail()) {
        std::cerr << "Error: Failed to open file." << std::endl;
        return;
    }

    std::regex begin_regex(".*START OF THE PROJECT GUTENBERG EBOOK.*");
    std::regex end_regex(".*General Information About Project Gutenberg.*");
    std::string line;
    bool is_begin = false;

    try {
        while (getline(inp, line)) {
            if (!is_begin && std::regex_search(line, begin_regex)) {
                is_begin = true;
                continue;
            } else if (is_begin && std::regex_search(line, end_regex)) {
                is_begin = false;
                continue;
            }

            if (is_begin && line.size() > 0) {
                std::regex words_regex("[^\\s]+");

                const std::regex_iterator words_begin =
                    std::sregex_iterator(line.begin(), line.end(), words_regex);
                const std::regex_iterator words_end = std::sregex_iterator();

                for (std::regex_iterator i = words_begin; i != words_end; i++) {
                    std::string match_str = i->str();
                    this->parser->process(match_str);
                }
            }
        }
    } catch (...) {
        std::cerr << "Error: Something wrong occurred when parsing text file"
                  << std::endl;
    }
}
