#include <iostream>
#include "students.hpp"

class students
{
    protected:
    static int count;
    int cnum;
    char* name;
    int course;
    int group;
    const int numGrade;
    public:
    students() = delete;
    //конструктор с параметрами
    students(char* name, int course, int group, int numGrade) : 
    name(name), course(course), group(group), numGrade(numGrade)
    {
        count++;
        cnum = count;
    }
    //конструктор копирования
    students(const students& St1)  : 
    numGrade(St1.numGrade), name(St1.name), course(St1.course), group(St1.group)
    {
        count++;
        cnum = count;
    }
};

class studentsFirstTerm : public students
{
    protected:
    int gradesFirstArr[4];
    public:
    studentsFirstTerm() = delete;


};

class studentsSecondTerm : public studentsFirstTerm
{
    private:
    int gradesSecondArr[5];
    public:
    studentsSecondTerm() = delete;



};