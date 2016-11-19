// Harjoitustyö-04
// Sandra Raitaniemi, 254081
// sandra.raitaniemi@student.tut.fi

#include "paaikkuna.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paaikkuna w;
    w.show();
    // Alustetaan pääikkuna.
    w.alusta();

    return a.exec();
}
