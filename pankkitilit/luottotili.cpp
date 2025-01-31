#include "luottotili.h"
#include <iostream>
using namespace std;

Luottotili::Luottotili(string k, double m):Pankkitili(k), luottoRaja(m)
{
    cout<<"Luottotili luotu "<<k<<"lle!"<<endl;
    cout<<"Luottoraja on "<<m<<" euroa.\n"<<endl;
}

bool Luottotili::deposit(double i)
{
    if (i < 0) {
        cout<<"Virhe! "<<endl;
        return false;
    } else if (i + saldo > 0){
        cout<<"Virhe! "<<endl;
        return false;
    } else {
        cout<<"Onnistui! Tallennetaan... "<<endl;
        saldo +=i;
        return true;
    }
}

bool Luottotili::withdraw(double i)
{
    if (i < 0) {
        cout<<"Virhe!"<<endl;
        return false;
    }
    else if (i + saldo > luottoRaja) {
        cout<<"Virhe!"<<endl;
        return false;
    }
    else {
        cout<<"Onnistui! Nostetaan... "<<endl;
        saldo -= i;
        return true;
    }
}
