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

void ultimateClick_serveur::on_btnStartStop_clicked()
{
    QString textBouton = "Start!";

    m_Actif = !m_Actif; // Inverse la valeur de m_Actif
    if(m_Actif)
    {
        textBouton = "Stop";
        m_TcpServ = new TcpServeur();
    }

    ui->btnStartStop->setText(textBouton);
}
