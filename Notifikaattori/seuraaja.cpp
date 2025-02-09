#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string k):nimi(k) {
    cout<<"Luodaan seuraaja "<<k<<endl;
}

string Seuraaja::getNimi()
{
    //cout<<"Nimi on "<<nimi<<endl;
    return nimi;
}

void Seuraaja::paivitys(string s)
{
    // Tulosta konsolille saatu
    // viesti
    cout<<s<<endl;
}
