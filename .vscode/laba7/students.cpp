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
    name(St1.name), course(St1.course), group(St1.group), numGrade(St1.numGrade)
    {
        count++;
        cnum = count;
    }
    
    //геттеры и сеттеры
    char* getName()
    {
        return name;
    }
    void setName(char* valueName)
    {
        name = valueName;
    }
    int getCourse()
    {
        return course;
    }
    void setCourse(int valueCourse)
    {
        course = valueCourse;
    }
    int getGroup()
    {
        return group;
    }
    void setGroup(int valueGroup)
    {
        group = valueGroup;
    }
    int getNumGrade()
    {
        return numGrade;
    }
    int getCount()
    {
        return cnum;
    }
    //метод вывода в поток
    virtual void print() const
    {
        std::cout << "Number: " << cnum << "\nName: " << name << "\nCourse: " << course << "\nGroup: " <<
        group << "\nStudent's ID number: " << numGrade << std::endl; 
    }
};

class studentsFirstTerm : public students
{
    protected:
    int gradesFirstArr[4];
    public:
    studentsFirstTerm() = delete;
    //конструктор с параметрами
    studentsFirstTerm(int a, int b, int c, int d) : students(name, course, group, numGrade)
    {
        gradesFirstArr[0] = a;
        gradesFirstArr[1] = b;
        gradesFirstArr[2] = c;
        gradesFirstArr[3] = d;
    }
    //конструктор копирования
    studentsFirstTerm(const studentsFirstTerm& St1)  : students(St1)
    {
        *this->gradesFirstArr = *gradesFirstArr;
    }
    //методы для доступа к оценке
    int getGrTerm1(int n)
    {
        return gradesFirstArr[n-1];
    }
    void setGr1Term(int n, int valueGr)
    {
        gradesFirstArr[n-1] = valueGr;
    }
    //вывод в поток
    void print() const override
    {
        students::print();
        std::cout << "First term grades: " << gradesFirstArr;
    }
    //средний балл после 1 сессии
    virtual int GPA()
    {
        int n = 0;
        int sumGrades;
        while (n<sizeof(gradesFirstArr)) 
        {
            sumGrades += gradesFirstArr[n++];
        }
        return sumGrades / sizeof(gradesFirstArr);
    }
    //средний балл по группе за 1 сессию
    int Group1GPA(int groupNum)
    {
        int avg;
        int count = 0;
        if (group == groupNum)
        {
            avg += GPA();
            count++;
        }
        return avg / count;
    }
};

class studentsSecondTerm : public studentsFirstTerm
{
    private:
    int gradesSecondArr[5];
    public:
    studentsSecondTerm() = delete;
//конструктор с параметрами
    studentsSecondTerm(int a, int b, int c, int d, int e) : studentsFirstTerm(a, b, c, d)
    {
        gradesFirstArr[0] = a;
        gradesFirstArr[1] = b;
        gradesFirstArr[2] = c;
        gradesFirstArr[3] = d;
        gradesFirstArr[4] = e;
    }
    //конструктор копирования
    studentsSecondTerm(const studentsSecondTerm& St1)  : studentsFirstTerm(St1)
    {
        *this->gradesSecondArr = *gradesSecondArr;
    }
    //методы для доступа к оценке
    int getGr2Term(int n)
    {
        return gradesSecondArr[n-1];
    }
    void setGr2Term(int n, int valueGr)
    {
        gradesSecondArr[n-1] = valueGr;
    }
    //вывод в поток
    void print() const override
    {
        studentsFirstTerm::print();
        std::cout << "Second term grades: " << gradesSecondArr;
    }
    //средний балл за учебный год
     virtual int GPA() override
    {
        int n = 0;
        int sumGrades1, sumGrades2;
        while (n < sizeof(gradesFirstArr))
        { 
            sumGrades1 += gradesFirstArr[n++];
        }
        n = 0;
        while (n < sizeof(gradesSecondArr))
        { 
            sumGrades2 += gradesSecondArr[n++];
        }
        return (sumGrades1 + sumGrades2) / (sizeof(gradesFirstArr) + sizeof(gradesSecondArr));
    }
     //средний балл по группе за учебный год
    int Group2GPA(int groupNum)
    {
        int avg;
        int count = 0;
        if (group == groupNum)
        {
            avg += GPA();
            count++;
        }
        return avg / count;
    }
};