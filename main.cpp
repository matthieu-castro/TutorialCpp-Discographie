#include "utils.h"
#include "donnees_disco.h"
#include "tests.h"
#include "discographie.h"
#include "systeme_commandes.h"

#include <stdexcept>

int main() {
    
    //Lancement préalable des tests unitaires
    test_creation_morceau_entree_complete();
    test_creation_morceau_entree_espaces();
    test_creation_morceau_entree_chanson_artiste();
    test_creation_morceau_entree_chanson_uniquement();
    test_creation_morceau_entree_vide();
    
    Discographie discographie {};
    bool continuer {true};
    
    do
    {
        try
        {
            std::string entree { recuperer_commande() };
            auto[commande, instructions] = analyser_commande(entree);
            instructions = traitement_chaine(instructions);
            continuer = executer_commande(discographie, commande, instructions);
        }
        catch (std::runtime_error const & exception)
        {
            std::cout << "Erreur: " << exception.what() << std::endl;
        }
    } while (continuer);
        
	return 0;
}