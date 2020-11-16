#include "saisir1605269.h"
using namespace std;
#include <iostream>
#include <string>


int saisirEntier()
{

    string clavier;

    getline(cin, clavier, '\n');                     // Le string et le getline permet au programme de prendre plusieurs entr�es de clavier sans faire planter le programme.
                                                     // Ici il est possible � clavier de recevoir plus d'un caract�re.


    while (!(!clavier.empty() && ((clavier.front() >= '0' && clavier.front() <= '9')             // Boucle de condition qui si l'utilisateur �crit rien, un nombre n�gatif, une lettre 
                                                                                                 // et meme plusieurs caract�res, la boucle redemandera de r��crire, jusqu'� la r�ponse souhait�e.
        || (clavier.length() > 1 && clavier.front() == '-' && clavier.at(1) >= '0' && clavier.at(1) <= '9'))))
    {
        cout << "Erreur: Vous devez taper un chiffre!!" << endl;
        cout << "Veuillez entrer un chiffre : ";
        getline(cin, clavier, '\n');                                
                                                                    
    }


    return stoi(clavier);        // stoi transition une valeure string sous forme d'entier (int) parce que saisirEntier est un int donc on doit retourner un int et non pas un string.
}
