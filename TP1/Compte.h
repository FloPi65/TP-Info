#ifndef COMPTE_H
#define COMPTE_H

#include <iostream>
using namespace std;

class Compte {
private:
    double solde;

public:
    Compte(double solde);// Constructeur

    void deposer(double montant);// Déposer de l'argent

    void retirer(double montant);// Retirer de l'argent

    void virer(double montant, Compte &autre);// Virer un montant vers un autre compte

    void afficher() const;// Afficher le solde
};

#endif
