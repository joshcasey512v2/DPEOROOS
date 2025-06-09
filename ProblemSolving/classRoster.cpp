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

int main(int argc, char const *argv[])
{
    studentRecord object1;
    object1.setGrade(80);
    object1.setStudentId(1);
    object1.setName("Josh");
    cout << object1.letterGrade() << endl;
    
    return 0;
}
