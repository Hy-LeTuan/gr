#pragma once

#include <functional>
#include <gr_types.hpp>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::pair;
using std::string;
using std::vector;

class Parser {
  public:
    virtual void process(string word) = 0;
    virtual void display() = 0;
};

class WordCountParser : public Parser {
  public:
    WordCountParser() {}
    void process(string word);
    void display();

  private:
    std::unordered_map<string, ll> word_dict;
};

class WordRankParser : public Parser {
  public:
    WordRankParser() {}
    void process(string word);
    void display();

  private:
    std::priority_queue<pair<int, string>, vector<pair<int, string>>,
                        std::less<pair<int, string>>>
        pq;
};
