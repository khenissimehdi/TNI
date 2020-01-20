#include "ReduireDynamique.hpp"

using namespace ns_wtni;

ReduireDynamique::ReduireDynamique( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
	dynamic = 7;
	add_param( dynamic, "" );
}


bool ReduireDynamique::is_dynamic_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre dynamic
    if(dynamic > 0 && dynamic <= 7)
    {
        return true;
    }
    msg=" valeur correcte";
	// Renseigner la variable msg si necessaire
    return false;
}

bool ReduireDynamique::verifyParameters( std::string &msg, bool isRunning )
{
	//Tableau contenant les differents messages
	std::vector<std::string> msgs;
	std::string _msg; // Message local
	bool res = true;
	_msg.clear();
	if ( is_param_input( &dynamic )==isRunning && ! is_dynamic_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	if ( msgs.size()==1 ) msg = msgs.front();
	else if ( msgs.size()>1 )
	{
		msg = "<ul>";
		for (unsigned int i=0; i<msgs.size(); ++i)
			msg += "<li>" + msgs[i] + "</li>";
		msg += "</ul>";
	}
	return res;
}

bool ReduireDynamique::is_ready( std::string & msg )
{
	return verifyParameters(msg, false);
}

bool ReduireDynamique::execute( std::string &msg)
{
	//Tester les parametres
	if ( !verifyParameters( msg, true ) ) 
		return false;

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! input )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}
    output = input;
    for(int i=1;i<input->height();i++)
    {
        for(int j=1;j< input->width();j++)
        {

              (*output)[i][j]>>=(8-dynamic);
              (*output)[i][j]<<=(8-dynamic);
        }

    }

	// ALLOUER les sorties ! TODO
	// Ecrire le code du plugin : TODO !!

	return true; 
}

CREATE_PLUGIN( ReduireDynamique );

