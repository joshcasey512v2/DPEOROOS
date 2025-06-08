#include <iostream>
using namespace std;

/*
Implement a concatenate function for strings using linked lists
Example
-> s1 = 'ab'
-> s2 = 'cd'
-> concatenate(s1, s2) = 'abcd'
*/

struct myString{
    char c;
    myString *nextChar;
};

typedef myString *str;

void concatenate(str s1, str s2){
    // Base case
    if (s1 == NULL)
    {
        s1 = s2;
        return;
    }
    
    myString *ptr = new myString;    
    ptr = s1;
    while (ptr->nextChar != NULL)
    {
        ptr = ptr->nextChar;
    }
    ptr->nextChar = s2;
}

int main(int argc, char const *argv[])
{
    str s1;
    str s2;

    myString *char1 = new myString;
    myString *char2 = new myString;
    myString *char3 = new myString;
    myString *char4 = new myString;

    char1->c = 'a';
    char2->c = 'b';
    char3->c = 'c';
    char4->c = 'd';

    s1 = char1;
    char1->nextChar = char2;
    char2->nextChar = NULL;

    s2 = char3;
    char3->nextChar = char4;
    char4->nextChar = NULL;

    char1 = char2 = char3 = char4 = NULL;

    concatenate(s1, s2);

    myString *ptr = new myString;
    ptr = s1;
    while (ptr != NULL)
    {
        cout << ptr->c;
        ptr = ptr->nextChar;
    }
    cout << endl;

    
    return 0;
}
