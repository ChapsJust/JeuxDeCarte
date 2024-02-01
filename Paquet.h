#pragma once
#include "Carte.h"

struct Node
{
    Carte *carte;
    Node *next;
    Node *back;
};

class Paquet
{
private:
    Node *m_premier{nullptr};
    int count{0};

public:
    Paquet();
    ~Paquet();
    Node *PigerPaquet();
    void Melanger();
    void Afficher();
    void Renitialiser();
    void Ajouter(Carte *carte);
    void AfficherPaquet();
    void Swap(Node *a, Node *b);
    void Repopuler();
    void setCount(int nombre) { count+=nombre; }
};


