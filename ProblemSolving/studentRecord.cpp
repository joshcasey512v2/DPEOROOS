#include <iostream>
using namespace std;

class studentRecord{
public:
    string letterGrade();
    studentRecord();
    studentRecord(int grade, int id, string name);
    int grade();
    void setGrade(int newGrade);
    int studentId;
    void setStudentId(int newId);
    string name();
    void setName(string newName);
    bool isValidGrade(int grade);
private:
    int _grade;
    int _studentId;
    string _name;
};

studentRecord::studentRecord() {
    _grade = 0;
    _studentId = 0;
    _name = "";
}

int studentRecord::grade(){
    return _grade;
}

void studentRecord::setGrade(int newGrade){
    if (isValidGrade(newGrade)) _grade = newGrade;
}

void studentRecord::setStudentId(int newID){
    if (newID > 0) _studentId = newID;
}

void studentRecord::setName(string newName){
    if (newName !=  " ") _name = newName;
}

string studentRecord::letterGrade(){
    if (!isValidGrade(_grade)) return "Error";
    const int NUMBER_CATEGORYS = 11;
    const string GRADE_LETTER[] =    {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A+"};
    const int LOWEST_GRADE_SCORE[] = {0,   60,  67,   70,   73,  77,   80,   83,  87,   90,   93};
    int category = 0;
    while (category < NUMBER_CATEGORYS && LOWEST_GRADE_SCORE[category] <= _grade)
    {
        category++;
    }
    return GRADE_LETTER[category-1];

}

studentRecord::studentRecord(int newGrade, int newID, string newName){
    setGrade(newGrade);
    setStudentId(newID);
    setName(newName);
}

bool studentRecord::isValidGrade(int grade){
    if (grade >= 0 && grade <= 100)
    {
        return true;
    }
    else return false;

}

class studentCollection {
public:
    studentCollection();
    ~studentCollection();
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);

private:

    struct studentNode {
        studentRecord studentData;
        studentNode *next;
    };
    typedef studentNode *studentList;

    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};

studentCollection::studentCollection(){
    _listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent){
    studentNode *newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum){
    studentNode *ptr = _listHead;
    while (ptr != NULL && ptr->studentData.studentId != idNum) ptr = ptr->next;

    if (ptr == NULL)
    {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else
    {
        return ptr->studentData;
    }    
}

void studentCollection::removeRecord(int idNum){
    studentNode *loopPtr = _listHead;
    studentNode *prev = NULL;

    while (loopPtr != NULL && loopPtr->studentData.studentId != idNum)
    {
        prev = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr = NULL) return;
    if (prev == NULL)
    {
        _listHead = _listHead->next;
    } else {
        prev->next = loopPtr->next;
    }

    delete loopPtr;
}

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

// This function could be slapped into the destructor but its nice to have
// helper functions
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

int main(int argc, char const *argv[])
{
    studentCollection s;
    studentRecord stu3(100, 3, "Jed");
    studentRecord stu2(80, 2, "Josh");
    studentRecord stu1(75, 1, "Jakub");

    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.removeRecord(2);


    return 0;
}
