#include "thclient.h"

ThClient::ThClient(int socketDescriptor, int IDCli)
{
    m_sockDesc = socketDescriptor;
    m_IDcli = IDCli; // Identifiant du client
    m_ba.append((char)0); // un x de o signifie que la partie n'est pas encore commencée
    m_ba.append((char)0);
    m_EnCours = true;
    m_Mod = false;
}

void ThClient::run()
{
    QTcpSocket socket;
    QByteArray baRecep;
    QByteArray ba;

    socket.setSocketDescriptor(m_sockDesc);

    do
    {
        baRecep = socket.read(socket.bytesAvailable());
        if(baRecep[0] == 1) // Un 1 signifie que le client a clické sur le cercle
        {
            emit(siClick(m_IDcli));
            ba.append((char)2);
            socket.write(ba); // L'envoi d'un 2 signifie que j'accorde un point au client
        }
        baRecep.clear();

        ba = m_ba;
        socket.write(ba);
        socket.waitForBytesWritten();
        msleep(10);
    }while(socket.waitForReadyRead() && m_EnCours);

    socket.close();
}

void ThClient::slNouvCoords(ushort x, ushort y, ushort r)
{
    QByteArray ba;
    ba.append((char)1); // Un signifie que les prochains bytes seront un cercle
    ba.append(x >> 8);
    ba.append(x);
    ba.append(y >> 8);
    ba.append(y);
    ba.append(r);

    m_ba.clear();
    m_ba.append(ba);
}

void ThClient::slJeu(int IDGagnant)
{
    m_ba.clear();
    if(m_IDcli == IDGagnant)
    {
        m_ba.append((char)2);
    }
    else
    {
        m_ba.append((char)3);
    }
    msleep(10); // Attend 10 ms pour etre sur que le resultat final soit envoyé
    m_EnCours = false;
}
