#include "thclient.h"

ThClient::ThClient(int socketDescriptor, int IDCli)
{
    m_sockDesc = socketDescriptor;
}

void ThClient::run()
{
    QTcpSocket socket;

    socket.setSocketDescriptor(m_sockDesc);

    while(socket.waitForReadyRead())
    {
        socket.write(m_ba);
    }
}

void ThClient::slNouvCoords(int x, int y, int r)
{
    QByteArray ba;
    ba.append(x);
    ba.append(y);
    ba.append(r);
    m_ba = ba;
}

void ThClient::slResultats()
{

}
