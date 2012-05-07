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
    
signals:
    void siNouvCoords(int x, int y, int r);
    void siJeu();

public slots:
    void incomingConnection(int socketDescriptor);
    void slClick();

private slots:
    void on_m_timerJeu_timeout();

private:
    int m_nbJoueurs;
    int m_x, m_y, m_r;
    int m_varx, m_vary; //contient la valeur qui sera incrémentée à x et y lors du déplacement
    QTimer* m_timerJeu;
};

#endif // TCPSERVEUR_H
