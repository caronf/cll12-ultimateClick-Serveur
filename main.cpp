#include <QtGui/QApplication>
#include "ultimateclick_serveur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ultimateClick_serveur w;
    w.show();
    
    return a.exec();
}
