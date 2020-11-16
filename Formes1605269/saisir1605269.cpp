#include "saisir1605269.h"
using namespace std;
#include <iostream>
#include <string>


int saisirEntier()
{

    string clavier;

    getline(cin, clavier, '\n');                     // Le string et le getline permet au programme de prendre plusieurs entrées de clavier sans faire planter le programme.
                                                     // Ici il est possible à clavier de recevoir plus d'un caractère.


    while (!(!clavier.empty() && ((clavier.front() >= '0' && clavier.front() <= '9')             // Boucle de condition qui si l'utilisateur écrit rien, un nombre négatif, une lettre 
                                                                                                 // et meme plusieurs caractères, la boucle redemandera de réécrire, jusqu'à la réponse souhaitée.
        || (clavier.length() > 1 && clavier.front() == '-' && clavier.at(1) >= '0' && clavier.at(1) <= '9'))))
    {
        cout << "Erreur: Vous devez taper un chiffre!!" << endl;
        cout << "Veuillez entrer un chiffre : ";
        getline(cin, clavier, '\n');                                
                                                                    
    }


    return stoi(clavier);        // stoi transition une valeure string sous forme d'entier (int) parce que saisirEntier est un int donc on doit retourner un int et non pas un string.
}
