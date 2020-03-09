#include "Gradient_morphologique.hpp"

using namespace ns_wtni;

Gradient_morphologique::Gradient_morphologique( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input1, "premiere image d'entrée" );
	add_input( input2, "deuxieme image d'entrée" );

// Ajout des donnees en sortie
	add_output( output, "image de sortie" );
// Ajout des parametres
}

bool Gradient_morphologique::execute( std::string &msg)
{

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! input1 )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}
	if ( ! input2 )
	{
		 msg = "L'entree n°1 n'est pas initialisee.";
		return false;
	}

	// ALLOUER les sorties ! TODO
     output = new GrayImage(*input1);
	// Ecrire le code du plugin : TODO !!

    for(int i = 0 ; i<input1->height(); i++)
    {
        for(int j = 0 ; j <input1->width();j++)
        {
            (*output)[i][j] = (*input1)[i][j]-(*input2)[i][j];
        }
     }

	return true; 
}

CREATE_PLUGIN( Gradient_morphologique );

