#ifndef __EROSION_HPP__
#define __EROSION_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class Erosion : public plugin
{
private:
// Donnees en entree
	const_auto_ref<ns_wtni::GrayImage> input;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres
	int taille_de_fenetre;

public:
	Erosion( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
