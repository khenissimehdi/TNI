#ifndef __DILATATION_HPP__
#define __DILATATION_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class Dilatation : public plugin
{
private:
// Donnees en entree
	const_auto_ref<ns_wtni::GrayImage> Input;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres
	int taille_de_fenetre;

public:
	Dilatation( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
