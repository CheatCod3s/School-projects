#include <iostream>
#include <string>

using namespace std;

double ympyran_pinta_ala(double sade){
    double pii = 3.14159265359;
    double pinta_ala = pii * sade * sade;
    return pinta_ala;
}

double suorakulmion_pinta_ala(double kanta, double korkeus){
    double pinta_ala = kanta * korkeus;
    return pinta_ala;
}

int main()
{
    cout << "Tervetuloa pinta-alalaskuriin!" << endl;
    string kuvio = "";
    cout << "Valitse kuvio, jolle haluat laskea pinta-alan: "
            "y (=ympyra) tai s (=suorakulmio)" << endl;
    getline(cin, kuvio);

    if (kuvio == "y") {
        double sade = 0;
        cout << "Ympyran sade:" << endl;
        cin >> sade;
        cout << "Ympyran pinta-ala on: "<< endl;
        cout << ympyran_pinta_ala(sade) << endl;
    } else {
        cout << "Suorakulmion kanta:" << endl;
        double kanta = 0;
        cin >> kanta;
        cout << "Suorakulmion korkeus:" << endl;
        double korkeus = 0;
        cin >> korkeus;
        cout << "Suorakulmion pinta-ala on:" << endl;
        cout << suorakulmion_pinta_ala(kanta, korkeus) << endl;

    }
}

