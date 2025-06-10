# Classes & OOP
- A **class** is a blueprint for constructing a particular package of code and data.
- Each variable created according to the classes blueprint is known as an **object** of that class
- Code outside the class that uses it is known as a **client** of the class
- A **class declaration** names the class and lists all of the **members** or items inside the class.
- Each item is either a 
    - **Data Item:** Variable declared within the class
    - **Method / Member function:** Function delcared within the class 
- **Constructor:** A special function that has the same name as the class and is invoked implicitly when an object of the class is declared
- **Access Specifier:** Indicates what functions can access the member.
    - **Public:** Accessed by any code using the object
    - **Private:** Accessed only by the code inside the class
    - **Protected:** Similar to private except methods in subclasses can also reference them.
```c++
class Sample{       // 1
public:             // 2
    Sample();       // 3
    Sample(int num);// 4
    int doSomthing(double param); // 5
private:
    int data; // 6
}
```

- 1: Name of the class
- 2: public access specifier
- 3: Default Constructor
- 4: Second constructor
- 5: Class method
- 6: Private data member

```c++
sample object1();    // Invokes default constructor
sample object2(15);  //  Invokes second constructor
```
---
## Goals of Class Use
- Encapsulation
- Code Reuse
- Dividing the Problem
- Information Hiding
- Readability
- Expressiveness

### Destructor
- Method called when an object goes out of scope
- Needed for use with dynamic data
- Example from *studentRecord.cpp*

```c++
void studentCollection::deleteList(studentList &listPtr){
    while (listPtr != NULL)
    {
        studentNode *tmp = listPtr;
        listPtr = listPtr->next;
        delete tmp;
    }
    
}

studentCollection::~studentCollection(){
    deleteList(_listHead);
}
```

---
### Deep Copy
- **Deep Copy:** Essentialy make a copy of everything in the structure
- **Cross Linking:** Where 2 pointer variables have the same value
- 2 distinct variables but they point to the same data structure
- Here we would have no issue

```c++
int x = 10;
int y = 5;
x = y;
x = 5;
```

- However, consider the following

```c++
studentCollection s1;
studentCollection s2;
studentRecord r1(85, 99837, "Josh");
s2.addRecord(r1);
studentRecord r2(100, 4756, "Jed");
s2.addRecord(r2);
s1 = s2;
s2.removeRecord(99837);
```

- Although s1 and s2 are two different objects, they are no longer entirely seperate objects.
- This is known as a *Shallow copy*
- This means that each data member of one object is directly assigned to the other

- Example of a deep copy (directly coppying the node)

```c++
studentCollection::studentList studentCollection::copiedList(const studentList original){
    if (original == NULL) return NULL;

    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode *oldPtr = original->next;
    studentNode *newPtr = newList;

    while (oldPtr != NULL)
    {
        newPtr->next = new studentNode;
        newPtr = newPtr->next;
        newPtr->studentData = oldPtr->studentData;
        oldPtr = oldPtr->next;
    }
    newPtr->next = NULL;
    return newList;
}
```