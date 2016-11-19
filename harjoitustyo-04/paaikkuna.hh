#ifndef PAAIKKUNA_HH
#define PAAIKKUNA_HH

#include <QMainWindow>
#include <QMenuBar>
#include <QActionGroup>

namespace Ui {
class Paaikkuna;
}

class Paaikkuna : public QMainWindow
{
    Q_OBJECT

public:
    explicit Paaikkuna(QWidget *parent = 0);
    ~Paaikkuna();

public slots:
    // Ikkunan alustus.
    void alusta();
    // Painoindeksin lasku.
    void laske_bmi();
    // BMI:n tulkitseminen taulukon avulla.
    void tulkitse_bmi(double);

private slots:
    void on_actionAlkutila_triggered();

    void on_actionLopeta_triggered();

    void on_actionNainen_triggered();

    void on_actionMies_triggered();

private:
    Ui::Paaikkuna *ui;
};

#endif // PAAIKKUNA_HH
