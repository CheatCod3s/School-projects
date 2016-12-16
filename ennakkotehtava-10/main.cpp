#include "Lista.hh"
#include <iostream>

using namespace std;

int main()
{
    Lista lista;

    lista.lisaa_alkio_loppuun("tiskaa");
    lista.lisaa_alkio_loppuun("kokkaa");
    lista.lisaa_alkio_loppuun("nuku");
    lista.lisaa_alkio_loppuun("maalaa");
    lista.lisaa_alkio_loppuun("opiskele");

    lista.tulosta();

    cout << "---" << endl;

    string poistettava_alkio = "nuku";
    lista.poista_alkio(poistettava_alkio);

    lista.tulosta();

    cout << "---" << endl;

    poistettava_alkio = "tiskaa";
    lista.poista_alkio(poistettava_alkio);

    lista.tulosta();

    cout << "---" << endl;

    poistettava_alkio = "opiskele";
    lista.poista_alkio(poistettava_alkio);

    lista.tulosta();


}

