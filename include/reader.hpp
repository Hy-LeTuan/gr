#pragma once

#include <gr_types.hpp>
#include <string>
#include <unordered_map>

class Reader {
  public:
    std::string path;
    std::unordered_map<std::string, ll> word_dict;

    Reader(const std::string path);
    void read_file();
    void display_word_dict();
};
