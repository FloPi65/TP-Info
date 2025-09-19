#ifndef BANQUE_H
#define BANQUE_H

#include <iostream>
#include "Client.h"

class Banque {
private:
    Client** tab;    // tableau dynamique de pointeurs vers Client
    int maxClient;   // capacité
    int nbClients;   // nombre d'éléments stockés

public:
    explicit Banque(int maxClient);
    ~Banque();

    bool ajouter(Client& c);
    void afficher() const;
    bool appartient(const Client& c) const;

    // constructeur par copie (alloue un nouveau tableau, copie les pointeurs)
    Banque(const Banque& other);

};

#endif
