#include "chef.h"
#include <iostream>
using namespace std;



chef::chef(string k):chefName(k) {
    cout<<"Chef "<<k<<"'s constructor"<<endl;
}
chef::~chef() {
    cout<<"chefs destructor"<<endl;
}


string chef::getName() {
    return chefName;
}

int chef::makeSalad(int n) {
    cout<<chefName<<" make Salad"<<endl;
    cout<<n/5<<" portions"<<endl;
    return n/5;
}

int chef::makeSoup(int s) {
    cout<<chefName<<" make Soup"<<endl;
    cout<<s/3<<" portions."<<endl;
    return s/3;
}
