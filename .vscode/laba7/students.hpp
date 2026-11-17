#include <iostream>
#ifndef STUDENTS_HPP
#define STUDENTS_HPP

class students
{
    protected:
    static int count;
    char* name;
    int course;
    int group;
    const int numGrade;
    public:
    students() = delete;
    students(char* name, int course, int group, int numGrade);
    students(const students& St1);
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

#endif

