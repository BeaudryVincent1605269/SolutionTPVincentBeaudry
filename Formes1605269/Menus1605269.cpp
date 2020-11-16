#include "Menus1605269.h"
#include "saisir1605269.h"
using namespace std;
#include <iostream>
#include <string>



void afficherMenu1()                         // Affiche menu 1
{
	cout << "Choisissez la forme : " << endl;
	cout << "1. Rectangle " << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Carré " << endl;
	cout << "4. Losange" << endl;
	cout << "5. Quitter" << endl;
	cout << "Votre choix -->";

}

void afficherMenu2()                        // Affiche menu 2
{ 
	cout << "Choisissez le remplissage : " << endl;
	cout << "1. Forme pleine" << endl;
	cout << "2. Forme vide" << endl;
	cout << "3. Retour au menu précédent" << endl;
	cout << "Votre choix -->";


}

int validerMenu(int choixMenu, int quitter) // Permet l'affichage du bon menu dépendant où l'utilisateur se trouve dans le main.
{
	int max;        // Intègre la valeur max des choix de menu.
	int min;        // Intègre la valeur min des choix de menu.

	int choix;             

	if (choixMenu == 1)
	{
		max = 5;            // La premiere fois quon arrive dans valider menu la valeur d'arrivée est 1 donc le max et le min va s'initialiser à 5 et 1, ce qui correspont au nombre de choix 
		min = 1;            // dans le menu 1

		afficherMenu1();
		choix = saisirEntier();       // Saisir entier est la fonction qui va permettre d'entrer n'importe quoi sur le clavier sans faire planter l'exécutable.


	}
	else
	{
		max = 3;         // Si la valeur envoyée n'est pas 1 on va donc initialiser les valeur min et max à 1 et 3.
		min = 1;

		afficherMenu2();
		choix = saisirEntier();        // Saisir entier est la fonction qui va permettre d'entrer n'importe quoi sur le clavier sans faire planter l'exécutable.

	}


	while (choix == quitter && choix < min || choix > max)  // Ici, peut importe dans quelle menu on se retrouve on va devoir entrer une valeure comprise entre min et max.
	{                                                       //  Sinon, l'utilisateur va écrire à l'infini jusqu'à temps que la boucle soit satisfaite.

		switch (choixMenu)
		{
		case 1:

			cout << "Erreur: Vous devez écrire un chiffre compris entre " << min << " et " << max << endl;  // message d'alerte saffichant quand la condition de la boucle n'est pas satisfaite.
			afficherMenu1();
			// le programme demande le choix de l'utilisateur

			choix = saisirEntier();   // fonction qui reviens parce quelle permet de ne pas faire planter le programme en écrivant n'importe quoi.
			break;
		case 2:
			cout << "Erreur: Vous devez écrire un chiffre compris entre " << min << " et " << max << endl;    // idem mais pour le menu 2
			afficherMenu2();
			// le programme demande le choix de l'utilisateur

			choix = saisirEntier();
			break;
		}

	}


	return choix;             // doit retourner le choix entrée par l'utilisateur avec ou sans correction de la fonction saisirEntier.
}
