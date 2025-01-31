#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"
using namespace std;

int main()
{
    /*Asiakas tili1("Jouni Laiti", 2500.0);
    cout<<"Tulostetaan nimi \n";

    tili1.getNimi();
    tili1.talletus(60);
    tili1.showSaldo();*/

    string nimi;
    int ltraja, pick, amount;

        cout<<"Tilin omistajan nimi?"<<endl;
        getline(cin, nimi);
        cout<<"Aseta luottoraja: "<<endl;
        cin>>ltraja;

    Asiakas t1(nimi,ltraja);

        cout<<"Saldosi on: "<<endl;
        t1.showSaldo();

    cout<<"Anna summa: \nPankki (1)\nLuotto (2)"<<endl;
    cin>>pick;
    switch(pick){
    case 1:
        cout<<"Talleta (1) tai nosta(2) rahaa?"<<endl;
        cin>>pick;
        switch(pick) {
        case 1:
            cout<<"Anna summa:"<<endl;
            cin>>amount;
            t1.talletus(amount);
            break;
        case 2:
            cout<<"Anna summa:"<<endl;
            cin>>amount;
            t1.nosto(amount);
            break;
        default:
            cout<<"Vaara valinta"<<endl;
        }
        break;
    case 2:
        cout<<"Talleta (1) tai nosta(2) rahaa?"<<endl;
        cin>>pick;
        switch(pick) {
        case 1:
            cout<<"Anna summa: "<<endl;
            cin>>amount;
            t1.luotonMaksu(amount);
            break;
        case 2:
            cout<<"Anna summa: "<<endl;
            cin>>amount;
            t1.luotonNosto(amount);
            break;
        default:
            cout<<"Vaara valinta"<<endl;
        }
        break;
    }
    cout<<"Saldosi on: "<<endl;
    t1.showSaldo();


    return 0;
}
