#include "EgaliseHisto.hpp"

using namespace ns_wtni;

EgaliseHisto::EgaliseHisto( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
	tailleFenetre = 5;
	add_param( tailleFenetre, "" );
	BooleanHisto = false;
	add_param( BooleanHisto, "" );
}


bool EgaliseHisto::is_tailleFenetre_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre tailleFenetre
	// Renseigner la variable msg si necessaire
    if(tailleFenetre >=3)
    {

    return true;
    }
    return false;
}

bool EgaliseHisto::is_BooleanHisto_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre BooleanHisto
	// Renseigner la variable msg si necessaire
	return true; 
}

bool EgaliseHisto::verifyParameters( std::string &msg, bool isRunning )
{
	//Tableau contenant les differents messages
	std::vector<std::string> msgs;
	std::string _msg; // Message local
	bool res = true;
	_msg.clear();
	if ( is_param_input( &tailleFenetre )==isRunning && ! is_tailleFenetre_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &BooleanHisto )==isRunning && ! is_BooleanHisto_set( _msg ) )
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

bool EgaliseHisto::is_ready( std::string & msg )
{
	return verifyParameters(msg, false);
}

bool EgaliseHisto::execute( std::string &msg)
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
    const GrayImage &Input= *input;

   output = input;

    for(int i=0; i<(input->height()-1);i++)
    {
        for(int j=0; j<(input->width()-1);j++)
        {
            e1::signal<long>histoCumul(256);
            for(int li = i-(tailleFenetre/2);li<i+(tailleFenetre/2);li++)
            {
                for(int co=j-(tailleFenetre/2);co<j+(tailleFenetre/2);co++)
                {
                    if(li>0 && li<input->height() && co>0 && co<input->width())
                    {
                        int ng_p = Input[li][co];
                        (histoCumul)[ng_p]+=1;
                    }
                }
            }
            for (int i=1; i<256;i++)
            {
                (histoCumul)[i] += (histoCumul)[i-1];
            }
            (*output)[i][j]=histoCumul[(*output)[i][j]]*255/(histoCumul)[255];
        }
    }




	return true; 
}

CREATE_PLUGIN( EgaliseHisto );

