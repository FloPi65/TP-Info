#ifndef BANQUE_H
#define BANQUE_H

#include <iostream>
#include "Client.h"

class Banque {
private:
    Client** tab;// tableau dynamique de pointeurs vers Client
    int maxClient;//capacite
    int nbClients;// nombre d'éléments stockés

public:
    Banque(int maxClient);
    ~Banque();

    bool ajouter(Client& c);
    void afficher() const;
    bool appartient(const Client& c) const;

    // constructeur par copie
    Banque(const Banque& other);

};

#endif
