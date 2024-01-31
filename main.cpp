#include <iostream>
#include "Carte.h"
#include "Paquet.h"
#include "MainCarte.h"
using namespace std;

void afficherMenu()
{
    cout << "MENU\n";
    cout << "1. Afficher le paquet de carte\n";
    cout << "2. Piger nombre de carte\n";
    cout << "3. Mélanger le paquet\n";
    cout << "4. Afficher la main\n";
    cout << "5. Discarter nombre de carte de la main\n";
    cout << "6. Réniatialiser tout\n";
    cout << "0. Quitter\n";
}

int main()
{
    int choix;
    int nombre = 0;
    Paquet paquet;
    MainCarte mainJoueur;
    do
    {
        afficherMenu();
        cin >> choix;
        switch (choix)
        {
        case 1:
            paquet.AfficherPaquet();
            break;
        case 2:
            cout << "Combien de carte voulez-vous piger? ";
            cin >> nombre;
            mainJoueur.PigerMain(nombre, &paquet);
            break;
        case 3:
            paquet.Melanger();
            break;
        case 4:
            mainJoueur.AfficherMain();
            break;
        case 5:
            cout << "Combien de carte voulez-vous discarter? ";
            cin >> nombre;
            mainJoueur.Discarter(nombre);
            break;
        case 6:
            paquet.Renitialiser();
            mainJoueur.RenitialiserMain();
            break;
        default:
            break;
        }
    } while (choix != 0);

    return 0;
}
