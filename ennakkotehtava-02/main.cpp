// Ennakkotehtava-02
// Sandra Raitaniemi, 245081
// sandra.raitaniemi@student.tut.fi

#include <iostream>
#include <iomanip>

using namespace std;

class Kellonaika {
  public:
    Kellonaika();
    Kellonaika(int tunti, int minuutti);
    void tiktok();
    int hae_tunti() const;
    int hae_minuutti() const;
    void tulosta() const;
    int laske_aikaero(Kellonaika& aika2);


  private:
    // Kello 00.00:sta kuluneet minuutit
    int kuluneet_minuutit_;
};


Kellonaika kysy_kellonaika(int syottokerta){
    cout << "Syötä " << syottokerta << ". kellonaika: ";

    int tunti;
    int min;

    cin >> tunti;
    cin.get();
    cin >> min;

    return Kellonaika(tunti, min);
}


int main() {
    Kellonaika aika1;
    Kellonaika aika2;

    aika1 = kysy_kellonaika(1);
    aika2 = kysy_kellonaika(2);

    cout << "Aikaero on: " << aika1.laske_aikaero(aika2) << " minuuttia" << endl;

}



Kellonaika::Kellonaika(int tunti, int minuutti):
    kuluneet_minuutit_(60 * tunti + minuutti) {
}

Kellonaika::Kellonaika():
    kuluneet_minuutit_(0) {

}

void Kellonaika::tiktok() {
    ++kuluneet_minuutit_;
    if ( kuluneet_minuutit_ >= 24 * 60 ) {
        kuluneet_minuutit_ = 0;
    }
}

int Kellonaika::hae_tunti() const {
    // Kun kokonaisluku jaetaan kokonaisluvulla
    // tuloksena on kokonaisluku (jakojäännös
    // heitetään menemään).
    return kuluneet_minuutit_ / 60;
}

int Kellonaika::hae_minuutti() const {
    return kuluneet_minuutit_ % 60;
}

void Kellonaika::tulosta() const {
    cout << setfill('0') << setw(2) << hae_tunti()
         << "."
         << setw(2) << hae_minuutti()
         << endl;
}

int Kellonaika::laske_aikaero(Kellonaika& aika2) {

    if (kuluneet_minuutit_ <= aika2.kuluneet_minuutit_){
        return aika2.kuluneet_minuutit_ - kuluneet_minuutit_;
    } else {
        return 24*60 - kuluneet_minuutit_ + aika2.kuluneet_minuutit_;
    }
}
