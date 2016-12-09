#include "Splitter.hh"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Splitter::Splitter():
    paloiteltava_(""), onko_paloittelu_suoritettu_(false), kentat_( {} ) {
}


void Splitter::aseta_paloiteltava_merkkijono(const string& mjono) {
    paloiteltava_ = mjono;
    onko_paloittelu_suoritettu_ = false;
}


void Splitter::paloittele(char erotinmerkki) {
    kentat_.clear();
    string::size_type alkukohta = 0;
    string kentan_teksti;
    bool ohita_tyhjat = true;

    while ( true ) {
        string::size_type loppukohta;

        loppukohta = paloiteltava_.find(erotinmerkki, alkukohta);
        if ( loppukohta == string::npos ) {
            break;
        }
        kentan_teksti = paloiteltava_.substr(alkukohta, loppukohta - alkukohta);

        if ( not (ohita_tyhjat and kentan_teksti.empty()) ) {
            kentat_.push_back(kentan_teksti);
        }
        alkukohta = loppukohta + 1;
    }


    kentan_teksti = paloiteltava_.substr(alkukohta);

    if ( not (ohita_tyhjat and kentan_teksti.empty()) ) {
        kentat_.push_back(kentan_teksti);
    }

    // Kirjataan ylös, että paloittelu on suoritettu.
    onko_paloittelu_suoritettu_ = true;

}


string Splitter::hae_kentta(int kentan_numero) const {

    if ( not onko_paloittelu_suoritettu_ ) {
        kentan_numero = kentat_.size();
    }

    return kentat_.at(kentan_numero);
}
