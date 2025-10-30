#include <gr_types.hpp>
#include <parser.hpp>
#include <reader.hpp>

int main() {
    Reader reader("../data/ibm-1401-programming-systems-by-anonymous.txt",
                  WordCount);
    reader.read();
    reader.display_parser_metrics();

    return 0;
}
