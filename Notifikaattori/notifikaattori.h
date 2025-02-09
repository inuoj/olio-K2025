#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include <string>
using namespace std;
#include "seuraaja.h"

class notifikaattori
{
public:
    notifikaattori();
    void lisaa(Seuraaja *);
    void poista(Seuraaja *);
    void tulosta();
    void postita(string);

private:
    Seuraaja *jotain = nullptr;
};

#endif // NOTIFIKAATTORI_H
