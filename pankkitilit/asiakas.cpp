#include "asiakas.h"
#include <iostream>
using namespace std;

Asiakas::Asiakas(string k, double m):kayttotili(k), nimi(k), luottotili(k,m)
{
    cout<<"Asiakas "<<k<<", tilit luotu."<<endl;
}

string Asiakas::getNimi()
{
    cout<<nimi<<endl;
    return nimi;
}

void Asiakas::showSaldo()
{
    //getBalance() pitää saada molemmista
    //Luottotili perii pankkitilin,
    //funktio pankkitiliolion sisällä
    cout<<"Pankkitilin saldo :"<< kayttotili.getBalance()<<" eur."<<endl;
    cout<<"Luottotilin saldo :"<< luottotili.getBalance()<<" eur.\n"<<endl;
}

bool Asiakas::talletus(double i)
{  
    return kayttotili.deposit(i);
}

bool Asiakas::nosto(double i)
{
    return kayttotili.withdraw(i);
}

bool Asiakas::luotonMaksu(double i)
{
    return luottotili.deposit(i);
}

bool Asiakas::luotonNosto(double i)
{
    return luottotili.withdraw(i);
}
