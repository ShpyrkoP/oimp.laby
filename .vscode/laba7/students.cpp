#include <iostream>
#include <cstring>
#include <iterator>
#include <vector>
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
    students(char* newName, int course, int group, int numGrade) : 
    name(nullptr), course(course), group(group), numGrade(numGrade)
    {
        count++;
        cnum = count;
        int length = strlen(newName);
        name = new char[length + 1];
        strcpy(name, newName);
    }
     //конструктор копирования
    students(const students& St1)  : 
    name(nullptr), course(St1.course), group(St1.group), numGrade(St1.numGrade)
    {
        count++;
        cnum = count;
        int length = strlen(St1.name);
        name = new char[length + 1];
        strcpy(name, St1.name);
    }
    virtual ~students()
    {
        delete[] name;
    }
    
    //геттеры и сеттеры
    const char* getName()
    {
        return name;
    }
    void setName(char* valueName)
    {
        delete[] name;
        int length = strlen(valueName);
        name = new char[length + 1];
        strcpy(name, valueName);
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
    int getCnum()
    {
        return cnum;
    }
    //метод вывода в поток
    virtual void print() const
    {
        std::cout << "Number: " << cnum << "\nName: " << name << "\nCourse: " << course << "\nGroup: " <<
        group << "\nStudent's ID number: " << numGrade << std::endl; 
    }
    virtual double GPA()
    {
        return 0;
    }
};
int students::count = 0;

class studentsFirstTerm : public students
{
    protected:
    int gradesFirstArr[4];
    public:
    studentsFirstTerm() = delete;
    //конструктор с параметрами
    studentsFirstTerm(char* name, int course, int group, int numGrade, int a, int b, int c, int d) 
    : students(name, course, group, numGrade)
    {
        gradesFirstArr[0] = a;
        gradesFirstArr[1] = b;
        gradesFirstArr[2] = c;
        gradesFirstArr[3] = d;
    }
    //конструктор копирования
    studentsFirstTerm(const studentsFirstTerm& St1)  : students(St1)
    {
        for (int i = 0; i < std::size(gradesFirstArr); i++)
        {
            this->gradesFirstArr[i] = St1.gradesFirstArr[i];
        }
    }
    //методы для доступа к оценке
    int getGrTerm1(int n)
    {
        if (n <= 4 && n > 0)
        {
        return gradesFirstArr[n-1];
        } else 
        {
            return gradesFirstArr[0];
        }
    }
    void setGr1Term(int n, int valueGr)
    {
        if (n <= 4 && n > 0)
        {
            gradesFirstArr[n-1] = valueGr;
        } else 
        {
            gradesFirstArr[0] = valueGr;
        }
    }
    //вывод в поток
    void print() const override
    {
        students::print();
        std::cout << "First term grades: ";
        for(int n = 0; n < std::size(gradesFirstArr); n++)
        {
            std::cout << gradesFirstArr[n] << " ";
        }
    }
    //средний балл после 1 сессии
    double GPA() override
    {
        int n = 0;
        int sumGrades{0};
        while (n < std::size(gradesFirstArr)) 
        {
            sumGrades += gradesFirstArr[n++];
        }
        return sumGrades / static_cast<double>(std::size(gradesFirstArr));
    }
};

class studentsSecondTerm : public studentsFirstTerm
{
    private:
    int gradesSecondArr[5];
    public:
    studentsSecondTerm() = delete;
//конструктор с параметрами
    studentsSecondTerm(char* name, int course, int group, int numGrade, int a, int b, int c, int d, int aa, int bb, int cc, int dd, int ee): 
    studentsFirstTerm(name, course, group, numGrade, a, b, c, d)
    {
        gradesSecondArr[0] = aa;
        gradesSecondArr[1] = bb;
        gradesSecondArr[2] = cc;
        gradesSecondArr[3] = dd;
        gradesSecondArr[4] = ee;
    }
    //конструктор копирования
    studentsSecondTerm(const studentsSecondTerm& St1)  : studentsFirstTerm(St1)
    {
        for (int i = 0; i < std::size(gradesSecondArr); i++)
        {
            this->gradesSecondArr[i] = St1.gradesSecondArr[i];
        }
    }
    //методы для доступа к оценке
    int getGr2Term(int n)
    {
        if (n <= 5 && n > 0)
        {
        return gradesSecondArr[n-1];
        } else 
        {
            return gradesSecondArr[0];
        }
    }
    void setGr2Term(int n, int valueGr)
    {
        if (n <= 5 && n > 0)
        {
            gradesSecondArr[n-1] = valueGr;
        } else 
        {
            gradesSecondArr[0] = valueGr;
        }
    }
    //вывод в поток
    void print() const override
    {
        studentsFirstTerm::print();
        std::cout << "Second term grades: ";
        for(int n = 0; n < std::size(gradesSecondArr); n++)
        {
            std::cout << gradesSecondArr[n] << " ";
        }
    }
    //средний балл за учебный год
    double GPA() override
    {
        int n = 0;
        int sumGrades1{0}, sumGrades2{0};
        while (n < std::size(gradesFirstArr))
        { 
            sumGrades1 += gradesFirstArr[n++];
        }
        n = 0;
        while (n < std::size(gradesSecondArr))
        { 
            sumGrades2 += gradesSecondArr[n++];
        }
        return (sumGrades1 + sumGrades2) / (static_cast<double>(std::size(gradesFirstArr)) + static_cast<double>(std::size(gradesSecondArr)));
    }
};

//средний балл по группе за 1 сессию
    double Group1GPA(int groupNum, std::vector<students*>& studentsArr)
    {
        double avg = 0;
        int count = 0;
        for (int i = 0; i < studentsArr.size(); i++)
        {
            if (studentsFirstTerm* ptr = dynamic_cast<studentsFirstTerm*>(studentsArr[i]))
            {
                if (ptr -> getGroup() == groupNum)
                {
                    avg += ptr -> GPA();
                    count++;
                }
            }
        }
        if (count == 0)
        {

            return 0;
        }
            return avg / count;
    }
  //средний балл по группе за учебный год
    double Group2GPA(int groupNum, std::vector<students*>& studentsArr)
    {
      double avg = 0;
        int count = 0;
        for (int i = 0; i < studentsArr.size(); i++)
        {
            if (studentsSecondTerm* ptr = dynamic_cast<studentsSecondTerm*>(studentsArr[i]))
            {
                if (ptr -> getGroup() == groupNum)
                {
                    avg += ptr -> GPA();
                    count++;
                }
            }
        }
        if (count == 0)
        {

            return 0;
        }
            return avg / count;  
    }