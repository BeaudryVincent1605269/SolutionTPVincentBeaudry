#include "Formes1605269.h"
using namespace std;
#include <iostream>
#include <string>
#include "saisir1605269.h"
#include <ctime>
void traiterRectangle(int fill)
{

	int ht;         // Intégration de la hauteur et la largeur
	int lg;

	cout << "Entrez la hauteur du rectangle : ";            
	ht = saisirEntier();                         // On se retrouve encore une fois dans la fonction qui permet de s'assurer de la bonne entrée de clavier par l'utilisateur.
	cout << endl;
	cout << "Entrer la largeur du rectangle : ";
	lg = saisirEntier();
	cout << endl;

	switch (fill)            // Permet de diriger le rectangle dans la catégorie remplit ou vide (1 ou 2)
	{
	case 1:
		cout << "Voici votre rectangle plein de " << ht << " x " << lg << " : " << endl;
		dessinerRectangle(ht, lg, fill);                        // Envois les valeur entrer de l'utilisateur ht, lg et le type de remplissage à la fonction dessiner.
		break;
	case 2:
		cout << "Voici votre rectangle vide de " << ht << " x " << lg << " : " << endl;
		dessinerRectangle(ht, lg, fill);
		break;
	}
}

void traiterCarre(int fill)    // idem a rectangle
{
	int ht;                    
	int lg;

	cout << "Entrer la largeur du carré : ";
	lg = saisirEntier();
	cout << endl;
	ht = lg;                          // un carré à la même largeur partout donc on égalise la hauteur à la largeur.
	switch (fill)
	{
	case 1:
		cout << "Voici votre carré plein de " << ht << " x " << lg << " : " << endl;
		dessinerRectangle(ht, lg, fill);
		break;
	case 2:
		cout << "Voici votre carré vide de " << ht << " x " << lg << " : " << endl;
		dessinerRectangle(ht, lg, fill);
		break;
	}
}

void traiterTriangle(int fill)
{
	int taille;            // intégration de la taille du triangle
	int alea;              // intégration de la variable pour l'aléatoire 


	srand(time(NULL));     // synchronise l'horloge avec la fonction d'aléatoire

	

	cout << "Veuillez entrer la hauteur du triangle : ";
	taille = saisirEntier();                                      // idem au 3 autres endroit où on retrouver saisirEntier

	
	alea = rand() % 4 + 1;           // Ici on veut avoir un nombre aléatoire entre 1 et 4 donc les valeur de % 4 sont égale a 0 1 2 3 on rajoute alors + 1 pour obtenir 1 2 3 4.
	if (alea == 1)
	{
		switch (fill)
		{
		case 1:
			cout << "Voici votre triangle plein de taille : " << taille << endl;      // Même principle que plus haut traiterRectangle
			dessinerTriangle1(taille, fill);
			break;
		case 2:
			cout << "Voici votre triangle vide de taille : " << taille << endl;
			dessinerTriangle1(taille, fill);
			break;
		}
	}
	if (alea == 2)                 // Comme les 3 autres on va dessiner un triangle différent dépendant qu'elle valeure on a obtenu à alea entre 1 et 4 
	{                              // Ici alea vaux 2 on va donc appeler la bonne fonction qui va dessiner le triangle 2 rempli ou vide dépendant du choix de remplissange.
		switch (fill)
		{
		case 1:
			cout << "Voici votre triangle plein de taille : " << taille << endl;
			dessinerTriangle2(taille, fill);
			break;
		case 2:
			cout << "Voici votre triangle vide de taille : " << taille << endl;
			dessinerTriangle2(taille, fill);
			break;
		}
	}
	if (alea == 3)
	{
		switch (fill)
		{
		case 1:
			cout << "Voici votre triangle plein de taille : " << taille << endl;
			dessinerTriangle3(taille, fill);
			break;
		case 2:
			cout << "Voici votre triangle vide de taille : " << taille << endl;
			dessinerTriangle3(taille, fill);
			break;
		}
	}
	if (alea == 4)
	{
		switch (fill)
		{
		case 1:
			cout << "Voici votre triangle plein de taille : " << taille << endl;
			dessinerTriangle4(taille, fill);
			break;
		case 2:
			cout << "Voici votre triangle vide de taille : " << taille << endl;
			dessinerTriangle4(taille, fill);
			break;
		}
	}
}

