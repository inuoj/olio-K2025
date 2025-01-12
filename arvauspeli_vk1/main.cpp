#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int maxnum;
    cout <<"Anna korkein arvattava luku: ";
    cin >> maxnum;
    int game(maxnum);

    int lkm = game(maxnum);
    cout << "Pisteesi olivat " << lkm << endl;
    return 0;
}

int game(int maxnum){
    int randluku;
    int arvattuluku = -1;
    int lkm;

    srand(time(NULL));
    randluku = rand() % maxnum + 1;

    while (arvattuluku!=randluku){

        cout << "Arvaa luku 1-"<<maxnum<<": " << endl;
        cin >>arvattuluku;
        lkm++;

        if (arvattuluku > randluku){
            cout << "Lukusi oli liian suuri. ";
        } else if (arvattuluku < randluku){
            cout << "Lukusi oli liian pieni. " ;
        }
    }
    cout << "!Lukusi oli oikein!" << endl;
    return lkm;
}
