#include <reader.hpp>

int main() {
    Reader reader("../data/ibm-1401-programming-systems-by-anonymous.txt");
    reader.read_file();

    reader.display_word_dict();

    return 0;
}
