#include "DynamiqueLineaire.hpp"

using namespace ns_wtni;

DynamiqueLineaire::DynamiqueLineaire( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
	a = 20;
	add_param( a, "" );
	b = 35;
	add_param( b, "" );
	rehaussement = true;
	add_param( rehaussement, "" );
}


bool DynamiqueLineaire::is_a_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre a
	// Renseigner la variable msg si necessaire
	return true; 
}

bool DynamiqueLineaire::is_b_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre b
	// Renseigner la variable msg si necessaire
	return true; 
}

bool DynamiqueLineaire::is_rehaussement_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre rehaussement
	// Renseigner la variable msg si necessaire
	return true; 
}

bool DynamiqueLineaire::verifyParameters( std::string &msg, bool isRunning )
{
	//Tableau contenant les differents messages
	std::vector<std::string> msgs;
	std::string _msg; // Message local
	bool res = true;
	_msg.clear();
	if ( is_param_input( &a )==isRunning && ! is_a_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &b )==isRunning && ! is_b_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &rehaussement )==isRunning && ! is_rehaussement_set( _msg ) )
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

bool DynamiqueLineaire::is_ready( std::string & msg )
{
	return verifyParameters(msg, false);
}

bool DynamiqueLineaire::execute( std::string &msg)
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

	// ALLOUER les sorties ! TODO
	// Ecrire le code du plugin : TODO !!

	return true; 
}

CREATE_PLUGIN( DynamiqueLineaire );

