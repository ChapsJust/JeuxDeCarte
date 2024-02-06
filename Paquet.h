#pragma once
#include "Carte.h"
#include "Liste.h"

class Paquet: public Liste
{
private:
    Node *m_premier{nullptr};
public:
    Paquet();
    ~Paquet();
    Node *PigerPaquet();
    void Melanger();
    void Afficher();
    void Renitialiser();
    void Ajouter(Carte *carte);
    void AfficherPaquet();
    void Repopuler();
};


