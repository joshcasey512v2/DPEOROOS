#include "iostream"

// Just like C, C++ is a statically typed language
// Every variable must be Declared its type

int main()
{
    int number = 5;
    float decimal = 2.2;
    // String type is imported from the standard library
    std::string word = "Hello";
    char c = 'c';
    bool right = true;
    bool wrong = false;

    std::cout << number << std::endl;
    std::cout << decimal << std::endl;
    std::cout << word << std::endl;
    std::cout << c << std::endl;
    std::cout << right << std::endl;
    // The compiler will complain not all variables are used
    // TODO: Print out the unused variable using the std library
    std::cout << wrong << std::endl;
    
    return 0;
}
