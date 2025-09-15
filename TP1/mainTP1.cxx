#include "Date.h"
#include "Compte.h"
#include "Client.h"

int main() {
    // ===== TEST DE LA CLASSE DATE =====
    Date d(3, 5, 2001);
    Date* dd = new Date(16, 12, 2001);

    d.afficher();
    dd->afficher();

    // ===== TEST DE LA CLASSE COMPTE =====
    Compte c1(100.0);     // Compte avec 100€
    c1.deposer(50.0);     // +50€
    c1.retirer(30.0);     // -30€
    c1.afficher();

    Compte* c2 = new Compte(500.0); // Compte dynamique avec 500€
    c2->afficher();

    c2->virer(100.0, c1); // Virement de 100€ de c2 vers c1
    c1.afficher();
    c2->afficher();

    c1.virer(50.0, *c2);  // Virement de 50€ de c1 vers c2
    c1.afficher();
    c2->afficher();

    // ===== TEST DE LA CLASSE CLIENT =====
    // cl1: Flo, né à d, possède c1
    Client cl1("Flo", d, c1);
    cl1.afficher();

    // Déposer 1000€ pour cl1
    cl1.deposer(1000.0);
    cl1.afficher();

    // cl2: Arnaud, né à dd, possède c2
    Client* cl2 = new Client("Arnaud", *dd, *c2);
    cl2->afficher();

    // Retirer 100€ chez cl2
    cl2->retirer(100.0);
    cl2->afficher();

    // Virements entre clients
    cl1.virer(500.0, *cl2);
    cl2->virer(100.0, cl1);

    // Affichage final
    cl1.afficher();
    cl2->afficher();

    // Nettoyage (APRÈS utilisation)
    delete cl2;
    delete c2;
    delete dd;

    return 0;
}
