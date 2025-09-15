#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int jour;
    int mois;
    int an;

public:
    // Constructeur avec arguments
    Date(int jour, int mois, int an);

    // Méthode pour afficher la date
    void afficher() const;
};

#endif
