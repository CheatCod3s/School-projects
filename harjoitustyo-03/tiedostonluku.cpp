//------------------------------------------------
//  TIE-02200 Ohjelmoinnin peruskurssi -mallikoodi
//  Copyright © 2016  opersk@cs.tut.fi
//------------------------------------------------
#include "todo_rakenne.hh"
#include <fstream>
#include <string>
#include <vector>


using namespace std;


// ----------------------------------------------------------------------------
// lue_tehtavatiedosto
// -------------------
// Funktio lukee parametrina saamansa tietovirran avulla tehtävälistatiedoston
// ja lisää sieltä saamansa tiedot tehtavarakenteeseen.  Jos tiedostossa
// on virheellisiä rivejä, funktion on palautettava false.  Jos tiedosto on
// virheetön, paluuarvon oltava true.  Tiedoston lukemin tämän funktion
// avulla EI SAA TULOSTAA NÄYTÖLLE MITÄÄN, sillä virheilmoitusten tulostuksesta
// on huolehdittu pääohjelmassa.
//
// KOKO TIEDOSTON LUKEMINEN ON TOTEUTETTAVA REKURSION AVULLA.  Tämä funktio,
// eikä sen avuksi itse toteutetut apufunktiot saa sisältää yhtään silmukka-
// rakennetta.  Silmukkarakenteet ovat tässä yhteydessä työn hylkäämisperuste.
//
// Funktion paluuarvo ja parametrien tyypit ja määrä on säilytettävä.
// ET SIIS SAA MUUTTAA LUE_TEHTAVATIEDOSTO-FUNKTION RAJAPINTAA.
// ----------------------------------------------------------------------------


// Funktio syötetiedoston rivin osiinpilkkomiseen.
vector<string> paloittele_rivi(string rivi) {

    // Tiedostossa puolipiste on aina indeksillä 1.
    int puolipisteen_paikka = 1;

    // Erotellaan kiireellisyys ja tehtävä rivistä
    string kiireellisyys = rivi.substr(0,puolipisteen_paikka);
    string tehtava = rivi.substr(puolipisteen_paikka + 1);

    vector<string> paloiteltu_rivi;

    // Ja tallennetaan ne vektoriin.
    paloiteltu_rivi.push_back(kiireellisyys);
    paloiteltu_rivi.push_back(tehtava);

    return paloiteltu_rivi;
}

// Funktio katsoo onko tehtävänkuvauskenttä tyhjä tai
// sisältääkö se pelkästään välilyöntejä.
// Jos kenttä on virheellinen funktio palauttaa falsen.
bool tarkista_tehtavankuvaus(string kuvaus){

    if (kuvaus == ""){
        return false;
    }

    // Jos välilyöntien määrä kentässä on sama kuin merkkien määrä
    // kentässä, funktio palauttaa falsen.
    int valilyonnin_paikka = kuvaus.find(" ");
    string valilyonnit = kuvaus.substr(valilyonnin_paikka);
    if (valilyonnit.length() == kuvaus.length()){
        return false;
    }

    return true;
}

bool lue_tehtavatiedosto(ifstream& virta, Todo& tehtavarakenne) {
    if (virta.eof()){
        return true;

   } else {
       string rivi;
       getline(virta, rivi);

       // Qt Creator lisäsi tekstitiedoston loppuun tyhjän rivin,
       // joka tuotti virhetilanteen. Koska virhe ei ole itse
       // tekstitiedostossa, asiasta ei nosteta virheilmoitusta.
       if (rivi == ""){
           return lue_tehtavatiedosto(virta, tehtavarakenne);
       }

       // Tarkistetaan, että puolipiste on syöterivillä,
       // paikkaindeksillä 1. Jos ei ole, rivi on virheellinen
       // ja nostetaan virheilmoitus.
       string::size_type puolipisteen_paikka = 1;
       if (rivi.find(";") != puolipisteen_paikka ) {
           return false;
       }

       // Paloitellaan rivi osiin funktiossa.
       vector<string> paloiteltu_rivi = paloittele_rivi(rivi);

       // Muutetaan kiireellisyyttä ilmaiseva string char-muotoon
       // ja tarkistetaan, että se on numero.
       if (not isdigit(paloiteltu_rivi.at(0).at(0))){
           return false;
       }

       int kiireellisyys = stoi(paloiteltu_rivi.at(0)); // 1-5
       string kuvaus = paloiteltu_rivi.at(1); // tehtävän kuvaus

       // Tarkastetaan, että tehtävänkuvaukset ovat oikeassa muodossa.
       if (not tarkista_tehtavankuvaus(kuvaus)){
           return false;
       }

       // Jos tiedostoon tallentamisessa ilmenee ongelmia, kuten
       // kiireellisyys ei ole väliltä 1-5, nostetaan virheilmoitus.
       if(not tehtavarakenne.lisaa_tehtava (kiireellisyys, kuvaus) ){
            return false;
        }
       // Koska funktio on rekursiivinen, funktio kutsuu itseään.
       return lue_tehtavatiedosto(virta, tehtavarakenne);

   }
}




