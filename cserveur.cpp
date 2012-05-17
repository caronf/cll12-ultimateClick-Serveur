#include "cserveur.h"

CServeur::CServeur(QObject *parent) :
    QTcpServer(parent)
{
    m_nbJoueurs = 0;

    m_timerJeu = new QTimer(this);
    m_timerJeu->setSingleShot(true);
    connect(m_timerJeu, SIGNAL(timeout()), this, SLOT(on_m_timerJeu_timeout()));
    m_timerJeu->start(5000);

    m_timerMort = new QTimer(this);
    m_timerMort->setSingleShot(true);
    connect(m_timerMort, SIGNAL(timeout()), this, SLOT(on_m_timerMort_timeout()));

    m_diff = 4; //Met la difficulté initiale à 4 pour que le premier click n'accorde aucun point
}

void CServeur::incomingConnection(int socketDescriptor)
{
    ThClient* thcli;

    if(m_nbJoueurs < 50) // Si la capacité maximum a été atteinte on ne fait rien
    {
        thcli = new ThClient(socketDescriptor, m_nbJoueurs);
        m_pointage[m_nbJoueurs] = 0;
        connect(this, SIGNAL(siNouvCoords(ushort, ushort, ushort)), thcli, SLOT(slNouvCoords(ushort, ushort, ushort))); // Signal pour l'envoi de nouvelles coordonées
        connect(this, SIGNAL(siJeu(int)), thcli, SLOT(slJeu(int)));
        connect(thcli, SIGNAL(siClick(int)), this, SLOT(slClick(int)));
        m_nbJoueurs++;
        thcli->start();

        if(m_nbJoueurs == 2) // Lorsqu'on a deux joueurs la partie peut commencer
        {
            slClick(0); // Génére le premier emplacement random
            m_timerJeu->start(1000); //On laisse le temps aux joueurs de se préparer
            // D'autres joueurs peuvent se joindre en tout temps
        }
    }
}

void CServeur::on_m_timerJeu_timeout()
{
    emit(siNouvCoords(m_x, m_y, m_r));
    m_x += m_varx;
    m_y += m_vary;

    if(m_x + m_r > 600) // limites horizontales
    {
        m_x = 600 - m_r;
    }
    else
    {
        if(m_x - m_r < 0)
        {
            m_x = 1 + m_r;
        }
    }

    if(m_y + m_r > 300) // limites verticales
    {
        m_y = 300 - m_r;
    }
    else
    {
        if(m_y - m_r < 0)
        {
            m_y = 0 + m_r;
        }
    }
    m_timerJeu->start(25); // Le déplacement aura lieu tous les 25 ms
}

void CServeur::slClick(int IDCli)
{
    // Un des clients nous informe qu'il a clické sur le cercle
    m_pointage[IDCli] += 4 - m_diff; // Additionne le nombre de point au client qui a clické en fonction de la difficulté
                                     // diff 1 = 3pts, diff 2 = 2 pts et diff 3 = 1 pt
    srand(time(0));
    m_diff = rand() % 3 + 1;
    m_r = m_diff * 8; // Les ronds sont de grosseur 8, 16 et 24 pixels de rayon
    m_x = rand() % (600 - 2 * m_r) + m_r; // Génére un nombre random entre le rayon et 600 - le rayon
    m_y = rand() % (300 - 2 * m_r) + m_r;
    m_varx = rand() % 7 - 3;
    m_vary = rand() % 7 - 3; // Défini une nouvelle valeur de déplacement entre -3 et 3

    m_timerMort->start(3000); // Si personne ne clique pas d'ici 3 secondes la partie se termine
}

void CServeur::on_m_timerMort_timeout()
{
    int IDgagnant, ptsGagnant;
    m_timerJeu->stop();

    for(int i = 0; i < m_nbJoueurs; i++) // Boucle récupérant l'id du gagnant
    {
        if(m_pointage[i] > ptsGagnant)
        {
            IDgagnant = i;
            ptsGagnant = m_pointage[i];
        }
    }

    emit(siJeu(IDgagnant));
    m_nbJoueurs = 0;
}

CServeur::~CServeur()
{
    on_m_timerMort_timeout(); // Si cette classe est détruite pendant le jeu, on déclanche la fin de partie
}
