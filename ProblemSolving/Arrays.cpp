#include <iostream>
using namespace std;

int compareFunction(const void* voidA, const void* voidB){
    int* intA = (int *)(voidA);
    int* intB = (int *)(voidB);
    return *intA - *intB;

}

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE = 10;
    int gradeArray[ARRAY_SIZE] = {87, 76, 100, 97, 64, 83, 88, 92, 74, 97};
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += gradeArray[i];
    }
    double average = sum / ARRAY_SIZE;
    cout << average << endl;
    
    
    
    return 0;
}
