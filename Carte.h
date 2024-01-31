#pragma once

class Carte
{
private:
    int valeur;
    int couleur;

public:
    Carte();
    ~Carte();
    Carte(int valeur, int couleur);
    void AfficherCarte();
};
