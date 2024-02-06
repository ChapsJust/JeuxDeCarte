#pragma once
#include "Paquet.h"

class MainCarte: public Liste
{
public:
    MainCarte();
    MainCarte(int nombre, Paquet *paquet);
    void PigerMain(int nombre, Paquet *paquet);
    void Discarter(int nombre);
    void AfficherMain();
    void RenitialiserMain();
    ~MainCarte();
};
