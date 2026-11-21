#include <iostream>
#ifndef STUDENTS_HPP
#define STUDENTS_HPP

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
    students(char* name, int course, int group, int numGrade);
    students(const students& St1);
    char* getName();
    void setName(char* valueName);
    int getCourse();
    void setCourse(int valueCourse);
    int getGroup();
    void setGroup(int valueGroup);
    int getNumGrade();
    int getCount();
    virtual void print() const;
};

class studentsFirstTerm : public students
{
    protected:
    int gradesFirstArr[4];
    public:
    studentsFirstTerm() = delete;
    studentsFirstTerm(int a, int b, int c, int d);
    studentsFirstTerm(const studentsFirstTerm& St1);
    int getGrTerm1(int n);
    void setGr1Term(int n, int valueGr);
    void print() const override;
    virtual int GPA();
    int Group1GPA(int groupNum);
};

class studentsSecondTerm : public studentsFirstTerm
{
    private:
    int gradesSecondArr[5];
    public:
    studentsSecondTerm() = delete;
    studentsSecondTerm(int a, int b, int c, int d, int e);
    studentsSecondTerm(const studentsSecondTerm& St1);
    int getGr2Term(int n);
    void setGr2Term(int n, int valueGr);
    void print() const override;
    virtual int GPA() override;
    int Group2GPA(int groupNum);
};

#endif

