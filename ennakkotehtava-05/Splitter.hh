#ifndef SPLITTER_HH
#define SPLITTER_HH

#include <string>
#include <vector>

using namespace std;

class Splitter {
public:
    Splitter();
    void aseta_paloiteltava_merkkijono(const string& mjono);
    void paloittele(char erotinmerkki);
    string hae_kentta(int kentan_numero) const;

  private:
    string paloiteltava_;
    bool onko_paloittelu_suoritettu_;
    vector<string> kentat_;

};

#endif // SPLITTER_HH
