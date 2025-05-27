#include <iostream>
#include <string>

// Define a class named MyClass
class MyClass
{
private:
    // Private member variable to store the name
    std::string name;

public:
    // Constructor declaration: called when an object is created
    MyClass(std::string n);

    // Destructor declaration: called when an object is destroyed
    ~MyClass();
};

// Constructor definition
// This initializes the 'name' member using an initializer list
// and prints a message indicating that the object has been created.
MyClass::MyClass(std::string n) : name(n)
{
    std::cout << "Constructor => MyClass object for \"" << name << "\" created." << std::endl;
}

// Destructor definition
// This is automatically called when the object goes out of scope.
// It prints a message indicating that the object is being destroyed.
MyClass::~MyClass()
{
    std::cout << "Destructor => MyClass object for \"" << name << "\" destroyed." << std::endl;
}

// Main function to demonstrate the use of constructor and destructor
int main()
{
    // Create an instance of MyClass.
    // This triggers the constructor.
    MyClass obj("CPlus");

    // When main() ends and 'obj' goes out of scope,
    // the destructor is automatically called.
    return 0;
}

