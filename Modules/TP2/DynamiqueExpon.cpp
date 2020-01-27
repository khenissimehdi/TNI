#include "DynamiqueExpon.hpp"

using namespace ns_wtni;

DynamiqueExpon::DynamiqueExpon( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
	n = 1;
    add_param( n, "entier n" );
	boolean = true;
    add_param( boolean, "boolean " );
}

bool DynamiqueExpon::execute( std::string &msg)
{

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! input )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}

	// ALLOUER les sorties ! TODO
	// Ecrire le code du plugin : TODO !!
    for(int i = 0; i<input->height();i++){
       for(int j = 0; j<input->width();j++)
       {
           int d = (*output)[i][j];
           if (boolean)
           {

              d= pow(d/255.0,n) *255;
           }
           else{
               d=pow(d/255.0,1.0/n)*255;
             }
                    (*output)[i][j]=d;
       }


	return true; 
}
}

CREATE_PLUGIN( DynamiqueExpon );

