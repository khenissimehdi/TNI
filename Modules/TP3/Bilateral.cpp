#include "Bilateral.hpp"

using namespace ns_wtni;

Bilateral::Bilateral( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
   add_input(input);
// Ajout des donnees en sortie
    add_output(output);
// Ajout des parametres
	taille_voisinage = 3;
	add_param( taille_voisinage, "taille_voisinage" );
	ecart_type_de_la_gaussienne_spatiale = 0.5;
	add_param( ecart_type_de_la_gaussienne_spatiale, "ecart_type_de_la_gaussienne_spatiale" );
	ecart_type_de_la_gaussienne_parametrige = 0.5;
	add_param( ecart_type_de_la_gaussienne_parametrige, "ecart_type_de_la_gaussienne_parametrige" );
}


bool Bilateral::is_taille_voisinage_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre taille_voisinage
	// Renseigner la variable msg si necessaire
	return true; 
}

bool Bilateral::is_ecart_type_de_la_gaussienne_spatiale_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre ecart_type_de_la_gaussienne_spatiale
	// Renseigner la variable msg si necessaire
	return true; 
}

bool Bilateral::is_ecart_type_de_la_gaussienne_parametrige_set( std::string &msg )
{
	// Ajouter les tests a faire sur le parametre ecart_type_de_la_gaussienne_parametrige
	// Renseigner la variable msg si necessaire
	return true; 
}

bool Bilateral::verifyParameters( std::string &msg, bool isRunning )
{
	//Tableau contenant les differents messages
	std::vector<std::string> msgs;
	std::string _msg; // Message local
	bool res = true;
	_msg.clear();
	if ( is_param_input( &taille_voisinage )==isRunning && ! is_taille_voisinage_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &ecart_type_de_la_gaussienne_spatiale )==isRunning && ! is_ecart_type_de_la_gaussienne_spatiale_set( _msg ) )
	{
		 res = false;
		 msgs.push_back( _msg );
	}
	_msg.clear();
	if ( is_param_input( &ecart_type_de_la_gaussienne_parametrige )==isRunning && ! is_ecart_type_de_la_gaussienne_parametrige_set( _msg ) )
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

bool Bilateral::is_ready( std::string & msg )
{
	return verifyParameters(msg, false);
}

bool Bilateral::execute( std::string &msg)
{
	//Tester les parametres
	if ( !verifyParameters( msg, true ) ) 
		return false;

	// ALLOUER les sorties ! TODO
    output = new GrayImage(*input);
    //output = new GrayImage(input->wi);
	// Ecrire le code du plugin : TODO !!
    int dec = taille_voisinage*2/5;
    for(int i = dec ; i<output->height()-dec;i++)
    {
        for(int j = dec ; j<output->width()-dec;j++)
        {

            for(int k = i-dec ; k<=i+dec;k++)
            {
                double s1 = 0.0;
                double s2 = 0.0;
                for(int l = j-dec ; l<=j+dec;l++)
                {
                    double u1 = sqrt(pow((i-k),2)+pow((j-l),2));
                    double u2  = (*input)[k][l]-(*input)[i][j];
                    double f1 = exp(-(pow(u1,2))/(2*ecart_type_de_la_gaussienne_spatiale));
                    double f2 = exp(-(pow(u2,2))/(2*ecart_type_de_la_gaussienne_spatiale));
                    s1+=f1*f2*(*input)[k][l];
                    s2+=f1*f2;



                }
                (*output)[i][j]=s1/s2;

            }

        }

    }

	return true; 
}

CREATE_PLUGIN( Bilateral );

