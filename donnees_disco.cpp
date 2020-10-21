#include "donnees_disco.h"
#include "utils.h"

#include <sstream>

std::ostream & operator<<(std::ostream & sortie, Artiste const & artiste)
{
    sortie << artiste.nom;
    return sortie;
}

std::ostream & operator<<(std::ostream & sortie, Album const & album)
{
    sortie << album.nom;
    return sortie;
}

std::ostream & operator<<(std::ostream & sortie, Morceau const & morceau)
{
    sortie << morceau.nom << " | " << morceau.album << " | " << morceau.artiste;
    return sortie;
}

std::istream & operator>>(std::istream & entree, Morceau & morceau)
{
    std::string mot {};
    std::ostringstream flux {};
    
    //Nom du morceau
    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }
    
    std::string nom_morceau { flux.str() };
    if (std::empty(nom_morceau))
    {
        nom_morceau = "Morceau inconnu";
    }
    morceau.nom = traitement_chaine(nom_morceau);
    flux.str(std::string {});
    
    //Nom de l'album
    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }
    
    std::string nom_album { flux.str() };
    if (std::empty(nom_album))
    {
        nom_album = "Album inconnu";
    }
    morceau.album.nom = traitement_chaine(nom_album);
    flux.str(std::string {});
    
    //Nom de l'artiste
    while (entree >> mot )
    {
        flux << mot << " ";
    }
    
    std::string nom_artiste { flux.str() };
    if (std::empty(nom_artiste))
    {
        nom_artiste = "Artiste inconnu";
    }
    morceau.artiste.nom = traitement_chaine(nom_artiste);
    flux.str(std::string {});
    
    return entree;
}
