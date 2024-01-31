#include "Paquet.h"
#include <iostream>

Paquet::Paquet()
{
    Repopuler();
}

Paquet::~Paquet()
{
    Node *node = m_premier;
    while (node != nullptr)
    {
        Node *temp = node;
        node = node->next;
        delete temp->carte;
        delete temp;
    }
}

void Paquet::Ajouter(Carte *carte)
{
    Node *node = new Node;
    node->carte = carte;
    node->next = m_premier;
    m_premier = node;
}

void Paquet::AfficherPaquet()
{
    if (m_premier == nullptr)
    {
        std::cout << "Le paquet est vide!" << std::endl;
        return;
    }

    Node *node = m_premier;
    while (node != nullptr)
    {
        node->carte->AfficherCarte();
        node = node->next;
    }
}

void Paquet::Melanger()
{
    srand(time(NULL));
    int n = 52;
    for (int i = 0; i < n; i++)
    {
        int r = i + (rand() % (n - i));
        Node *node = m_premier;
        Node *node2 = m_premier;
        for (int j = 0; j < i; j++)
        {
            node = node->next;
        }
        for (int j = 0; j < r; j++)
        {
            node2 = node2->next;
        }
        Swap(node, node2);
    }
}

void Paquet::Renitialiser()
{
    // Supprime toutes les cartes et les nodes
    Node *node = m_premier;
    while (node != nullptr)
    {
        Node *temp = node;
        node = node->next;
        delete temp->carte;
        delete temp;
    }

    // Remet m_premier à nullptr
    m_premier = nullptr;

    Repopuler();
}

void Paquet::Repopuler()
{
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            Carte *carte = new Carte(j, i);
            Ajouter(carte);
        }
    }
}
void Paquet::Swap(Node *a, Node *b)
{
    Carte *temp = a->carte;
    a->carte = b->carte;
    b->carte = temp;
}

Node *Paquet::PigerPaquet()
{
    Node *node = m_premier;
    m_premier = m_premier->next;
    return node;
}
