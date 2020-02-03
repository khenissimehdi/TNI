#ifndef __COUPEBANDE_HPP__
#define __COUPEBANDE_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal1d.hpp>

class CoupeBande : public plugin
{
private:
// Donnees en entree
	auto_ref<ns_wtni::e1::signal<double> > input;
// Donnees en sortie
	auto_ref<ns_wtni::e1::signal<double> > output;
// Parametres
	int n1;
	int n2;

public:
	CoupeBande( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
