#include "game.h"
#include <cstdlib>
#include <time.h>
using namespace std;

game::game() {
    cout <<"Constructor"<<endl;
    srand(time(NULL));
    cout <<"Anna korkein arvattava luku: "<< endl;
    cin >> maxNumber;

}

game::~game(){
    cout <<"destructor"<<endl;
}

void game::play(){
    cout <<"void play"<<endl;

    while (playerGuess == 0){
        randomNumber = rand() % maxNumber +1;

        while (playerGuess!=randomNumber){

            cout << "Arvaa luku 1-"<<maxNumber<<": " << endl;
            cin >>playerGuess;
            numOfGuesses++;

            if (playerGuess > randomNumber){
                cout << "Lukusi oli liian suuri. ";
            } else if (playerGuess < randomNumber){
                cout << "Lukusi oli liian pieni. " ;
            }
        }
        cout<<"Lukusi oli oikein!"<< endl;
        printGameResult(numOfGuesses);
        cout<<"\nJatketaanko? 0 = Kylla"<< endl;
        cin>>playerGuess;
    }
}

void game::printGameResult(int){
    cout<<"Oikea luku oli "<<randomNumber<< endl;
    cout<<"Arvasit "<<numOfGuesses<<" kertaa"<< endl;
    numOfGuesses = 0;
}
