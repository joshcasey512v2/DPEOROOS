#include <iostream>
using namespace std;
typedef char *arrayString;

char characterAt(arrayString s,int position){
    return s[position];
}
// Helper function to find length of string
int length(arrayString s){
    int length = 0;
    while (s[length] != 0) length ++;
    return length;
}

// & needed to create new array in the heap 
void append(arrayString &s, char c){
    int oldLength = length(s);

    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++)
    {
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength+1] = 0;
    delete[] s;
    s = newS;
}

void concatenate(arrayString &s1, arrayString s2){
    int s1Length  = length(s1);
    int s2Length = length(s2);
    // Length of returned string is combination of both lengths plus a space for the termination character 0
    int newSLength = s1Length + s2Length + 1;

    arrayString newS = new char[newSLength];
    for (int i = 0; i < s1Length; i++)
    {
        newS[i] = s1[i];
    }
    for (int i = 0; i < s2Length; i++)
    {
        newS[s1Length + i] = s2[i];
    }
    newS[newSLength-1] = 0;
    delete[] s1;
    s1 = newS;
}

int main(int argc, char const *argv[])
{
    arrayString b = new char[3];
    b[0] = 'H';
    b[1] = 'i';
    b[2] = 0;
    
    arrayString a = new char[4];
    a[0] = 'B';
    a[1] = 'y';
    a[2] = 'e';
    a[3] = 0;
    cout << b  << " " << a << endl;
    concatenate(b, a);
    for (int i = 0; i < length(b); i++)
    {
        cout << b[i];
    }
    
    cout << endl;
     
    return 0;
}
