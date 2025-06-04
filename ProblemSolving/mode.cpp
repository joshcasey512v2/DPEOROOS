#include <iostream>
using namespace std;
/*
Find The value in an array that appears the most often
*/
int compareFunction(const void* voidA, const void* voidB){
    int* intA = (int *)(voidA);
    int* intB = (int *)(voidB);
    return *intA - *intB;

}

int main(int argc, char const *argv[])
{
    const int ARRAR_SIZE = 12;
    int surveryData[ARRAR_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    // Finding the frequency of elements in the above array would be tricky
    // To make life easier for us, why not sort it?
    qsort(surveryData, ARRAR_SIZE, sizeof(int), compareFunction);
    int mostFrequent;
    int highestFrequent = 0;
    int currentFrequent = 0;
    for (int i = 0; i < ARRAR_SIZE; i++)
    {
        currentFrequent++;
        if (surveryData[i] != surveryData[i + 1] || i == ARRAR_SIZE -1)
        {
            if (currentFrequent > highestFrequent)
            {
                highestFrequent = currentFrequent;
                mostFrequent = surveryData[i];
            }
            
            currentFrequent = 0;
        }
        
    }
    cout << mostFrequent << endl;
    
    
    return 0;
}
