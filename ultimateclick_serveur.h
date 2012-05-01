#ifndef ULTIMATECLICK_SERVEUR_H
#define ULTIMATECLICK_SERVEUR_H

#include <QMainWindow>
#include "tcpserveur.h"

namespace Ui {
class ultimateClick_serveur;
}

class ultimateClick_serveur : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ultimateClick_serveur(QWidget *parent = 0);
    ~ultimateClick_serveur();
    
private slots:
    void on_btnStartStop_clicked();

private:
    Ui::ultimateClick_serveur *ui;
    bool m_Actif;
    TcpServeur* m_TcpServ;
};

#endif // ULTIMATECLICK_SERVEUR_H
