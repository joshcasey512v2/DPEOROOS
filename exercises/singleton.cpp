// singleton.cpp
// Fix the Singleton implementation.

#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void sayHello() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton::getInstance().sayHello();
    return 0;
}
