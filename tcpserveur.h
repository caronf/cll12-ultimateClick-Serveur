#ifndef TCPSERVEUR_H
#define TCPSERVEUR_H

#include <QTcpServer>

class TcpServeur : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServeur(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // TCPSERVEUR_H
