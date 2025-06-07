#include <iostream>
using namespace std;

/*
Create a function that takes 3 parameters
-> Source
-> target
-> replaceText
Replace every occurrence of target in source with replace text
Example
replaceString('abcdabee', 'ab', 'xyz') -> 'xyzcdxyzee'
*/ 

typedef char *arrayString;

int stringLength(arrayString str) {
    int len = 0;
    while (str[len] != '0') {
        len++;
    }
    return len;
}

bool isMatch(arrayString source, int pos, arrayString target, int targetLen) {
    for (int i = 0; i < targetLen; i++) {
        if (source[pos + i] != target[i]) {
            return false;
        }
    }
    return true;
}

void replaceString(arrayString& source, arrayString target, arrayString replaceText) {
    int sourceLen = stringLength(source);
    int targetLen = stringLength(target);
    int replaceLen = stringLength(replaceText);

    // Step 1: Count how many times target appears in source for calculating new length
    int count = 0;
    for (int i = 0; i <= sourceLen - targetLen; ) {
        if (isMatch(source, i, target, targetLen)) {
            count++;
            i += targetLen;
        } else {
            i++;
        }
    }

    int newLen = sourceLen + count * (replaceLen - targetLen);
    arrayString newString = new char[newLen + 1]; // +1 for null terminator

    int i = 0; 
    int j = 0; 
    while (source[i] != '0') {
        if (isMatch(source, i, target, targetLen)) {
            for (int k = 0; k < replaceLen; k++) {
                newString[j++] = replaceText[k];
            }
            i += targetLen;
        } else {
            newString[j++] = source[i++];
        }
    }
    newString[j] = '0';

    // Replace old string
    delete[] source;
    source = newString;
}

int main() {
    
    arrayString source = new char[9];
    source[0] = 'a';
    source[1] = 'b';
    source[2] = 'c';
    source[3] = 'd';
    source[4] = 'a';
    source[5] = 'b';
    source[6] = 'e';
    source[7] = 'e';
    source[8] = '0';

    arrayString target = new char[3];
    target[0] = 'a';
    target[1] = 'b';
    target[2] = '0';

    arrayString replaceText = new char[4];
    replaceText[0] = 'x';
    replaceText[1] = 'y';
    replaceText[2] = 'z';
    replaceText[3] = '0';

    replaceString(source, target, replaceText);

    cout << source << endl; 

    delete[] source;
    delete[] target;
    delete[] replaceText;

    return 0;
}

