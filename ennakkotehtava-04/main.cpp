// Ennakkotehtävä 04
// Sandra Raitaniemi, 254081
// sandra.raitaniemi@student.tut.fi
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void tallenna_tietorakenteeseen(map <string, vector<string>>& sijoitukset,
                                string laji, string kilpailija){

    map <string, vector<string>>::iterator sijoitusiter;
    sijoitusiter = sijoitukset.find(laji);

    if(sijoitusiter == sijoitukset.end()){
        sijoitukset.insert({laji, {kilpailija}});


    } else {

         sijoitusiter->second.push_back(kilpailija);

    }
}

void tulosta(map <string, vector<string>> sijoitukset){

    map<string, vector<string>>::const_iterator laji_iter;
    laji_iter = sijoitukset.begin();

    while ( laji_iter != sijoitukset.end() ) {
        cout << laji_iter->first << endl;

        vector<string>::const_iterator kilpailija_iter;
        kilpailija_iter = laji_iter->second.begin();

        int sijoitus = 1;
        while ( kilpailija_iter != laji_iter->second.end() ) {
            cout << "  " << sijoitus << ". " << *kilpailija_iter << endl;

            ++sijoitus;
            ++kilpailija_iter;
        }

        ++laji_iter;
    }



}

int main(){
   map<string, vector<string>> sijoitukset;

   while(true) {
       cout << "Syötä laji: ";
       string laji;
       getline(cin, laji);

       if(laji.empty()){
           break;
       }

       cout << "Syötä kilpailijan nimi: ";
       string kilpailija;
       getline(cin, kilpailija);

       if (kilpailija.empty()){
           break;
       }

       tallenna_tietorakenteeseen(sijoitukset, laji, kilpailija);

    }

    tulosta(sijoitukset);
}

