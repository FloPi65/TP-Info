#include "Compte.h"

// Constructeur
Compte::Compte(double solde) {
    this->solde = solde;
}

// Déposer de l'argent
void Compte::deposer(double montant) {
    solde += montant;
}

// Retirer de l'argent
void Compte::retirer(double montant) {
    if (montant <= solde) {
        solde -= montant;
    } else {
        cout << "Retrait impossible : solde insuffisant !" << endl;
    }
}

// Virer de l'argent vers un autre compte
void Compte::virer(double montant, Compte &autre) {
    if (montant <= solde) {
        solde -= montant;
        autre.deposer(montant);
    } else {
        cout << "Virement impossible : solde insuffisant !" << endl;
    }
}

// Afficher le solde
void Compte::afficher() const {
    cout << "Solde du compte : " << solde << " €" << endl;
}
