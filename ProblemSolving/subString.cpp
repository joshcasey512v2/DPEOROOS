#include <iostream>
using namespace std;

/*
Create a function that takes 3 Parameters
-> an arrayString
-> starting postiion interger
-> Integer length of characters
Example
subString('abcdefg', 3, 4) -> 'cdef'
*/

typedef char *arrayString;

void subString(arrayString &s, int startPosition, int length){
    arrayString newS = new char[length];
    for (int i = 0; i < length; i++)
    {
        newS[i] = s[i+startPosition-1];
    }
    delete[] s;
    s = newS;
}

int main(int argc, char const *argv[])
{
    arrayString test = new char[7];
    test[0] = 'a';
    test[1] = 'b';
    test[2] = 'c';
    test[3] = 'd';
    test[4] = 'e';
    test[5] = 'f';
    test[6] = 'g';
    subString(test, 3, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << test[i];
    }
    cout << endl;
    
    return 0;
}
