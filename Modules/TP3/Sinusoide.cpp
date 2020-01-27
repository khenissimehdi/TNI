#include "Sinusoide.hpp"

using namespace ns_wtni;

Sinusoide::Sinusoide( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
	f1 = 0.4;
	add_param( f1, "" );
	f2 = 0.3;
	add_param( f2, "" );
	N = 256;
	add_param( N, "nombre d'echantillons" );
}


bool Sinusoide::is_f1_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre f1
	// Renseigner la variable msg si necessaire
	return true; 
}

bool Sinusoide::is_f2_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre f2
	// Renseigner la variable msg si necessaire
	return true; 
}

bool Sinusoide::is_N_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre N
	// Renseigner la variable msg si necessaire
	return true; 
}

bool Sinusoide::verifyParameters( std::string &msg, bool isRunning )
{
	//Tableau contenant les differents messages
	std::vector<std::string> msgs;
	std::string _msg; // Message local
	bool res = true;
	_msg.clear();
	if ( is_param_input( &f1 )==isRunning && ! is_f1_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &f2 )==isRunning && ! is_f2_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &N )==isRunning && ! is_N_set( _msg ) )
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

bool Sinusoide::is_ready( std::string & msg )
{
	return verifyParameters(msg, false);
}

bool Sinusoide::execute( std::string &msg)
{
	//Tester les parametres
	if ( !verifyParameters( msg, true ) ) 
		return false;

	// ALLOUER les sorties ! TODO
	// Ecrire le code du plugin : TODO !!

	return true; 
}

CREATE_PLUGIN( Sinusoide );

