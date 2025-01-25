#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    string pswd;
    int wInput = 0;
    int flInput = 0;
    chef kokki1("Gordon Ramsay");
    italianChef kokki2("Jyrki Sukula");

    kokki1.makeSalad(19);
    kokki1.makeSoup(9);
    kokki2.makeSalad(11);
    kokki2.makeSoup(7);

    kokki2.askSecrect(pswd, wInput, flInput);
    return 0;
}
