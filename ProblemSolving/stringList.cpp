#include <iostream>
using namespace std;

/*
Create an implementation for strings that uses a linked list
of characters instead of dynamically allocated arrays.
-> Create an append & characterAt function
*/

struct myString{
    char c;
    myString *nextChar;
};

typedef myString *mystring;

void append(mystring s, char c){
    myString *currPtr = new myString;
    myString *newChar = new myString;
    newChar->c = c;
    newChar->nextChar = NULL;

    currPtr = s;

    if (s == NULL) s = newChar;
    
    while (currPtr->nextChar != NULL) currPtr = currPtr->nextChar;

    currPtr->nextChar = newChar;
    
}

char characterAt(mystring s, int pos){
    myString *ptr = new myString;

    ptr = s;
    int count = 0;
    while (ptr != NULL)
    {
        if (count == pos)
        {
            return ptr->c;
        }
        count++;
        ptr = ptr->nextChar;
    }
    return ' ';
}

int main(int argc, char const *argv[])
{
    mystring s;
    myString *char1 = new myString;
    myString *char2 = new myString;
    myString *char3 = new myString;
    myString *char4 = new myString;
    myString *char5 = new myString;

    char1->c = 'H';
    char2->c = 'e';
    char3->c = 'l';
    char4->c = 'l';
    char5->c = 'o';

    s = char1;
    char1->nextChar = char2;
    char2->nextChar = char3;
    char3->nextChar = char4;
    char4->nextChar = char5;
    char5->nextChar = NULL;

    char1 = char2 = char3 = char4 = char5 = NULL;

    cout << characterAt(s, 2) << endl;
    append(s, '!');
    cout << characterAt(s, 5);
    
    return 0;
}

