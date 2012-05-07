#include "ultimateclick_serveur.h"
#include "ui_ultimateclick_serveur.h"
#include "cserveur.h"

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
    QString textBouton;

    m_Actif = !m_Actif; // Inverse la valeur de m_Actif
    if(m_Actif)
    {
        textBouton = "Stop";
        m_TcpServ = new CServeur();
        m_TcpServ->listen(QHostAddress::Any, 55415);
    }
    else
    {
        m_TcpServ->close();
        textBouton = "Start!";
    }

    ui->btnStartStop->setText(textBouton); // Affiche le message approprié sur le bouton
}
