#include <iostream>
using namespace std;

struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};

typedef listNode *studentCollection;

// Adding a Node
// as we are changing sc we add it as a reference parameter &sc
void addRecord(studentCollection &sc, int studentNum, int grade){
    listNode *newNode = new listNode;
    newNode->studentNum = studentNum;
    newNode->grade = grade;
    newNode->next = sc;
    sc = newNode;
}

// Traversing a Linked List
// Average Grade
double averageGrade(studentCollection sc){
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

int main(int argc, char const *argv[])
{
    studentCollection sc;
    listNode *node1 = new listNode;
    node1->studentNum = 1;
    node1->grade = 90;
    listNode *node2 = new listNode;
    node2->studentNum = 2;
    node2->grade = 89;
    listNode *node3 = new listNode;
    node3->studentNum = 3;
    node3->grade = 84;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    // Avoid potential cross linking problems
    node1 = node2 = node3 = NULL;
    cout << averageGrade(sc) << endl;

    return 0;
}