void traiterLosange(int fill)
{

	int taille;                           // Comme le triagle il a une taille a intégrer. Ici la taille du losange va être la largeur et la hauteur.

	cout << "Veuillez entrer la hauteur/largeur (IMPAIR) du Losange : ";
	taille = saisirEntier();                               // Rebonjour à saisirEntier

	while (taille % 2 == 0)      // Pour que le losange s'affiche d'une belle façon il faut s'assurer que l'utilisateur entre un nombre impair.
	{
		cout << "Vous devez entrer un nombre impair !!! " << endl;      // Ici on valide que l'utilisateur entre un nombre impair
		cout << "Veuillez entrer la hauteur du Losange : ";
		taille = saisirEntier(); // Hey, je te connais toi!
	}
	cout << endl;

	switch (fill)      // On appel la bonne fonction qui va dessiner le losange remplis ou vide en affichant le bon message.
	{
	case 1:
		cout << "Voici votre Losange plein de : " << taille << endl;
		dessinerLosange(taille, fill);                                       
		break;
	case 2:
		cout << "Voici votre Losange vide de : " << taille << endl;
		dessinerLosange(taille, fill);
		break;
	}
}

void dessinerRectangle(int ht, int lg, int fill)
{
	for (int rangee = 1; rangee <= ht; rangee++)               // Boucle 1. Permet de faire les rangées dépendante de ht.
	{

		for (int colonne = 1; colonne <= lg; colonne++)       // Boucle 2. Permet de compter les colonnes dépendante de lg.
		{

			switch (fill)            // Ce switch permet de remplir la forme d'espace pour vide ou de # pour remplis.
			{
			case 1:
				if (colonne > 1 && colonne < lg && rangee != 1 && rangee != ht)
				{

					cout << "#";
				}
				else
				{
					cout << "*";
				}
				break;
			case 2:
				if (colonne > 1 && colonne < lg && rangee != 1 && rangee != ht)
				{

					cout << " ";
				}
				else
				{
					cout << "*";
				}
				break;
			}
		}
		cout << endl;                        // Après que les colonne soit généré on saute de ligne pour faire la deuxième rangée


	}



}

void dessinerTriangle1(int taille, int fill)
{
	for (int rangee = 1; rangee <= taille; rangee++)     // Boucle 1. Permet de faire les rangées dépendante de taille.      Rangée commence à un et a chaque boucle on augmente de 1 donc colonne aussi.
	{                                                  // On commence petit et on grandit.
		for (int colonne = 1; colonne <= rangee; colonne++)    // Boucle 2. Permet de compter les colonnes dépendante du nombre de rangée.
		{
			switch (fill)      // Ce switch permet de remplir la forme d'espace pour vide ou de # pour remplis.
			{
			case 1:
				if (colonne > 1 && colonne < rangee && rangee != 1 && rangee != taille)      // condition de remplissage
				{
					cout << "#";
				}
				else
				{
					cout << "*";
				}

				break;
			case 2:
				if (colonne > 1 && colonne < rangee && rangee != 1 && rangee != taille)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
				break;
			}
		}

		cout << endl;

	}
}

void dessinerTriangle2(int taille, int fill)        // Même principle que triangle 1 mais à l'envers.
{
	for (int rangee = taille; rangee >= 1; rangee--)       // C'est pour ca qu' ici plus on descend on racourci rangée, car le nombre de colonne est dépendante de la valeur de rangée.
	{                                                      // On commence grand et on rétréci
		for (int colonne = 1; colonne <= rangee; colonne++)
		{
			switch (fill)       // Rempli ou vide
			{
			case 1:
				if (colonne > 1 && colonne < rangee && rangee != 1 && rangee != taille)   // Condition de remplissage 
				{
					cout << "#";
				}
				else                          // sinon on dessine le contour
				{
					cout << "*";
				}
				break;
			case 2:
				if (colonne > 1 && colonne < rangee && rangee != 1 && rangee != taille)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
				break;
			}
		}

		cout << endl;

	}
}

