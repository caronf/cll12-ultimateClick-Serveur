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
    void slJeu(int IDGagnant);
    void slNouvCoords(ushort x, ushort y, ushort r);
    void run();

private:
    int m_sockDesc;
    int m_IDcli;
    bool m_EnCours, m_Mod;
    QByteArray m_ba;
};

#endif // THCLIENT_H
