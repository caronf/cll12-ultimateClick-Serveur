#include "ultimateclick_serveur.h"
#include "ui_ultimateclick_serveur.h"

ultimateClick_serveur::ultimateClick_serveur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ultimateClick_serveur)
{
    ui->setupUi(this);
}

ultimateClick_serveur::~ultimateClick_serveur()
{
    delete ui;
}
