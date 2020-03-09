#include "Dilatation.hpp"

using namespace ns_wtni;

Dilatation::Dilatation( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( Input, "image d'entrée" );

// Ajout des donnees en sortie
	add_output( output, "image de sortie" );
// Ajout des parametres
	taille_de_fenetre = 0;
	add_param( taille_de_fenetre, "taille de fenetre" );
}

bool Dilatation::execute( std::string &msg)
{

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! Input )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}

	// ALLOUER les sorties ! TODO
      output = new GrayImage(*Input);


	// Ecrire le code du plugin : TODO !!
      output = new GrayImage(*Input);
         // Ecrire le code du plugin : TODO !!

         for(int x = 0 ; x<Input->height(); x++)
         {
             for(int y = 0 ; y <Input->width();y++)
             {
                 int max = 0;
                 for(int k = x-(taille_de_fenetre/2); k<=x+taille_de_fenetre/2;k++)
                 {
                     for(int l = y-(taille_de_fenetre/2);l<=y+taille_de_fenetre/2;l++)
                     {
                         if(max < (*Input)[k][l])
                         {
                             max  = (*Input)[k][l];
                         }

                     }

                 }
                 (*output)[x][y]=max;
             }
         }

	return true; 
}

CREATE_PLUGIN( Dilatation );

