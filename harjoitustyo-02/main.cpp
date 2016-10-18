// Ennakkotehtava-02
// sandra.raitaniemi@student.tut.fi
// Sandra Raitaniemi
// 254081

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

class Splitter {
    public:
    Splitter();
    void aseta_paloiteltava_merkkijono(string& merkkijono);
    void paloittele(char erotinmerkki);
    vector<string> hae_vektori() const;
    bool tarkista_kenttien_pituus();
    bool tarkista_valilyonnit();
    bool tarkista_tyhjat_kentat();
    bool tarkista_numero();

    private:
    string paloiteltava_;
    vector<string> kentat_;

};

Splitter::Splitter():
    paloiteltava_(""), kentat_({}){
}


void Splitter::aseta_paloiteltava_merkkijono(string& merkkijono){
    paloiteltava_ = merkkijono;
}
// Jakaa tekstirivin kenttiin ja tallentaa kentät vektoriin käyttäen erotinmerkkinä pistepilkkua.
void Splitter::paloittele(char erotinmerkki){
    kentat_.clear();
    string::size_type alkukohta = 0;
    string kentan_teksti;

    while (true) {
        string::size_type loppukohta;
        loppukohta = paloiteltava_.find(erotinmerkki, alkukohta);


        if (loppukohta == string::npos){
            break;
        }
        kentan_teksti = paloiteltava_.substr(alkukohta,loppukohta - alkukohta);
        kentat_.push_back(kentan_teksti);
        alkukohta = loppukohta + 1; // lasketaan pistepilkku mukaan merkkijonoon

    }

    kentan_teksti = paloiteltava_.substr(alkukohta);
    kentat_.push_back(kentan_teksti);

}
// Palauttaa kentät-vektorin.
vector <string> Splitter::hae_vektori() const {
    return kentat_;
}
// Tarkistaa, että tekstitiedoston rivillä on neljä kenttää.
bool Splitter::tarkista_kenttien_pituus(){

    if (kentat_.size() != 4){
        return false;
    } else {
        return true;
    }
}
// Tarkistaa, että tekstitiedoston kentät eivät sisällä välilyöntejä.
bool Splitter::tarkista_valilyonnit(){
    for (string kentta : hae_vektori()){
        string::size_type kohta;
        kohta = kentta.find(" ");
        if (kohta != string::npos ){
            return false;
        }
    }
    return true;
}
// Tarkistaa, että tekstitiedoston kentät eivät ole tyhjiä.
bool Splitter::tarkista_tyhjat_kentat(){
    for (string kentta : hae_vektori()){
        if (kentta == ""){
            return false;
       }
    }
    return true;
}
// Tarkistaa, että kentän viimeinen osa on double tai "loppu".
bool Splitter::tarkista_numero(){
    try{
        double arvo = stod(hae_vektori().at(3));
        return true;
    } catch (exception& e){
        string arvo = hae_vektori().at(3);
        if (arvo == "loppu"){
            return true;
        } else {
            return false;
        }

    }
}

//______________________________________________________________
//______________________________________________________________

// Muuttaa hinnan string-tyypistä double tyyppii. Jos hinta on "loppu"
// sen arvoksi laitetaan -1.0.
double muuta_hintatyyppi(vector<string> kauppatiedot){
    if (kauppatiedot.at(3) != "loppu"){
        double hinta = stod(kauppatiedot.at(3));
        return hinta;
    } else {
        double hinta = -1.00;
        return hinta;
    }

}
// Alustaa tuotteiden structin.
struct Tuotestruct{
    string tuotenimi;
    double hinta;
};
// Tarkistaa, että annettu käsky on oikean pituinen.
bool kaskyn_tarkistus(vector<string> kasky, string::size_type pituus){
    if (kasky.size() != pituus){
        return false;
    } else {
        return true;
    }
}


