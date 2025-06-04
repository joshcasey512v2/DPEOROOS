#include <iostream>
using namespace std;

bool isSorted(int array[], int arraySize){
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] > array[i+1]) return false;
        
    }
    return true;
    
}

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE = 5;
    int testarray[ARRAY_SIZE] = {1,0,3,4,5};
    bool sorted = isSorted(testarray, ARRAY_SIZE);
    // 0 == False / 1 == True
    cout << sorted << endl;  
    return 0;
}
