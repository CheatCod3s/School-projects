#ifndef PINO_HH
#define PINO_HH

#include <string>

using namespace std;

class Pino {
  public:
    Pino();
    ~Pino();

    // empty palauttaa true vain, jos rakenteeseen (private-osan
    // linkitetty lista) ei sisällä yhtään alkiota.
    bool empty() const;

    // push_front lisää parametrina saamansa kokonaisluvun
    // private-osan linkitetyn listan alkuun.
    void push_front(int lisattava_arvo);


    // pop_front poistaa listan alusta yhden luvun ja tallentaa
    // sen viiteprametriinsa.  Jos lista on tyhjä, parametrin arvo
    // ei muutu, ja funktio palauttaa false.  Jos listasta saatiin
    // poistettua arvo, paluuarvo on true.
    bool pop_front(int& poistettu_arvo);

  private:
    struct Listan_alkio {
        int luku;
        Listan_alkio *seuraavan_osoite;
    };

    Listan_alkio *ensimmaisen_osoite_;
    Listan_alkio *viimeisen_osoite_;
};

#endif // PINO_HH
