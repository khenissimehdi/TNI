#ifndef __NAGAO_HPP__
#define __NAGAO_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class nagao : public plugin
{
private:
// Donnees en entree
	auto_ref<ns_wtni::GrayImage> input;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres

public:
	nagao( pluglink * p );

	virtual bool execute( std::string & );
};

#endif
