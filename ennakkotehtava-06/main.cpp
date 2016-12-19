#include <iostream>
#include <map>
#include <string>


using namespace std;

using Puhelinluettelo = map<string, string>;

int laske_nimet(Puhelinluettelo::const_iterator tutkittava,
                Puhelinluettelo::const_iterator loppu,
                char nimen_alkukirjain);

int main()
{


    Puhelinluettelo luettelo = {
            { "Kalle",  "111 1111" },
            { "Jarkko", "222 2222" },
            { "Kirsi",  "333 3333" },
            { "Jaana",  "444 4444" },
            { "Matti",  "555 5555" },
            { "Minna",  "666 6666" },
            { "Anja",   "777 7777" },
            { "Eero",   "888 8888" },
            { "Keijo",  "999 9999" },
        };

    cout << "X: " << laske_nimet(luettelo.begin(), luettelo.end(), 'X') << endl;
        cout << "K: " << laske_nimet(luettelo.begin(), luettelo.end(), 'K') << endl;
        cout << "J: " << laske_nimet(luettelo.begin(), luettelo.end(), 'J') << endl;
        cout << "M: " << laske_nimet(luettelo.begin(), luettelo.end(), 'M') << endl;
        cout << "A: " << laske_nimet(luettelo.begin(), luettelo.end(), 'A') << endl;
        cout << "E: " << laske_nimet(luettelo.begin(), luettelo.end(), 'E') << endl;





}

int laske_nimet(Puhelinluettelo::const_iterator tutkittava,
                Puhelinluettelo::const_iterator loppu,
                char nimen_alkukirjain){

    if (tutkittava == loppu){
        return 0;

    } else if (tutkittava->first.front() > nimen_alkukirjain) {
        return 0;

    } else if (tutkittava->first.front() == nimen_alkukirjain){
        ++tutkittava;
        return 1 + laske_nimet(tutkittava, loppu, nimen_alkukirjain);

    } else {
        ++tutkittava;
        return laske_nimet(tutkittava, loppu, nimen_alkukirjain);
    }
}

