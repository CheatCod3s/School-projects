#include "paaikkuna.hh"
#include "ui_paaikkuna.h"

Paaikkuna::Paaikkuna(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Paaikkuna)
{
    ui->setupUi(this);

    connect(ui->nollaa_button, SIGNAL(clicked()),
                      this, SLOT(nollaa_kaikki_arvot()));
    connect(ui->kmh_spinbox, SIGNAL(valueChanged(int)),
            this, SLOT(kmh_maili_muunnin()));

}

Paaikkuna::~Paaikkuna()
{
    delete ui;
}


void Paaikkuna::nollaa_kaikki_arvot() {
          ui->kmh_spinbox->setValue(0);
          ui->kmh_slider->setValue(0);
          ui->miles_lcd->display(0.0);
}

void Paaikkuna::kmh_maili_muunnin(){
    double kmh = ui->kmh_spinbox->value();
    double maili = kmh * 0.6213;

    ui->miles_lcd->display(maili);

}
