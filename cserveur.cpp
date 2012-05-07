#include "cserveur.h"

CServeur::CServeur(QObject *parent) :
    QTcpServer(parent)
{
    m_nbJoueurs = 0;
    m_timerJeu = new QTimer(this);
    m_timerJeu->setSingleShot(true);
    connect(m_timerJeu, SIGNAL(timeout()), this, SLOT(on_m_timerJeu_timeout()));
    m_timerJeu->start(5000);
}

void CServeur::incomingConnection(int socketDescriptor)
{
    QTcpSocket socket;
    ThClient* thcli;

    thcli = new ThClient(socketDescriptor, m_nbJoueurs);
    connect(this, SIGNAL(siNouvCoords(int, int, int)), thcli, SLOT(slNouvCoords(int, int, int))); // Signal pour l'envoi de nouvelles coordonées
    m_nbJoueurs++;

    if(m_nbJoueurs == 1) // Lorsqu'on a deux joueurs la partie peut commencer
    {
        m_timerJeu->start(1); //On attend tout de même 2 secondes afin de laisser à d'autres joueurs de se joindre à la partie
        thcli->run();
    }
}

void CServeur::on_m_timerJeu_timeout()
{
    //Une fois le temps d'attente terminé, on peut commencer la partie
    /*int i = rand();
    QDateTime dtEnvoi, dtClick;
    dtEnvoi = QDateTime::currentDateTime();
    while(dtEnvoi.secsTo(dtClick))
    {

    }*/
    emit(siNouvCoords(300, 150, 10));
}
