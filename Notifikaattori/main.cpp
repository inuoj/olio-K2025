#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"

using namespace std;

int main()
{
    notifikaattori n;

    Seuraaja a("Aapo");
    Seuraaja b("Eero");
    Seuraaja c("miniEero");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();

    n.postita("Viesti 1");

    n.poista(&a);
    n.tulosta();

    n.postita("Viesti 2");

    return 0;
}
