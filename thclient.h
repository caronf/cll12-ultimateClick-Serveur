#ifndef THCLIENT_H
#define THCLIENT_H

#include <QThread>
#include <QTcpSocket>
#include <QByteArray>

class ThClient : public QThread
{
    Q_OBJECT
public:
    explicit ThClient(int socketDescriptor, int IDCli);
    
signals:
    void siClick(int ID);
    
public slots:
    void slResultats();
    void slNouvCoords(int x, int y, int r);
    void run();

private:
    int m_sockDesc;
    int m_IDcli;
    QByteArray m_ba;
};

#endif // THCLIENT_H
