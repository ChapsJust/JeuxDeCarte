#include "Liste.h"

Liste::Liste() {}

Liste::~Liste() {}

void Liste::Swap(Node *a, Node *b)
{
    Carte *temp = a->carte;
    a->carte = b->carte;
    b->carte = temp;
}