#ifndef BANQUE_H
#define BANQUE_H
#include <iostream>
#include "Client.h"
class Banque{
private :
    Client * tab ; // tableau dynamique de clients
    int maxClient; // taille max de tab
    int nbClients; //indice 1ere case libre dans tab
public:

    Banque(int maxClient);//Constructeur

    ~Banque();//Destructeur

    bool ajouter(Client& c);//Ajouter un client (par référence, on stocke son adresse)


    void afficher() const;//Afficher le contenu

    bool appartient(const Client& c) const;//Test d'appartenance (par adresse)

    Banque(const Banque& other);//Constructeur par copie (copie le tableau de pointeurs, pas les clients)

    // (optionnel) opérateur d’affectation par copie pour être carré
    Banque& operator=(const Banque& other);
};

#endif
