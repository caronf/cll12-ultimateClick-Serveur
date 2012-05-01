#ifndef ULTIMATECLICK_SERVEUR_H
#define ULTIMATECLICK_SERVEUR_H

#include <QMainWindow>

namespace Ui {
class ultimateClick_serveur;
}

class ultimateClick_serveur : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ultimateClick_serveur(QWidget *parent = 0);
    ~ultimateClick_serveur();
    
private:
    Ui::ultimateClick_serveur *ui;
};

#endif // ULTIMATECLICK_SERVEUR_H
