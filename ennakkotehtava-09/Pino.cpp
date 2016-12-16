#include "Pino.hh"
#include <string>

Pino::Pino(): ensimmaisen_osoite_{nullptr}, viimeisen_osoite_{nullptr} {

}

Pino::~Pino() {

    Listan_alkio *vapautettavan_osoite;
    while( ensimmaisen_osoite_ != nullptr ) {
        vapautettavan_osoite = ensimmaisen_osoite_;
        ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;

        delete vapautettavan_osoite;
    }

}

bool Pino::empty() const {

    if (ensimmaisen_osoite_ == nullptr) {
        return true;
    } else {
        return false;
    }
}

void Pino::push_front(int lisattava_arvo){

    Listan_alkio *uuden_osoite = new Listan_alkio{lisattava_arvo, nullptr};


    uuden_osoite->seuraavan_osoite = ensimmaisen_osoite_;
    ensimmaisen_osoite_ = uuden_osoite;

}

bool Pino::pop_front(int &poistettu_arvo) {

    if( empty() ) {
        return false;
    }

    Listan_alkio *poistettavan_osoite{ensimmaisen_osoite_};

    poistettu_arvo = poistettavan_osoite->luku;

    ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;


    delete poistettavan_osoite;

    return true;
}
