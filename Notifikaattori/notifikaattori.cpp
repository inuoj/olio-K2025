#include "notifikaattori.h"
#include <iostream>
using namespace std;

notifikaattori::notifikaattori() {
    cout<<"notifikaattorin konstruktori"<<endl;
}

void notifikaattori::lisaa(Seuraaja * A)
{
    A->next=nullptr;
    if(jotain == nullptr){
        jotain = A;
    } else {
        Seuraaja *temp = jotain;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        //A->next = jotain->next;
        //jotain = A;
        temp->next = A;

    }
    cout<<"Notifik. lisaa seuraajan "<<A->getNimi()<<endl;
}

void notifikaattori::poista(Seuraaja *A)
{
    // Jos poistettava solmu on ensimmäinen
    if (jotain == A) {
        jotain = jotain->next;
    }

    // Poisto tehdään ohittamalla olio
    Seuraaja * temp = jotain;
    while(temp -> next != nullptr){
        if(temp -> next == A){
            temp->next = temp->next->next;
        }
        temp = temp -> next;
    }
    cout<<"Notifikaattori poisti seuraajan "<<A->getNimi()<<endl;
}


void notifikaattori::tulosta()
{
    Seuraaja * temp = jotain;
    cout<<"\nNotifikaattorin seuraajat: \n";
    while(temp != nullptr){
        cout<<"Seuraaja "<<temp -> getNimi()<<" (osoite: "<<temp<<", next: "<<temp->next<<")"<<endl;
        temp = temp->next;
    }
}

void notifikaattori::postita(string s)
{
    Seuraaja * temp = jotain;
    cout<<"\nNotifikaattori postaa viestin: '"<<s<<"'"<<endl;
    while (temp != nullptr){
        cout<<"Seuraaja "<<temp -> getNimi()<<" sai viestin: "<<endl;
        temp->paivitys(s);
        temp = temp->next;
    }
}
