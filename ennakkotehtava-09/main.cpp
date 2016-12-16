// Ennakkotehtävä-09
// Sandra Raitaniemi, 254081
// sandra.raitaniemi@student.tut.fi

#include "Pino.hh"
#include <iostream>

using namespace std;


int main()
{
    Pino pino;

    pino.push_front(1);
    pino.push_front(2);
    pino.push_front(3);

    int poistettava = 0;


    if (pino.pop_front(poistettava) == true ) {
        cout << "Arvon poistaminen onnistui." << endl;
    } else {
        cout << "Arvon poistaminen epäonnistui." << endl;
    }

}

