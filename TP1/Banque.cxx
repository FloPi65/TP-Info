#include "Banque.h"

// Constructeur
Banque::Banque(int maxClient) : tab(nullptr), maxClient(maxClient), nbClients(0) {
    if (this->maxClient <= 0) this->maxClient = 1;
    tab = new Client*[this->maxClient];
    for (int i = 0; i < this->maxClient; ++i) tab[i] = nullptr;
}

// Destructeur (ne détruit pas les Client* pointés)
Banque::~Banque() {
    delete[] tab;
    tab = nullptr;
}


// Ajouter un client (on stocke l'adresse)
bool Banque::ajouter(Client& c) {
    if (nbClients >= maxClient) {
        std::cout << "Banque pleine: impossible d'ajouter\n";
        return false;
    }
    if (appartient(c)) {
        std::cout << "Client deja present dans la banque.\n";
        return false;
    }
    tab[nbClients++] = &c;
    return true;
}

// Afficher
void Banque::afficher() const {
    std::cout << "=== Banque (" << nbClients << "/" << maxClient << ") ===\n";
    for (int i = 0; i < nbClients; ++i) {
        if (tab[i]) tab[i]->afficher();
    }
}

// Test d'appartenance (compare adresses)
bool Banque::appartient(const Client& c) const {
    for (int i = 0; i < nbClients; ++i) {
        if (tab[i] == &c) return true;
    }
    return false;
}
// Constructeur par copie (nouveau tableau, mêmes pointeurs vers clients)
Banque::Banque(const Banque& other)
    : tab(nullptr), maxClient(other.maxClient), nbClients(other.nbClients) {
    tab = new Client*[maxClient];
    for (int i = 0; i < maxClient; ++i) {
        tab[i] = (i < nbClients) ? other.tab[i] : nullptr;
    }
}
