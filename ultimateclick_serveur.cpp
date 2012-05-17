#include "ultimateclick_serveur.h"
#include "ui_ultimateclick_serveur.h"
#include "cserveur.h"

ultimateClick_serveur::ultimateClick_serveur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ultimateClick_serveur)
{
    ui->setupUi(this);
    m_TcpServ = new CServeur();
    m_TcpServ->listen(QHostAddress::Any, 55415);
    srand(time(0));
}

ultimateClick_serveur::~ultimateClick_serveur()
{
    m_TcpServ->close();
    delete m_TcpServ;
    delete ui;
}
