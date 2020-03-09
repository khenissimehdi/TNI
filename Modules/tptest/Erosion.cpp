#include "Erosion.hpp"

using namespace ns_wtni;

Erosion::Erosion( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input, "image d'entrée" );

// Ajout des donnees en sortie
	add_output( output, "image de sortie" );
// Ajout des parametres
	taille_de_fenetre = 0;
	add_param( taille_de_fenetre, "taille de la fenetre" );
}

bool Erosion::execute( std::string &msg)
{

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! input )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}

	// ALLOUER les sorties ! TODO
	// Ecrire le code du plugin : TODO !!
    output = new GrayImage(*input);


  // Ecrire le code du plugin : TODO !!
    output = new GrayImage(*input);
       // Ecrire le code du plugin : TODO !!

       for(int x = 0 ; x<input->height(); x++)
       {
           for(int y = 0 ; y <input->width();y++)
           {
               int min = 255;
               for(int k = x-(taille_de_fenetre/2); k<=x+taille_de_fenetre/2;k++)
               {
                   for(int l = y-(taille_de_fenetre/2);l<=y+taille_de_fenetre/2;l++)
                   {
                       if(min > (*input)[k][l])
                       {
                           min  = (*input)[k][l];
                       }

                   }

               }
               (*output)[x][y]=min;
           }
       }


	return true; 
}

CREATE_PLUGIN( Erosion );

