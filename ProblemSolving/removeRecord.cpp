#include <iostream>
using namespace std;

/*
write a function that takes a pointer to a studentCollection
and a student number and removes the record with that student 
number from the collection
-> removeRecord(studentCollection &s, int studentNumer)
*/

struct listNode{
    int studentNumber;
    int grade;
    listNode *next;
};

typedef listNode *studentCollection;

void removeRecord(studentCollection &s, int studentNumber){
    listNode *currPtr = new listNode;
    listNode *prevPtr = new listNode;

    currPtr = s;
    while (currPtr != NULL)
    {
        if (currPtr->studentNumber == studentNumber)
        {
            prevPtr->next = currPtr->next;
            delete currPtr;
        }
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    
}

int main(int argc, char const *argv[])
{
    studentCollection sc;

    // Student 1
    listNode *node1 = new listNode;
    node1->studentNumber = 1;
    node1->grade = 100;

    // Student 2
    listNode *node2 = new listNode;
    node2->studentNumber = 2;
    node2->grade = 90;

    // Student 3
    listNode *node3 = new listNode;
    node3->studentNumber = 3;
    node3->grade = 80;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node1 = node2 = node3 = NULL;

    cout << "Before Deletion" << endl;
    listNode *before = sc;
    while (before != NULL)
    {
        cout << before->studentNumber << endl;
        before = before->next;
    }

    removeRecord(sc, 2);

    cout << "After Deletion" << endl;
    while (sc != NULL)
    {
        cout << sc->studentNumber << endl;
        sc = sc->next;
    }
    


    return 0;
}
