#include "Paquet.h"
#include <iostream>
#include <vector>

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
    count++;
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

// Méthode pour mélanger les cartes
void Paquet::Melanger() {

    // Utilise rand() pour mélanger les cartes
    srand(time(NULL)); 
    if (m_premier == nullptr || m_premier->next == nullptr) return; 

    // Compte le nombre de cartes dans le paquet
    Node* current = m_premier;
    int length = 0;
    while (current) {
        length++;
        current = current->next;
    }

    // Crée un tableau de pointeurs de nodes
    std::vector<Node*> nodePointers(length);
    current = m_premier;
    for (int i = 0; i < length; i++) {
        nodePointers[i] = current;
        current = current->next;
    }

    // Mélange les cartes en utilisant fisher-yates
    for (int i = 0; i < length - 1; i++) {
        int j = i + rand() % (length - i); 
        if (i != j) {
            Swap(nodePointers[i], nodePointers[j]);
        }
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
            Carte *carte = new Carte{j, i};
            Ajouter(carte); // 
        }
    }
}

Node *Paquet::PigerPaquet()
{
    Node *node = m_premier;
    m_premier = m_premier->next;
    return node;
}
