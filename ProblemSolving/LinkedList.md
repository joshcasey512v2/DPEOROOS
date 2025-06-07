# Linked Lists in C++

A **linked list** is a linear data structure where each element (called a **node**) contains:
- Data (in this case, `studentNum` and `grade`)
- A pointer to the **next node** in the sequence

This tutorial explains the basic structure and operations of singly linked lists using C++.

---

## Structure of a Node

```cpp
struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};
```

Each `listNode` contains:
- `studentNum`: Unique student identifier
- `grade`: Student's grade
- `next`: Pointer to the next node in the list

```cpp
typedef listNode *studentCollection;
```

This line defines `studentCollection` as a pointer to a `listNode`, representing the head of the list.

---

## ➕ Adding a Node to the Beginning

```cpp
void addRecord(studentCollection &sc, int studentNum, int grade){
    listNode *newNode = new listNode;
    newNode->studentNum = studentNum;
    newNode->grade = grade;
    newNode->next = sc;
    sc = newNode;
}
```

This function:
- Dynamically allocates memory for a new node.
- Sets the student data.
- Points the new node to the current head (`sc`).
- Updates `sc` to point to the new node (making it the new head).

---

## Traversing the List and Calculating Average Grade

```cpp
double averageGrade(studentCollection sc){
    if (sc == NULL) return 0;

    int count = 0;
    int sum = 0;
    listNode *loopPtr = sc;
    while (loopPtr != NULL)
    {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}
```

This function:
- Checks if the list is empty.
- Uses a loop to traverse each node.
- Accumulates grades and counts students.
- Returns the average grade.



---

## Main Function – Building the List

Here, we use `addRecord` to add students to the list:

```cpp
int main() {
    studentCollection sc = NULL;

    addRecord(sc, 3, 84);
    addRecord(sc, 2, 89);
    addRecord(sc, 1, 90);

    cout << averageGrade(sc) << endl;

    return 0;
}
```

This will build the list in reverse order (latest added at the head), so the final list is:
```
1 → 2 → 3 → NULL
```

---

## Sample Output

```
87.6667
```

(Computed as `(90 + 89 + 84) / 3`)

---

