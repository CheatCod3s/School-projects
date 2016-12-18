#ifndef PINO_HH
#define PINO_HH

using namespace std;

class Pino {
      public:
        Pino();
        ~Pino();

        void print() const;

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
        int* taulukko_;
        int kaytetty_tila_;
        int taulukon_koko_;

    };


#endif // PINO_HH
