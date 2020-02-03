#include "CoupeBande.hpp"

using namespace ns_wtni;

CoupeBande::CoupeBande( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
    add_input( input );

// Ajout des donnees en sortie
    add_output( output );
// Ajout des parametres
    n1 = 0;
    add_param( n1, "delimite la plage d'indice n1" );
    n2 = 0;
    add_param( n2, "delimite laplage d'indice n2" );
}

bool CoupeBande::execute( std::string &msg)
{

    // Tester les entrees - A COMPLETER si NECESSAIRE !
    if ( ! input )
    {
         msg = "L'entree n°0 n'est pas initialisee.";
        return false;
    }

    // ALLOUER les sorties ! TODO
    output=input;
    int size = output->size();
    if(n1>n2)
    {
        int e;
        e=n1;
        n1=n2;
        n2=e;
    }
    for (int i=0;i<size;i++)
    {
        if(i>n1 && i<n2)
        {
            (*output)[i]=0;
        }
        else if(i<(size-n1) && i>(size-n2))
        {
            (*output)[i]=0;
        }

    }
    // Ecrire le code du plugin : TODO !!

    return true;
}

CREATE_PLUGIN( CoupeBande );

