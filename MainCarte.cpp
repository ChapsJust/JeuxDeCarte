#include "MainCarte.h"
#include "Carte.h"
#include <iostream>
using namespace std;

MainCarte::MainCarte() {}

MainCarte::MainCarte(int nombre, Paquet *paquet)
{
    PigerMain(nombre, paquet);
}

void MainCarte::PigerMain(int nombre, Paquet *paquet)
{
    for (int i = 0; i < nombre; i++)
    {
        Node *pigeNode = paquet->PigerPaquet();
        // Vérifie si le paquet est vide sinon arrete de piger
        if (pigeNode == nullptr)
        {
            cout << "Le paquet est vide!" << endl;
            break;
        }

        Node *node = new Node;
        node->carte = pigeNode->carte;
        node->next = m_premier;
        node->back = nullptr;

        if (m_premier != nullptr)
        {
            m_premier->back = node;
        }

        m_premier = node;
    }
}

void MainCarte::Discarter(int nombre)
{
    for (int i = 0; i < nombre; i++)
    {
        if (m_premier == nullptr)
        {
            cout << "La main est vide!" << endl;
            return;
        }
        Node *node = m_premier;
        m_premier = m_premier->next;
        delete node->carte;
        delete node;
    }
}

void MainCarte::AfficherMain()
{
    // Vérifie si la main est vide
    if (m_premier == nullptr)
    {
        cout << "La main est vide!" << endl;
        return;
    }

    // Affiche les cartes dans la main
    Node *node = m_premier;
    while (node != nullptr)
    {
        node->carte->AfficherCarte();
        node = node->next;
    }
}

MainCarte::~MainCarte()
{
    RenitialiserMain();
}

void MainCarte::RenitialiserMain()
{
    Node *node = m_premier;
    while (node != nullptr)
    {
        Node *temp = node;
        node = node->next;
        delete temp->carte;
        delete temp;
    }
    m_premier = nullptr;
}