// Ennakkotehtävä 07
// Sandra Raitaniemi, 254081
// sandra.raitaniemi@student.tut.fi

#include <iostream>

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Opiskelija {
    string nimi;
    unsigned int opnum;
};


// ***** TODO *****************************************************************
// Toteuta tähän kohtaan vertailufunktio algorithm-kirjaston
// sort-funktiota varten.  Funktion on osattava vertailla kahta
// Opiskelija-tyyppistä struct:ia siten, että aakkosissa aiemmin
// oleva nimi-kenttä tulkitaan pienemmäksi struct:iksi.
// ****************************************************************************

bool aakkosvertailija(Opiskelija nimi1, Opiskelija nimi2){
    return (nimi1.nimi < nimi2.nimi);
}

// ***** TODO *****************************************************************
// Toteuta tähän kohtaan vertailufunktio algorithm-kirjaston
// sort-funktiota varten.  Funktion on osattava vertailla kahta
// Opiskelija-tyyppiseen struct:iin osoittavaa osoitinta siten,
// että pienemmäksi tulkitaan se niistä, joka osoittaa opiskelija-
// numeroltaan pienempään opiskelijaan.
// ****************************************************************************
bool numerovertailija(Opiskelija* nro1, Opiskelija* nro2){
    return (nro1->opnum < nro2->opnum);
}


int main() {
    vector<Opiskelija> oprek = {
        { "Teekkari, Tiina",           52401 },
        { "Ylikuuskajaskari, Jaska",  186112 },
        { "Repolainen, Reijo",        117118 },
        { "Teekkari, Teemu",          196196 },
        { "Santaholma, Santtu",       173421 },
    };

    vector<Opiskelija*> opiskelijaosoittimet = { };

    // Laitetaan opiskelijaosoittimet-vektoriin kaikkien oprek:iin
    // talletettujen opiskelijoiden muistiosoitteet.
    for ( vector<Opiskelija>::size_type i = 0; i < oprek.size(); ++i ) {
        opiskelijaosoittimet.push_back( &oprek.at(i) );
    }



    // ***** TODO *************************************************************
    // Käytä tässä kohdassa algorithm-kirjaston sort-funktiota siten,
    // että saat oprek-vektorissa olevat opiskelijat järjestetty
    // nimi-kentän mukaiseen kasvavaan aakkosjärjestykseen.
    // ************************************************************************
    sort(oprek.begin(), oprek.end(), aakkosvertailija);

    // ***** TODO *************************************************************
    // Käytä tässä kohdassa algorithm-kirjaston sort-funktiota siten,
    // että saat opiskelijaosoittimet-vektorissa olevat osoittimet
    // järjestettyä siten, että ne ovat osoittamiensa opiskelijoiden
    // mukaisessa kasvavassa opiskelijanumerojärjestyksessä.
    // ************************************************************************
    sort(opiskelijaosoittimet.begin(), opiskelijaosoittimet.end(), numerovertailija);


    //------------------------------------------------------------------//
    // Tässä kohdassa kumpikin vektori on järjestetty oman vertailu-    //
    // kriteerinsä perusteella kasvavaan järjestykseen. Tätä tilannetta //
    // havainnollistetaan tehtävänannon kuvassa, joka esittää           //
    // lajittelun jälkeistä lopputilannetta.                            //
    //------------------------------------------------------------------//



    // Tulostetaan opiskelijoiden tiedot näytölle kuumankin edellä
    // lajitellun vektorin avulla, jotta nähdään onko lajittelu onnistunut.

    cout << "Opiskelijat nimen mukaisessa järjestyksessa:" << endl
         << "--------------------------------------------" << endl;
    for ( Opiskelija opisk : oprek ) {
        cout << setw(24) << left << opisk.nimi
             << setw(6) << right << opisk.opnum << endl;
    }

    cout << endl;

    cout << "Opiskelijat numeron mukaisessa järjestyksessa:" << endl
         << "----------------------------------------------" << endl;
    for ( Opiskelija* opisk_ptr : opiskelijaosoittimet ) {
        cout << setw(24) << left << opisk_ptr->nimi
             << setw(6) << right << opisk_ptr->opnum << endl;
    }
}

