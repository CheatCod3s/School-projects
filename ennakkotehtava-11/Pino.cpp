#include "Pino.hh"
#include <iostream>

using namespace std;

const int alkukoko = 8;

Pino::Pino():
    taulukko_(new int[alkukoko]),
    taulukon_koko_(alkukoko),
    kaytetty_tila_(0){

}

Pino::~Pino() {
    delete [] taulukko_;
}

bool Pino::empty() const {
   return (taulukon_koko_ == 0);
}

void Pino::print() const {

    for (int i = 0 ; i < kaytetty_tila_; ++i){
        cout << taulukko_[i] << endl;
    }
}

void Pino::push_front(int lisattava_arvo) {
    if(kaytetty_tila_-1 == taulukon_koko_){
        int *uusi_taulukko = new int[2 * taulukon_koko_];
        for (int i = 0 ; i < kaytetty_tila_ ; ++i){
            uusi_taulukko[i] = taulukko_[i];
        }
        delete [] taulukko_;
        taulukko_ = uusi_taulukko;
        taulukon_koko_ = 2 * taulukon_koko_;
    }


    taulukko_[kaytetty_tila_] = lisattava_arvo;
    ++kaytetty_tila_;

}

bool Pino::pop_front(int& poistettu_arvo) {
    if (empty()){
        return false;
    }

    poistettu_arvo = taulukko_[kaytetty_tila_];
    --kaytetty_tila_ ;

    return true;
}
