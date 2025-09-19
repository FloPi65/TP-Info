#include "Banque.h"

//Constructeur
Banque::Banque(int maxClient) {
    if (maxClient <= 0) maxClient = 1;
    this->maxClient = maxClient;
    nbClients = 0;
    tab = new Client*[maxClient];
    for (int i = 0; i < maxClient; ++i)
        tab[i] = nullptr;
}

//Destructeur
Banque::~Banque() {
    delete[] tab;
}

//Ajoute un client
bool Banque::ajouter(Client& c) {
    if (nbClients >= maxClient) return false;
    if (appartient(c)) return false;
    tab[nbClients++] = &c;
    return true;
}

//Affiche la banque
void Banque::afficher() const {
    std::cout << "Banque : " << nbClients << " clients / " << maxClient << "\n";
    for (int i = 0; i < nbClients; ++i)
        tab[i]->afficher();
}

//Teste si un client appartient à la banque
bool Banque::appartient(const Client& c) const {
    for (int i = 0; i < nbClients; ++i)
        if (tab[i] == &c) return true;
    return false;
}

//Constructeur par copie
Banque::Banque(const Banque& other) {
    maxClient = other.maxClient;
    nbClients = other.nbClients;
    tab = new Client*[maxClient];
    for (int i = 0; i < maxClient; ++i)
        tab[i] = (i < nbClients) ? other.tab[i] : nullptr;
}
