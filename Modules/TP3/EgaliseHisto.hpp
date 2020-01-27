#ifndef __EGALISEHISTO_HPP__
#define __EGALISEHISTO_HPP__

#include <string>

#include <plugin.hpp>
#include <w_signal2d.hpp>

class EgaliseHisto : public plugin
{
private:
// Donnees en entree
	auto_ref<ns_wtni::GrayImage> input;
// Donnees en sortie
	auto_ref<ns_wtni::GrayImage> output;
// Parametres
	int tailleFenetre;
	bool BooleanHisto;

	bool verifyParameters(std::string &msg, bool isRunning);

public:
	EgaliseHisto( pluglink * p );

	bool is_tailleFenetre_set( std::string &msg );
	bool is_BooleanHisto_set( std::string &msg );

	virtual bool is_ready( std::string & );

	virtual bool execute( std::string & );
};

#endif
