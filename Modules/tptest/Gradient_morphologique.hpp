#ifndef __GRADIENT_MORPHOLOGIQUE_HPP__
#define __GRADIENT_MORPHOLOGIQUE_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class Gradient_morphologique : public plugin
{
private:
// Donnees en entree
	const_auto_ref<ns_wtni::GrayImage> input1;
	const_auto_ref<ns_wtni::GrayImage> input2;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres

public:
	Gradient_morphologique( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
