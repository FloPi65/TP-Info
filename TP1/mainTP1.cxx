#include "Date.h"
#include "Compte.h"
#include "Client.h"
#include "Banque.h"

int main() {
    Date d(3, 5, 2001);
    Date* dd = new Date(16, 12, 2001);

    d.afficher();
    dd->afficher();

    Compte c1(100.0);
    c1.deposer(50.0);
    c1.retirer(30.0);
    c1.afficher();

    Compte* c2 = new Compte(500.0);
    c2->virer(100.0, c1);
    c1.virer(50.0, *c2);
    c1.afficher();
    c2->afficher();

    Client cl1("Flo", d, c1);
    cl1.deposer(1000.0);
    cl1.afficher();

    Client* cl2 = new Client("Arnaud", *dd, *c2);
    cl2->retirer(100.0);
    cl2->afficher();

    cl1.virer(500.0, *cl2);
    cl2->virer(100.0, cl1);

    cl1.afficher();
    cl2->afficher();

    Banque b(100);
    b.ajouter(cl1);
    b.ajouter(*cl2);
    b.afficher();

    Banque b2(b);
    b2.afficher();

    delete cl2;
    delete c2;
    delete dd;

    return 0;
}
