#ifndef TCPSERVEUR_H
#define TCPSERVEUR_H

#include "thclient.h"
#include <QTcpServer>
#include <QTimer>
#include <QTcpSocket>
#include <QDateTime>
#include <stdlib.h>

class CServeur : public QTcpServer
{
    Q_OBJECT
public:
    explicit CServeur(QObject *parent = 0);
    ~CServeur();
    
signals:
    void siNouvCoords(ushort x, ushort y, ushort r);
    void siJeu(int IDGagnant);

public slots:
    void incomingConnection(int socketDescriptor);
    void slClick(int IDCli);

private slots:
    void on_m_timerJeu_timeout();
    void on_m_timerMort_timeout();

private:
    ushort m_nbJoueurs;
    ushort m_x, m_y, m_r;
    ushort m_varx, m_vary; //contient la valeur qui sera incrémentée à x et y lors du déplacement
    int m_diff; // Contient la difficulté variant entre 1 (difficile) et 3(facile)
    QTimer* m_timerJeu, *m_timerMort;
    int m_pointage[50];
};

#endif // TCPSERVEUR_H
