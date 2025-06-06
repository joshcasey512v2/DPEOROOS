# Pointers
- Pointers in C++ are indicated with astericks (*)
- Declaring a pointer we put an asterick between the type and name
``` 
int *myPointer;
```
- Note the following will only declare variable1 as a pointer and variable2 will just be of type int
```
int * variable1, variable2;
```
- An ampersand (&) infront of a variable acts as the *address of* operator.
```
variable1 = &variable2;
```
- We can assign one pointer variable to another directly
```
myPointer = variable1;
```
- Most importantly we can allocate memory during runtime that can be accesed through a pointer using the *new* operator
```
double *myPointer = new double;
```
- Accessing the memory at the other end of pointer is known as *dereferencing*
- This is accomplished with an asterick to the left of a pointer identifier
```
myPointer = 35.4;
int localDouble = *myPointer;
```
- To deallocate memory allocated with new, we use the kewword *delete*
```
delete myPointer;
```
---
## Benefits of pointers
- Runtime-Sized data structures
- Resizable data structures
- Memory sharing

## When to use
- Cant estimate amount of data ahead of runtime
- If you need a structure that can grow and shrink during execution
- Large objects or other blocks of data being passed around your program
---

# The Stack & The Heap
- C++ allocates memory in 2 places: the *stack* and the *heap*
- **Stack:** Organised and Neat
- **Heap:** Disjoint and Messy
- Everytime a function is called a block of memory is allocated on the top of the runtime stack
- The block of memory is called an **activation record**
- **Memory Fragmentation:** Gaps between remaining allocated memory blocks caused from many allocations and deallocations
- Each call to *new* or *malloc* sets aside a chunk of memory in the heap and returns a pointer to the chunk. 
- **LifeTime:** Time span between allocation and deallocation
- **Memory Leak:** Memory is allocated from the heap but never deallocated and not referenced by any pointer.
```
int *myPointer = new int;
myPointer = NULL;
```


