#ifndef CLIENT_H
#define CLIENT_H

#include "Date.h"
#include "Compte.h"
#include <iostream>

using namespace std;

class Client {
private:
    string nom;
    Date naissance;
    Compte &compte;

public:
    Client(const string& nom, const Date& naissance, Compte& compte);//Constructeur

    void deposer(double montant);
    void retirer(double montant);
    void virer(double montant, Client& autre); // virement vers un autre client


    void afficher() const;
};

#endif
