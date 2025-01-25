#include "italianchef.h"
#include <iostream>
#include <compare>

using namespace std;


italianChef::italianChef(string k):chef(k), flour(0), water(0){
    cout<<"Chef "<<k<<"'s constructor"<<endl;
}

italianChef::~italianChef() { cout<<"IC's destructor"<<endl; }


int italianChef::makepizza(int flour, int water)
{
    int x = flour/5;
    int y = water/5;
    int lkm;
    if(x>y){
        cout<<y<<" portions"<<endl;
        return y;
    } else if (x<y){
        cout << x << " portions"<< endl;
        return x;
    } else {
        cout << x << " portions"<< endl;
        return x;
    };
}


bool italianChef::askSecrect(string p, int f, int w)
{
    //Kysy salasanaa, jos ok:
    //Kutsu makepizza() funktiota
    cout<<"How many flour? How many water? "<<endl;
    cin >> f >> w;
    cout<<"Enter password: "<<endl;
    cin >> p;
    if(p.compare(password)==0){

        makepizza(f, w);
        cout << "pizzan valmistus"<<endl;
        return true;
    } else { cout<<"Wrong password!"<<endl; }

}
