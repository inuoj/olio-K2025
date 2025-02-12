#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "student.h"


using namespace std;
int main ()
{
    int selection =0;
    string name;
    int age;
    vector<Student> studentList;
    studentList = { {"Jouni", 21}, {"Eero", 22}, {"Kari", 59} };

while(selection < 5)
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout<<"Student name ?"<<endl;
            cin.ignore();
            getline (cin, name);

            cout<<"Student age ?"<<endl;
            cin>>age;
            studentList.emplace_back(name,age);

            break;
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for (auto it = studentList.begin(); it != studentList.end(); ++it) {
                cout <<"\nStudent "<< it->getName()<<endl;
                cout <<"Age "<<it->getAge()<<endl;
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            std::sort(studentList.begin(), studentList.end(),
                [](Student& a, Student& b) {
                    return a.getName() < b.getName();
                });

            // Tulostetaan oppilaat aakkosjärjestyksessä
            for (auto &opp : studentList) {
                cout << opp.getName() << "\n";
            }

            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            std::sort(studentList.begin(), studentList.end(),
                      [](Student& a, Student& b) {
                          return a.getAge() < b.getAge();
                      });

            // Tulostetaan oppilaat ikäjärjestyksessä
            for (auto &opp : studentList) {
                cout <<opp.getName()<<", age: "<< opp.getAge() << "\n";
            }
            break;
        case 4:
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout <<"Enter students name: "<<endl;
            cin.ignore();
            getline(cin, name);
            /*auto it = find_if(studentList.begin(), studentList.end(),[name, &b](Student &a){
                b = true;
                return name == a.getName();
            });*/ // EI toiminukkaan tälleen

            // it joku index, printataan se index?
            for (auto it = studentList.begin(); it != studentList.end(); ){
                if (it->getName() == name){
                    cout << it->getName() <<", age: "<< it->getAge()<<endl;
                    break;
                } else {
                    it++;
                } if (it == studentList.end()) {
                    cout << "Could not find student"<<endl;

                }
            }
            break;
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }

    }

    return 0;
}
