#ifndef ULTIMATECLICK_SERVEUR_H
#define ULTIMATECLICK_SERVEUR_H

#include <QMainWindow>
#include <QtGui>
#include "cserveur.h"
#include <stdlib.h>
#include <time.h>

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

private:
    Ui::ultimateClick_serveur *ui;
    bool m_Actif;
    CServeur* m_TcpServ;
};

#endif // ULTIMATECLICK_SERVEUR_H
