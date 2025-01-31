#include "pankkitili.h"
#include <iostream>
using namespace std;

Pankkitili::Pankkitili(string k) {
    cout<<"Pankkitili luotu "<<k<<"lle!"<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double i)
{
    if (i < 0) {
        cout<<"Virhe!"<<endl;
        return false;
    } else {
        cout<<"Onnistui! Talletetaan..."<<endl;
        saldo += i;
        return true;
    }
}

bool Pankkitili::withdraw(double i)
{
    if (i < 0) {
        cout<<"Virhe!"<<endl;
        return false;
    }
    else if (i > saldo) {
        cout<<"Virhe!"<<endl;
        return false;
    }
    else {
        cout<<"Onnistui! Nostetaan"<<endl;
        saldo -=i;
        return true;
    }
}
