#include "paaikkuna.hh"
#include "ui_paaikkuna.h"

Paaikkuna::Paaikkuna(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Paaikkuna)
{
    ui->setupUi(this);

    // Jos pituutta tai painoa muutetaan liukuvalla valikolla tai skrollivalikolla,
    // BMI lasketaan.
    connect(ui->pituusSpin, SIGNAL(valueChanged(int)),
            this, SLOT(laske_bmi()));
    connect(ui->painoSpin, SIGNAL(valueChanged(int)),
            this, SLOT(laske_bmi()));

    // Lisätään sukupuolivalikkotoiminnat ActionGrouppiin,
    // jolloin vain toinen sukupuoli voi olla valittuna.
    QActionGroup *AG = new QActionGroup(ui->menuSukupuoli);
    AG->addAction(ui->actionNainen);
    AG->addAction(ui->actionMies);
}

Paaikkuna::~Paaikkuna()
{
    delete ui;
}

// Metodissa asetetaan ikkunan arvot alkutilaan.
void Paaikkuna::alusta()
{
    // Asetetaan nainen oletussukupuoleksi.
    ui->actionNainen->setChecked(true);
    ui->sukupuoliLabel->setText("nainen");
    // Nollataan paino- ja pituusvalikot.
    ui->painoSpin->setValue(0);
    ui->pituusSpin->setValue(0);
    // Asetetaan painoindeksin ja tulkinnan kentät viivoiksi.
    ui->bmiLabel->setText("-");
    ui->tulkintaLabel->setText("-");

}
// Metodi, jossa lasketaan BMI.
void Paaikkuna::laske_bmi()
{
    int paino = ui->painoSpin->value();
    int pituus = ui->pituusSpin->value();

    // Lasketaan BMI:n arvo.
    double pituus_metreina = pituus / 100.0;
    double BMI = paino/(pituus_metreina * pituus_metreina);

    // Kun käyttäjä on asettanut pituuden ja painon,
    // näytetään BMI:n arvo ikkunassa.
    if (pituus > 0 and BMI > 0){
        ui->bmiLabel->setNum(BMI);
        tulkitse_bmi(BMI);

    } else {

        // Jos painoa tai pituutta ei ole syötetty, BMI- ja tulkintaketät
        // ovat viivoja.
        ui->bmiLabel->setText("-");
        ui->tulkintaLabel->setText("-");
    }
}

// Metodi, jossa verrataan BMI:n arvoa taulukon arvoihin
// ja tulkitaan tulosta.
void Paaikkuna::tulkitse_bmi(double BMI)
{
    // Vektorit sisältävät arvot, joiden mukaan henkilön BMI tulkitaan.
    std::vector <double> miehen_bmi_arvot = { 20.7, 26.4, 27.8, 31.1 };
    std::vector <double> naisen_bmi_arvot = { 19.1, 25.8, 27.3, 32.2 };

    // Osoitin, jonka avulla käsitellään valittua vektoria.
    std::vector <double> *bmi_arvot;

    // Tutkitaan, kumpi sukupuoli on valittuna ja valitaan vektori sen mukaan.
    if (ui->actionMies->isChecked()) {

        bmi_arvot = &miehen_bmi_arvot;

    } else if (ui->actionNainen->isChecked()) {

        bmi_arvot = &naisen_bmi_arvot;
    }

    // Verrataan BMI:n arvoa vektorin arvoihin ja asetetaan tulkinta
    // sen mukaan.
    if (BMI <= (*bmi_arvot)[0]) {

        ui->tulkintaLabel->setText("alipainoa");

    } else if ((*bmi_arvot)[0] < BMI and BMI <= (*bmi_arvot)[1]) {

        ui->tulkintaLabel->setText("normaali");

    } else if ((*bmi_arvot)[1] < BMI and BMI <= (*bmi_arvot)[2]) {

        ui->tulkintaLabel->setText("lievää ylipainoa");

    } else if ((*bmi_arvot)[2] < BMI and BMI <= (*bmi_arvot)[3]) {

        ui->tulkintaLabel->setText("ylipainoa");

    } else if ((*bmi_arvot)[3] < BMI) {

        ui->tulkintaLabel->setText("paljon ylipainoa");
    }

}

// Metodia kutsutaan, kun käyttäjä valitsee sukupuoleksi naisen.
void Paaikkuna::on_actionNainen_triggered()
{
    ui->sukupuoliLabel->setText("nainen");
    // Jos käyttäjä valitseekin sukupuolen vasta syötettyään mittansa,
    // lasketaan BMI valitulle sukupuolelle.
    laske_bmi();
}

// Metodia kutsutaan, kun käyttäjä valitsee sukupuoleksi miehen.
void Paaikkuna::on_actionMies_triggered()
{
    ui->sukupuoliLabel->setText("mies");
    laske_bmi();
}

// Metodia kutsutaan, kun käyttäjä valitsee toiminnoksi
// alkutilaan asetuksen.
void Paaikkuna::on_actionAlkutila_triggered()
{
    alusta();
}

// Metodia kutsutaan, kun käyttäjä valitsee toiminnoksi
// lopetuksen.
void Paaikkuna::on_actionLopeta_triggered()
{
    // Suljetaan ikkuna.
    Paaikkuna::close();
}


