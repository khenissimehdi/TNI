#ifndef __DYNAMIQUEEXPON_HPP__
#define __DYNAMIQUEEXPON_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class DynamiqueExpon : public plugin
{
private:
// Donnees en entree
	auto_ref<ns_wtni::GrayImage> input;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres
	int n;
	bool boolean;

public:
	DynamiqueExpon( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
