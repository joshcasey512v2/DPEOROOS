#include <iostream>
using namespace std;

struct student
{
    int grade;
    int studentId;
    string name;
};


int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE = 5;
    student studentArray[ARRAY_SIZE] = {
        {87, 1, "Josh"},
        {100, 2, "Jed"},
        {90, 3, "Jakub"},
        {99, 4, "Robert"},
        {80, 5, "Evun"}
    };

    // Find the highest grade
    int highestGrade = studentArray[0].grade;
    string bestStudent = studentArray[0].name;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (studentArray[i].grade > highestGrade)
        {
            highestGrade = studentArray[i].grade;
            bestStudent = studentArray[i].name;
        }
        
    }
    
    cout << "Highest grade: " << highestGrade  << " by " << bestStudent << endl;
    return 0;
}

