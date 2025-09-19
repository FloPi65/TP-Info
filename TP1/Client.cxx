#include "Client.h"
#include <iostream>


Client::Client(const string& nom, const Date& naissance, Compte& compte)
    : nom(nom), naissance(naissance), compte(compte) {}

void Client::deposer(double montant) {
    compte.deposer(montant);
}

void Client::retirer(double montant) {
    compte.retirer(montant);
}

void Client::virer(double montant, Client& autre) {

    compte.virer(montant, autre.compte);// on vire de MON compte vers le compte de l'autre
}

void Client::afficher() const {
    cout << "Client: " << nom << "\nDate de naissance: ";
    naissance.afficher();// utilise Date::afficher()
    compte.afficher();// affiche le solde
}
