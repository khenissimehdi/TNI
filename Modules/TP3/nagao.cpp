#include "nagao.hpp"

using namespace ns_wtni;

nagao::nagao( pluglink *p ) : plugin(p)
{
// Ajout des donnees en entree
	add_input( input );

// Ajout des donnees en sortie
	add_output( output );
// Ajout des parametres
}
/*---
 *  Numerotation des pixels dans la fenetre 5 x 5
 *
 *  +----+----+----+----+----+
 *  |  0 |  1 |  2 |  3 |  4 |
 *  +----+----+----+----+----+
 *  |  5 |  6 |  7 |  8 |  9 |
 *  +----+----+----+----+----+
 *  | 10 | 11 | 12 | 13 | 14 |
 *  +----+----+----+----+----+
 *  | 15 | 16 | 17 | 18 | 19 |
 *  +----+----+----+----+----+
 *  | 20 | 21 | 22 | 23 | 24 |
 *  +----+----+----+----+----+
 *
 *  9 fenÃªtres de Nagao : NumÃ©rotation
 *
 *  +-------+
 *  |\     /|
 *  | \ 0 / |
 *  |  \ /  |
 *  | 3 X 1 |
 *  |  / \  |
 *  | / 2 \ |
 *  |/     \|
 *  +-------+
 *
 *  +-------+
 *  | 4 | 5 |
 *  +---+---+
 *  | 6 | 7 |
 *  +---+---+
 *
 *  +-------+
 *  |       |
 *  | +---+ |
 *  | | 8 | |
 *  | +---+ |
 *  |       |
 *  +-------+
 *
 * Table de correspondance entre les pixels ( 0 - 24 )
 * et les 9 fenetres de Nagao ( 0 - 8 )
 * Format d'une ligne : nombre de fenetre, nÂ° fenetre 1, nÂ° fenetre 2, ... nÂ° fenetre nb
 */
static int lk_up[25][10] = { { 3, 0, 3, 4 }, // pixel 0
                             { 2, 0, 4 }, // pixel 1
                             { 3, 0, 4, 5 }, // pixel 2
                             { 2, 0, 5 }, // pixel 3
                             { 3, 0, 1, 5 }, // pixel 4
                             { 2, 3, 4 }, // pixel 5
                             { 4, 0, 3, 4, 8 }, // pixel 6
                             { 4, 0, 4, 5, 8 }, // pixel 7
                             { 4, 0, 1, 5, 8 }, // pixel 8
                             { 2, 1, 5 }, // pixel 9
                             { 3, 3, 4, 6 }, // pixel 10
                             { 4, 3, 4, 6, 8 }, // pixel 11
                             { 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 }, // pixel 12
                             { 4, 1, 5, 7, 8 }, // pixel 13
                             { 3, 1, 5, 7 }, // pixel 14
                             { 2, 3, 6 }, // pixel 15
                             { 4, 2, 3, 6, 8 }, // pixel 16
                             { 4, 2, 6, 7, 8 }, // pixel 17
                             { 4, 1, 2, 7, 8 }, // pixel 18
                             { 2, 1, 7 }, // pixel 19
                             { 3, 2, 3, 6 }, // pixel 20
                             { 2, 2, 6 }, // pixel 21
                             { 3, 2, 6, 7 }, // pixel 22
                             { 2, 2, 7 }, // pixel 23
                             { 3, 1, 2, 7 } }; // pixel 24
bool nagao::execute( std::string &msg)
{

	// Tester les entrees - A COMPLETER si NECESSAIRE !
	if ( ! input )
	{
		 msg = "L'entree n°0 n'est pas initialisee.";
		return false;
	}

	// ALLOUER les sorties ! TODO
     output = new GrayImage(*input);
	// Ecrire le code du plugin : TODO !!
     for(int i = 2 ; i < output->height()-2;i++)
     {
         for(int j = 2 ; j < output->width()-2;j++)
         {
            int tableau[25];
            int tab = 0;
            double *moy = new double[9];
            double *var = new double[9];
            for(int k = 0 ; k<25;k++)
            {
                 int i2 = (i-2) + (k%5);
                 int j2 = (j-2) + (k/5);
                for(int l = 1; l < lk_up[k][0]; l++)
                {

                }
            }

         }
     }


	return true; 
}

CREATE_PLUGIN( nagao );

