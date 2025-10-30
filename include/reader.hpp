#pragma once

#include <gr_types.hpp>
#include <parser.hpp>
#include <string>

class Reader {
  public:
    Reader(const std::string path_, Parser &parser_)
        : path{path_}, parser{&parser_} {}

    Reader(const std::string path_, ParserTypes parser_type);

    void read();
    void display_parser_metrics();

  private:
    std::string path;
    Parser *parser;
};
