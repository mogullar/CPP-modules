#include <cctype>
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
    int size = sizeof(argv) / sizeof(argv[0]);
    std::stringstream ss;
    std::string result;

    for (size_t i = 1; i <= size; i++){
        ss << argv[i];
    }

    result = ss.str();

    for (size_t i = 0; i < result.length(); i++){
        result[i] = std::toupper(result[i]);
    }

    std::cout << result << std::endl;
}