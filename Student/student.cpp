#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(string s, int i):name(s),age(i)
{
    //Konstruktori studentille
}

void Student::setAge(int k)
{
    age = k;
}

void Student::setName(string s)
{
    name = s;
}

string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

void Student::printStudentInfo()
{
    cout<<"Student name: "<<name<<endl;
    cout<<"Student age: "<<age<<endl;

}
