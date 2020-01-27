#include "HistoCumul.hpp"

using namespace ns_wtni;

HistoCumul::HistoCumul( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( histo, "histogramme cumulé" );
// Ajout des parametres
}

bool HistoCumul::execute( std::string &msg)
{
    if ( ! input )
    {
         msg = "L'entree n°1 n'est pas initialisee.";
        return false;
    }


	// Tester les entrees - A COMPLETER si NECESSAIRE !
   const GrayImage & In = *input;
  int largeur = In.width();
  int hauteur = In.height();
	// ALLOUER les sorties ! TODO
    histo = new e1::signal <long>(256);
    e1::signal<long> & Out = *histo ;

	// Ecrire le code du plugin : TODO !!

    for(int li=0; li<In.height(); li ++){
        for(int co=0; co<In.width();co++){
            int pix = In[li][co];
            (*histo)[pix]++;


        }

    }
    for(int i = 1; i < 256;i++)
    {

          (*histo)[i]= (*histo)[i-1] + (*histo)[i]  ;

    }

	return true; 
}

CREATE_PLUGIN( HistoCumul );

