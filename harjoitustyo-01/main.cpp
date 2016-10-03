// Pankkisimulaatio
// Sandra Raitaniemi, 245081
// sandra.raitaniemi@student.tut.fi

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;
// Alustetaan pankkitililuokka.
class Pankkitili {
    public:
        Pankkitili(string tilinumero, double saldo, string asiakasnro);
        void tulosta() const;
        void aseta(string tilinumero, double saldo, string asiakasnumero);
        void pano(double summa);
        void otto(double summa);
        double hae_saldo();

    private:
        string tilinumero_;
        double saldo_;
        string asiakasnro_;
};

Pankkitili::Pankkitili(string tilinumero, double saldo, string(asiakasnro)):
   tilinumero_{tilinumero}, saldo_{saldo}, asiakasnro_{asiakasnro}{
}

// Asettaa pankkitilille käyttäjän syöttämät tietot.
void Pankkitili::aseta(string tilinumero, double saldo, string asiakasnumero){
    tilinumero_ = tilinumero;
    saldo_ = saldo;
    asiakasnro_ = asiakasnumero;
}

// Lisää tilille rahaa.
void Pankkitili::pano(double summa) {
    saldo_= saldo_ + summa;
}

// Nostaa tililtä rahaa.
void Pankkitili::otto(double summa) {
    saldo_= saldo_ - summa;
}

// Tulostaa tilinumeron, saldon (kahden desimaalin tarkkuuteen
// pyöristettynä) ja asiakasnumeron.
void Pankkitili::tulosta() const{
    cout << "Tilinumero: " << tilinumero_ << endl;
    cout << "Saldo: " <<  setprecision(2)<< fixed << saldo_ << endl;
    cout << "Asiakasnumero: " << asiakasnro_ << endl;
}
// Lukee pankkitilin saldon.
double Pankkitili::hae_saldo() {
    return saldo_;
}

// Tarkistaa, että käyttäjän syöttämä summa on positiivinen.
// Palauttaa falsen, jos luku on negatiivinen.
bool summan_tarkistus(double summa) {
    if (summa < 0 ) {
        return false;
    } else {
        return true;
    }
}

// Tarkistaa, että tili, jolle käyttäjä haluuaa suorittaa toiminnon
// on jokin olemassa olevista tileistä (1, 2 tai 3).
// Palauttaa falsen, jos tili ei 1, 2 tai 3.
bool pankkinumeron_tarkistus(int numero){
    if ((numero < 0) || (2 < numero)) {
        return false;
    } else {
    return true;
    }
}