int main() {
    // Alustetaan tietorakenteet.
    Splitter paloiteltava_rivi;
    map <string, map<string, vector<Tuotestruct>>> kauppaketjut;
    map <string, vector<Tuotestruct>> kauppakohtaiset_tuotteet;
    vector<Tuotestruct> tuotevalikoima;
    vector<string> kaikki_tuotteet = {};

    // Luetaan tiedosto.
    ifstream tiedosto("tuotetiedot.txt");

    // Jos tiedostoa ei pysytä lukemaan, tulostuu virhe ja ohjelma lopetetaan.
    if (not tiedosto){
        cout << "Virhe: syötetiedostoa ei saatu luettua." << endl;
        return 0;
    } else {


        vector<string> kauppatiedot;
        char erotinmerkki = ';';
        string rivi;

        while(getline(tiedosto, rivi)){
            // Rivi paloitellaa osiin.
            paloiteltava_rivi.aseta_paloiteltava_merkkijono(rivi);
            paloiteltava_rivi.paloittele(erotinmerkki);
            kauppatiedot = paloiteltava_rivi.hae_vektori();

            // Tarkistetaan, että kenttiä on oikea määrä.
            if(paloiteltava_rivi.tarkista_kenttien_pituus() == false){
                cout << "Virhe: syötetiedosto on väärää muotoa." << endl;
                return 0;
            // Tarkistetaan, että kentät eivät sisällä välilyöntejä.
            } else if (paloiteltava_rivi.tarkista_valilyonnit() == false){
                cout << "Virhe: syötetiedosto on väärää muotoa." << endl;
                return 0;
            // Tarkistetaan, että kentät eivät ole tyhjiä.
            } else if (paloiteltava_rivi.tarkista_tyhjat_kentat() == false) {
                cout << "Virhe: syötetiedosto on väärää muotoa." << endl;
                return 0;
            // Tarkistetaan, että kentän viimeinen osa on double-muodossa tai
            // "loppu".
            } else if (paloiteltava_rivi.tarkista_numero() == false){
                cout << "Virhe: syötetiedosto on väärää muotoa." << endl;
            }


            string kauppa = kauppatiedot.at(0); // Esim. Prisma
            string toimipiste = kauppatiedot.at(1); // Esim. Kaleva
            string tuote = kauppatiedot.at(2); // Esim. mansikkajogurtti

            // Muutetaan hinta stringistä doubleksi.
            double hinta = muuta_hintatyyppi(kauppatiedot);
            // Asetetaan structiin tuotteen nimi ja hinta.
            Tuotestruct tavara{tuote, hinta};

            // Tarkistetaan, onko tuote jo kaikki_tuotteet-listassa, jos ei ole
            //lisätään se sinne.
            vector<string>::iterator iter;
            iter = find(kaikki_tuotteet.begin(), kaikki_tuotteet.end(), tuote);
            if (iter == kaikki_tuotteet.end()){
                kaikki_tuotteet.push_back(tuote);
            }

            // Tutkitaan, onko kauppaketju kauppaketjut-mapissa. Jos  ei ole
            // lisätään tuote vektorii, vektori toimipistekohtaiseen mappiin
            // ja toimipistekohtaine mappi kauppaketjut-mappiin.
            if (kauppaketjut.find(kauppa) == kauppaketjut.end()){
                map <string, vector<Tuotestruct>> kauppakohtaiset_tuotteet;
                vector<Tuotestruct> tuotevalikoima;
                tuotevalikoima.push_back(tavara);
                kauppakohtaiset_tuotteet.insert({toimipiste,tuotevalikoima});
                kauppaketjut.insert({kauppa,kauppakohtaiset_tuotteet});
             } else {
                // Tutkitaan, onko toimipiste jo tunnettu. Jos ei ole, lisätään toimipisteen
                // tuote vektoriin ja toimipiste mappiin.
                if(kauppaketjut[kauppa].find(toimipiste) == kauppakohtaiset_tuotteet.end()){
                    vector<Tuotestruct> tuotevalikoima;
                    tuotevalikoima.push_back(tavara);
                    kauppaketjut[kauppa].insert({toimipiste, tuotevalikoima});
                } else {
                    // Tutkitaan, onko tuote jo toimipisteen valikoimassa.
                    // Luodaan tuotevalikoiman sisältävälle vektorille osoitin ja
                    // iteraattori. Jos tuote löytyy tuotevalikoimasta ennestään,
                    // korvataa tuotevektorin alkio uuudella samalla tuotteella.
                    vector<Tuotestruct> *tuotevektoriosoitin;
                    tuotevektoriosoitin = &kauppaketjut[kauppa][toimipiste];
                    vector<Tuotestruct>::iterator iter;
                    bool tuote_loytyi = false;
                    for (iter = tuotevektoriosoitin->begin(); iter != tuotevektoriosoitin->end(); ++iter){
                        if (tuote == iter->tuotenimi){
                            kauppaketjut[kauppa][toimipiste].erase(iter);
                            kauppaketjut[kauppa][toimipiste].push_back(tavara);
                            tuote_loytyi = true;
                            }
                        }

                    // Jos tuotetta ei löytynyt, lisätään tuote tuotevalikoimaan.
                    if(tuote_loytyi == false) {
                        kauppaketjut[kauppa][toimipiste].push_back(tavara);
                    }
                    }

            }
       }
    }





        // Tuotehakua kysytään niin kauan kunnes käsky on "lopeta".
        string kasky = "";
        while (kasky != "lopeta"){

            cout << "tuotehaku> ";
            string rivi = "";
            getline(cin,rivi);

            // Paloitellaan käsky.
            Splitter paloiteltava_kasky;
            char erotinmerkki = ' ';
            paloiteltava_kasky.aseta_paloiteltava_merkkijono(rivi);
            paloiteltava_kasky.paloittele(erotinmerkki);
            vector<string> paloiteltu_kasky = paloiteltava_kasky.hae_vektori();
            kasky = paloiteltu_kasky.front();

            if (kasky == "kauppaketjut"){
                // Tarkistetaan, että käsky on oikean pituinen. Jos käsky sisältää useamman,
                // kuin yhden kentän, tulostetaan virheilmoitus.
                string::size_type kaskyn_pituus{1};
                if (kaskyn_tarkistus(paloiteltu_kasky, kaskyn_pituus) == true){
                    map <string, map<string, vector<Tuotestruct>>>::iterator iter;
                    // Tulostetaan kauppaketjut iteraattorin avulla aakkosjärjestyksessä.
                    for (iter = kauppaketjut.begin(); iter != kauppaketjut.end(); ++iter){
                        cout << iter->first << endl;
                    }
                } else {
                    cout << "Virhe: virheellinen käsky." << endl;
                }

           } else if(kasky == "myymalat"){
                // Tarkistetaan, että käsky on oikean pituinen. Jos käsky sisältää enemmän
                // kuin kaksi kenttää, tulostetaan virheilmoitus.
                string::size_type kaskyn_pituus{2};
                if (kaskyn_tarkistus(paloiteltu_kasky, kaskyn_pituus) == true){
                    string kauppaketju_nimi;
                    kauppaketju_nimi = paloiteltu_kasky.at(1);
                    map<string, vector<Tuotestruct>>::iterator iter;
                    // Tulostetaan myymälät iteraattorin avulla aakkosjärjestyksessä.
                    for (iter = kauppaketjut[kauppaketju_nimi].begin(); iter != kauppaketjut[kauppaketju_nimi].end(); ++iter){
                        cout << iter->first << endl;
                    }
                } else {
                    cout << "Virhe: virheellinen käsky." << endl;
                }

           } else if(kasky == "halvin"){
                // Tarkistetaan, että käsky on oikean pituinen. Jos käsky sisältää enemmän
                // kuin kaksi kenttää, tulostetaan virheilmoitus.
                string::size_type kaskyn_pituus{2};
                if (kaskyn_tarkistus(paloiteltu_kasky, kaskyn_pituus) == true){
                    string tuotteen_nimi;
                    tuotteen_nimi = paloiteltu_kasky.at(1);
                    // Alustetaan mappi, johon löytyneen tuotteen tiedot laitetaan.
                    map<string, double> tuote_loytyy;
                    // Käydään kaupat yksitellen läpi kauppaketjut-mapista.
                    for (auto kauppaketju : kauppaketjut){
                        string kauppa = kauppaketju.first;
                        // Käydään toimipisteet yksitellen läpi mapista.
                        for(auto sijainti : kauppaketjut[kauppa]){
                            string toimipiste = sijainti.first;
                            vector<Tuotestruct> *tuotevektoriosoitin;
                            tuotevektoriosoitin = &kauppaketjut[kauppa][toimipiste];
                            // Käydään tuotteet yksitellen läpi vektorista.
                            for(Tuotestruct tuotealkio : *tuotevektoriosoitin){
                                // Jos haluttu tuote löytyy, lisätään kauppaketju + toimipiste mapin ensimmäiseksi
                                // kentäksi ja tuotteen hinta mapin toiseksi kentäksi.
                                if(tuotealkio.tuotenimi == tuotteen_nimi){
                                    tuote_loytyy.insert({kauppa +" "+ toimipiste, tuotealkio.hinta });
                                }
                            }
                        }
                    // Jos tuotetta ei löytynyt mappi on tyhjä.
                    } if (tuote_loytyy.size() == 0){
                        cout << "Tuote ei kuulu valikoimiin." << endl;
                      } else {

                            double hinta;
                            // Alustetaan vektori johon lisätään toimipisteet, joissa on tuotteelle halvin hinta.
                            vector<string> kaupat_joissa_halvin_hinta;
                            int lapikayntikerrat = 0;

                            for (auto tuote : tuote_loytyy ){
                                // Kun mapista otetaan ensimmäinen tuote, asetetaan sen hinta vertailuhinnaksi, ellei
                                // tuote ole loppu eli hinta ei ole -1.0.
                                if (lapikayntikerrat == 0 && tuote.second > 0){
                                    kaupat_joissa_halvin_hinta.push_back(tuote.first);
                                    hinta = tuote.second;
                                    ++lapikayntikerrat;
                                } else {
                                    double uusi_hinta = tuote.second;
                                    ++lapikayntikerrat;
                                    // Seuraavasta läpikäyntikerrasta eteenpäin, tuotetta verrataan aina sen hetkiseen alimpaan hintaa.
                                    // Jos uusi hinta ont halvempi kuin vanha hinta. Tyhjennetään vektori ja tilalle lisätään kauppa jossa on halvin hinta.
                                    if (uusi_hinta < hinta && uusi_hinta > 0){
                                        hinta = uusi_hinta;
                                        kaupat_joissa_halvin_hinta.clear();
                                        kaupat_joissa_halvin_hinta.push_back(tuote.first);
                                    // Jos halvin hinta on sama toisessakin kaupassa, lisätään kauppa vektoriin.
                                    } else if(uusi_hinta == hinta){
                                        kaupat_joissa_halvin_hinta.push_back(tuote.first);
                                    }
                                }
                            }
                            // Jos halvin hinta on kaikissa kaupoissa ollut -1.0 on vektori tyhjä.
                            if (kaupat_joissa_halvin_hinta.size() == 0){
                                cout << "Tuote on tilapäisesti loppu kaikkialta." << endl;
                            } else {
                                cout <<setprecision(2)<< fixed << hinta << endl;
                                vector<string>::iterator iter;
                                for (iter = kaupat_joissa_halvin_hinta.begin(); iter != kaupat_joissa_halvin_hinta.end(); ++ iter){
                                    cout << *iter << endl;
                                }
                            }
                        }

                } else {
                    cout << "Virhe: virheellinen kasky" << endl;
                }


            } else if(kasky == "tuotevalikoima"){
                // Tarkistetaan, että käskyn pituus on oikein.
                string::size_type kaskyn_pituus{3};
                if (kaskyn_tarkistus(paloiteltu_kasky, kaskyn_pituus) == true){
                    string kauppaketjun_nimi;
                    kauppaketjun_nimi = paloiteltu_kasky.at(1);
                    string kaupan_sijainti;
                    kaupan_sijainti = paloiteltu_kasky.at(2);

                    // Käydään tuotteet läpi vektorista, ja asetetaan ne mappiin tulostuksen helpottamiseksi.
                    vector<Tuotestruct> *tuotevektoriosoitin;
                    tuotevektoriosoitin = &kauppaketjut[kauppaketjun_nimi][kaupan_sijainti];
                    map<string, double> tuotteet;
                    for (auto tuote : *tuotevektoriosoitin){
                        tuotteet.insert({tuote.tuotenimi, tuote.hinta});
                    }
                    // Tulostetaan tuotteiden nimet ja hinnat.
                    map<string, double>::iterator iter;
                    for(iter = tuotteet.begin(); iter != tuotteet.end(); ++iter){
                        cout << iter->first << " ";
                        // Jos hinta on -1.0 tuote on loppu.
                        if (iter->second == -1.0){
                            cout << "loppu" << endl;
                        } else {
                            cout << setprecision(2)<< fixed << iter->second << endl;
                        }
                    }
                } else {
                    cout << "Virhe: virheellinen käsky." << endl;
                }


            } else if(kasky == "tuotenimet"){
                // Tarkistetaan että käskyn pituus on oikein.
                string::size_type kaskyn_pituus{1};
                if (kaskyn_tarkistus(paloiteltu_kasky, kaskyn_pituus) == true){
                    // Tulostetaan kaikki_tuotteet-vektorista tuotteet aakkosjärjestyksessä.
                    sort(kaikki_tuotteet.begin(), kaikki_tuotteet.end());
                    for(string tuote : kaikki_tuotteet){
                        cout << tuote << endl;
                    }
                } else {
                    cout << "Virhe: virheellinen käsky." << endl;
                }

            } else if(kasky != "lopeta") {

                cout << "Virhe: virheellinen käsky." << endl;
            }
        }
    }