void dessinerTriangle3(int taille, int fill) 
{
	int nbEspace = 0;              // Il faut calculer le nombre d'espace pour générer le triangle. Ici on commence à 0 espace.


	for (int rangee = taille; rangee >= 1; rangee--)     // Boucle des rangées.
	{

		for (int colonne = 1; colonne <= taille; colonne++) // Boucle des colonnes.
		{
			switch (fill)
			{
			case 1:
				if (colonne <= nbEspace)         // Ici, à chaque fois que le nombre de colonne est plus petit que le nombre d'espace on fait un espace
				{                                // on va donc commencer sans espace et en rajouter 1 à chaque rangée.
					cout << " ";
				}
				else
				{
					if (colonne == taille || rangee == taille || colonne == nbEspace + 1)  // Condition de remplissange.
					{
						cout << "*";
					}
					else
					{
						cout << "#";
					}

				}
				break;
			case 2:

				if (colonne <= nbEspace)
				{
					cout << " ";
				}
				else
				{
					if (colonne == taille || rangee == taille || colonne == nbEspace + 1)
					{
						cout << "*";
					}
					else
					{
						cout << " ";
					}

				}


			}
		}

		cout << endl;

		nbEspace++;
	}
}

void dessinerTriangle4(int taille, int fill)
{

	int nbEspace = taille - 1;                        // On suit la même logique que le triangle3, mais à l'envers on commence avec beaucoup d'espace et on en enlève 1 à chaque rangéeé.
	for (int rangee = 1; rangee <= taille; rangee++)
	{

		for (int colonne = 1; colonne <= taille; colonne++)
		{
			switch (fill)
			{
			case 1:
				if (colonne <= nbEspace)
				{
					cout << " ";
				}
				else
				{
					if (colonne == taille || rangee == taille || colonne == nbEspace + 1)
					{
						cout << "*";
					}
					else
					{
						cout << "#";
					}
				}
				break;
			case 2:
				if (colonne <= nbEspace)
				{
					cout << " ";
				}
				else
				{
					if (colonne == taille || rangee == taille || colonne == nbEspace + 1)
					{
						cout << "*";
					}
					else
					{
						cout << " ";
					}
				}
				break;

			}

		}

		cout << endl;




		nbEspace--;
	}
}

void dessinerLosange(int taille, int fill)
{
	int milieu = taille / 2 + 1;             // On défini la valeur du milieu.
	int nbEspace = milieu - 1;              // On veut le nombre d'espace entre le milieu et le début ou la fin.
	int lg = 1;                             // Le nombre de caractère par rangée ex: rangée 1 va avoir un caractère, rangée 2 va en avoir 3, etc..

	for (int rangee = 1; rangee <= taille; rangee++)     // Boucle des rangées.
	{

		for (int colonne = 1; colonne <= taille; colonne++)      // Boucle des colonnes.
		{
			if (colonne <= nbEspace || (nbEspace + lg < colonne && colonne > milieu)) // La condition des espaces quand il en a un ou non.  
			{
				cout << " ";
			}
			else   // Si il n'a pas d'espace on met quoi ?
			{

				if (colonne == nbEspace + 1 || colonne == nbEspace + lg)    // Condition pour faire les contours.        
				{
					cout << "*";
				}
				else                       // le reste va donc être l'intérieur.
				{
					switch (fill)
					{
					case 1:

						cout << "#";

						break;
					case 2:
						cout << " ";

						break;
					}
				}
			}



		}
		cout << endl;
		if (rangee < milieu)   // à chaque fois qu'on va sauté une ligne on veut que le nombre de caractère augmente de 2 pour que les conditons plus haut fonctionne.
		{                      // Jusqu'au milieu on va enlever des espaces et ajouter 2 caractère. 
			lg = lg + 2;
			nbEspace--;
		}
		if (rangee >= milieu)       // par contre passer le milieu on veut l'effet inverse.
		{
			lg = lg - 2;
			nbEspace++;
		}


	}
}



// T4 : colonne == taille || rangee == taille || colonne == nbEspace + 1       *
// T3 : colonne == taille || rangee == taille || colonne == nbEspace + 1       *
// T2 : colonne > 1 && colonne < rangee && rangee != 1 && rangee != taille     #
// T1 : colonne > 1 && colonne < rangee && rangee != 1 && rangee != taille     #