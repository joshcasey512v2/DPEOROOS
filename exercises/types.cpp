#include "iostream"

// Just like C, C++ is a statically typed language
// Every variable must be Declared its type

int main()
{
    int number = 5; // 2/4 Bytes
    float decimal = 2.2; // 4 Bytes
    // String type is imported from the standard library
    std::string word = "Hello";
    char c = 'c'; // 1 Byte
    bool right = true; // 1 Byte
    bool wrong = false; // 1 Byte
    double bigDecimal = 2.333333; // 8 Bytes

    std::cout << number << std::endl;
    std::cout << decimal << std::endl;
    std::cout << word << std::endl;
    std::cout << c << std::endl;
    std::cout << right << std::endl;
    // The compiler will complain not all variables are used
    // TODO: Print out the unused variable using the std library

    return 0;
}
