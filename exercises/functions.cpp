#include "iostream"
// The line underneath omits the use of std:: 
using namespace std;

// TODO: Make a function to return the result of adding 2 numbers
int addTwoNumbers(int a, int b){
    // TODO: Add Logic here
    return a + b;
}

int main()
{
    int a = 5;
    int b = 5;
    int result = addTwoNumbers(a, b);
    cout << result << endl;
    return 0;
}