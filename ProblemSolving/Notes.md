# Array Fundamentals
- **Array:** Collection of variables of the same type organised under one name.
- Individual variables in an array are known as elements of the array
- The First element of the array has the number 0.
- **Random access:** Access any element of the array at any time 

## Array Operations
### Store
- An array is a collection of variables and we can assign a value to each of those
- Initialising an Array

``` int tenIntegerArray[10] = {2, 5, 3, 8, 9, 6, 1, 7, 4, 10} ```
- Assigning a Value to the array

``` 
int tenIntegerArray[0] = 5;
int tenIntegerArray[10] = {5, 5, 3, 8, 9, 6, 1, 7, 4, 10};
 ```
- Initialise an array of size 10 with every element being -1

``` 
int tenIntegerArray[10];
for (int i = 0; i < 10; i++) tenIntegerArray[i] = -1;
```
---
### Copy
- Make a copy of an array, Why?
    - Manipulate the array but require the original for further processing
    -   Copy part of an array for reordering

```
int tenIntegerArray[10] = {5, 5, 3, 8, 9, 6, 1, 7, 4, 10};
int secondArray[10];
for (int i = 0; i < 10; i++) secondArray[i] = tenIntegerArray[i];
```
---
### Retrieval & Search
- Retrieving a value from a specific location
```
int number = tenIntegerArray[0]
```
- **Searching for a specfic Value**
```
const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 3987, -287, 1};
    int targetValue = 12;
    int targetPosition = 0;
    while ((intArray[targetPosition] != targetValue) && (targetPosition < ARRAY_SIZE))
    {
        targetPosition++;
    }
    cout << "Target Value: " << targetValue << " can be found at position: " << targetPosition << endl; 
```

- **Criterion-Based Search (Highest Value)**
```
const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 3987, -287, 1};
    int highestValue = intArray[0];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if(intArray[i] > highestValue) highestValue = intArray[i];
    }
    
    cout << "Highest Value: " << highestValue << endl;
```
---

### Sort
- Putting data in a specified order
- Fast & Easy Sorting: **qsort**
```
int compareFunction(const void* voidA, const void* voidB){
    int* intA = (int *)(voidA);
    int* intB = (int *)(voidB);
    return *intA - *intB;

}

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 3987, -287, 1};
    qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunction);
    
    return 0;
}
```
- Easy to modify: **Insertion Sort**
```
const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 3987, -287, 1};
    int start = 0;
    int end  = ARRAY_SIZE -1;
    for (int i = start+1; i < end; i++)
    {
        for (int j = i; i < j > start && intArray[j-1] > intArray[j]; j--)
        {
            int tmp = intArray[j-1];
            intArray[j-1] = intArray[j];
            intArray[j] = tmp;
        }
        
    }
```
---
### Compute Statistics
- Computing the average
```
const int ARRAY_SIZE = 10;
    int gradeArray[ARRAY_SIZE] = {87, 76, 100, 97, 64, 83, 88, 92, 74, 97};
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += gradeArray[i];
    }
    double average = sum / ARRAY_SIZE;
    cout << average << endl;
```
- Occurances of negatives
```
const int ARRAY_SIZE = 10;
int countNegatives = 0;
int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 3987, -287, 1};
for (int i = 0; i < ARRAY_SIZE; i++){
    if (intArray[i] < 0) countNegatives++;
}
```