// Ennakkotehtava 11
// Sandra Raitaniemi, 254081
// sandra.raitaniemi@student.tut.fi

#include "Pino.hh"
#include <iostream>

using namespace std;

int main()
{
    Pino taulukko;

    for(int i = 1 ; i < 11 ; ++i){
        taulukko.push_front(i);
    }

    taulukko.print();

    cout << "---" << endl;

    int poistettu_arvo = 0;

    taulukko.pop_front(poistettu_arvo);

    taulukko.print();
}

