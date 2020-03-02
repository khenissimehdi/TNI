#ifndef __BILATERAL_HPP__
#define __BILATERAL_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class Bilateral : public plugin
{
private:
// Donnees en entree
    auto_ref<ns_wtni::GrayImage> input;
// Donnees en sortie
    auto_ref<ns_wtni::GrayImage> output;
// Parametres
	int taille_voisinage;
	double ecart_type_de_la_gaussienne_spatiale;
	double ecart_type_de_la_gaussienne_parametrige;

	bool verifyParameters(std::string &msg, bool isRunning);

public:
	Bilateral( pluglink * p );

	bool is_taille_voisinage_set( std::string &msg );
	bool is_ecart_type_de_la_gaussienne_spatiale_set( std::string &msg );
	bool is_ecart_type_de_la_gaussienne_parametrige_set( std::string &msg );

	virtual bool is_ready( std::string & );

	virtual bool execute( std::string & );
};

#endif
