#include "Carte.h"
#include <iostream>
using namespace std;

Carte::Carte() {}

Carte::~Carte() {}

Carte::Carte(int valeur, int couleur) : valeur(valeur), couleur(couleur) {}

void Carte::AfficherCarte()
{
    cout << "Carte: " << couleur << " " << valeur << endl;
}