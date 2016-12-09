// Ennakkotehtävä-05
// Sandra Raitaniemi, 254081
// sandra.raitaniemi@student.tut.fi

#include <iostream>
#include <string>
#include <vector>

#include "Splitter.hh"
#include "Operaatiot.hh"

using namespace std;

void tyyppimuunnin(string& arvo, double& tulos){

    tulos = stod(arvo);

}

int main(){

    Splitter palat;
    string syote;
    char erotinmerkki = ' ';
    while (true){
        cout << "laskin> ";
        getline(cin, syote);


        if (syote.empty()){
            break;
        }

        palat.aseta_paloiteltava_merkkijono(syote);
        palat.paloittele(erotinmerkki);

        string arvo1 = palat.hae_kentta(0);
        string arvo2 = palat.hae_kentta(2);
        string operaattori = palat.hae_kentta(1);

        double a;
        double b;
        tyyppimuunnin(arvo1, a);
        tyyppimuunnin(arvo2, b);

        double tulos;

        if (operaattori == "+"){
            tulos = summa(a,b);
        }
        else if (operaattori == "-"){
           tulos = erotus(a,b);
        }
        else if (operaattori == "*"){
           tulos = tulo(a,b);

        }
        else if (operaattori == "/"){
            tulos = jako(a,b);
        }




        cout << tulos << endl;
    }


    cout << "Kiitos ja näkemiin!" << endl;
}
