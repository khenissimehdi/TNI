#include "DivResolution.hpp"

using namespace ns_wtni;

DivResolution::DivResolution( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
	n_x = 2;
	add_param( n_x, "" );
	n_y = 2;
	add_param( n_y, "" );
}

bool DivResolution::execute( std::string &msg)
{

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! input )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}

	// ALLOUER les sorties ! TODO
	// Ecrire le code du plugin : TODO !!
    // ALLOUER les sorties ! TODO
    output = new GrayImage(input->width()/n_x,input->height()/ n_y);
    // Ecrire le code du plugin : TODO !!
    for(int i = 0; i<input->height(); i++){
        if(i%n_y <= 0){
            for(int j = 0; j<input->width(); j++){
                if(j%n_x <= 0){
                    (*output)[i/n_y][j/n_x]=(*input)[i][j];
                }
            }
        }

}

	return true; 
}

CREATE_PLUGIN( DivResolution );

