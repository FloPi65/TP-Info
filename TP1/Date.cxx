#include "Date.h"

// Constructeur
Date::Date(int jour, int mois, int an) {
    this->jour = jour;
    this->mois = mois;
    this->an = an;
}

// Méthode afficher
void Date::afficher() const {
    cout << jour << "/" << mois << "/" << an << endl;
}
