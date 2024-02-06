#pragma once
#include "Carte.h"
struct Node
{
    Carte *carte;
    Node *next;
    Node *back;
};

class Liste
{
private:
    
protected:
    int count{0};
    Node *m_premier{nullptr};
    Liste();
    ~Liste();
    void Swap(Node *a, Node *b);
};