int main() {
    // Pankkitilit tallennetaan tilit-vektoriin.
    vector<Pankkitili> tilit;
    for (int luku{0}; luku < 3; ++luku){
        string tilinumero = "FI0000000000000000";
        double saldo = 0;
        string asiakasnumero = "0000000";
        Pankkitili tili(tilinumero, saldo, asiakasnumero);
        tilit.push_back(tili);
    }
    string kasky;
    while (true) {
        // Käyttäjältä kysytään syöte ja tutkitaan syötteen pituus.
        int tilin_nro = 0; // Tili 1, 2, tai 3
        int kohdetili = 0;  // Tili 1, 2, tai 3
        kasky = "";
        string rivi = "";
        cout << "pankkitilitesti> ";
        getline(cin, rivi);
        string::size_type pituus = 0;
        pituus = rivi.length();
        unsigned int tilisiirtokaskyn_pituus = 14;

        // Tutkitaan, onko käsky "loppu" ennen kuin käskyn numeroita
        // aletaan tutkia.
        if (rivi == "loppu" ){
            break;
        }

        // Jos merkkijonon pituus on yhtä suuri kuin tilisiirtokäskyn
        // merkkijonon pituus, otetaan tilisiirtoon käytettävien tilien
        // numerot talteen niiden indeksien perusteella ja muutetaan
        // niiden tyypit char-tyypistä int-tyyppiin.
        // Numeroista vähennetään ykköset, jotta niillä voidaan sujuvasti
        // hakea vektorista niitä vastaavat tilit.
        if ( pituus == tilisiirtokaskyn_pituus){
            kasky = "tilisiirto";
            tilin_nro = (rivi.at(11)-'0')-1; // Tili 1, 2, tai 3
            kohdetili = (rivi.at(13)-'0')-1; // Tili 1, 2 tai 3

            // Jos syötetyt numerot eivät ole 1, 2 tai 3, annetaan virheilmoitus.
                if ((pankkinumeron_tarkistus(tilin_nro) == false) ||
                        (pankkinumeron_tarkistus(kohdetili)== false)){
                    cout << "Virhe: tiliä ei ole olemassa." << endl;
                } else { if (kasky == "tilisiirto"){
                        cout << "Syötä siirtomäärä: ";
                        double summa = 0;
                        cin >> summa;
                        cin.ignore();   // tyhjennetään cin
                        if (summan_tarkistus(summa) == false){
                            cout << "Virhe: summan on oltava positiivinen." << endl;
                        } else {
                         // Tarkistetaan onko tilillä tarpeeksi katetta siirron
                         // suorittamiseen.
                                if(tilit[tilin_nro].hae_saldo() < summa ){
                                    cout << "Virhe: tilisiirtoa ei voida suorittaa." << endl;
                                } else {
                                    tilit[tilin_nro].otto(summa);
                                    tilit[kohdetili].pano(summa);
                                }
                          }
                     }
               }
            // Jos käsky ei ole "tilisiirto", tutkitaan onko se joku
            // jäljelle jääneistä käskyistä.
            // Ensin käskystä erotellaan tilin numero ja itse käsky.
            // Numeroksi otetaan merkkijonon viimeine merkki ja
            // käskyksi merkkijonon ensimmäisestä merkistä merkit
            // toiseksi viimeiseen merkkiin asti.
       } else {
            tilin_nro = (rivi.at(pituus - 1)-'0')-1;
            kasky = rivi.substr(0, pituus - 2);
            // Tarkistetaan onko tilin numero 1,2 tai 3.
            if (pankkinumeron_tarkistus(tilin_nro) == false){
                cout << "Virhe: tiliä ei ole olemassa." << endl;
            } else {
                if (kasky == "tulosta"){
                    // Haetaan vektorista tilin numerolla oikea tililuokka.
                    tilit[tilin_nro].tulosta();
                }
                // Kysytään käyttäjältä tilin tiedot, tarkistetaan onko
                // saldo positiivinen ja asetetaan tilin tiedot.
                else if (kasky == "aseta"){
                    string tilinumero;
                    cout << "Syötä tilinumero: ";
                    cin >> tilinumero;
                    cin.ignore();
                    double saldo;
                    cout << "Syötä saldo: ";
                    cin >> saldo;
                    cin.ignore();
                    if (summan_tarkistus(saldo) == false){
                        cout << "Virhe: summan on oltava positiivinen." << endl;
                    } else {
                        string asiakasnumero;
                        cout << "Syötä asiakasnumero: ";
                        cin >> asiakasnumero;
                        cin.ignore();
                        tilit[tilin_nro].aseta(tilinumero, saldo, asiakasnumero);
                        cout << "Tilin " << tilin_nro + 1 << " tiedot asetettu." << endl;
                     }
                }
                // Lisätään tilille rahaa.
                else if (kasky == "pano"){
                    double summa;
                    cout << "Syötä rahamäärä: ";
                    cin >> summa;
                    cin.ignore();
                    // Tarkistetaan, että käyttäjän syöttämä summa on positiivinen.
                    if (summan_tarkistus(summa) == false){
                        cout << "Virhe: summan on oltava positiivinen." << endl;
                    }
                    else {
                        tilit[tilin_nro].pano(summa);
                        cout << "Pano suoritettu tilille " << tilin_nro + 1 << "." << endl;
                    }
                }
                // Nostetaan tililtä rahaa.
                else if (kasky == "otto"){
                    double summa;
                    cout << "Syötä rahamäärä: ";
                    cin >> summa;
                    cin.ignore();
                    if (summan_tarkistus(summa) == false){
                        cout << "Virhe: summan on oltava positiivinen." << endl;
                    }
                    // Tarkistetaan, että tillä on tarpeeksi katetta nostoon.
                    else if( tilit[tilin_nro].hae_saldo() < summa){
                        cout << "Virhe: tilisiirtoa ei voida suorittaa." << endl;
                    }
                    else {
                        tilit[tilin_nro].otto(summa);
                        cout << "Otto suoritettu tililtä " << tilin_nro + 1 << "." << endl;
                    }
                    // Jos käyttäjän syöttämää käskyä ei ole,
                    // tulostetaan virheilmoitus.
                } else { cout << "Virhe: väärä käsky."<< endl; }

            }

        }

    }
}













