#ifndef __DIVRESOLUTION_HPP__
#define __DIVRESOLUTION_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class DivResolution : public plugin
{
private:
// Donnees en entree
	const_auto_ref<ns_wtni::GrayImage> input;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres
	int n_x;
	int n_y;

public:
	DivResolution( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
