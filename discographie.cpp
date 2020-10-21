#include "discographie.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>


void enregister(Discographie const & discographie, std::string const & nom_fichier)
{
    std::ofstream fichier {nom_fichier};
    if (!fichier)
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier en écriture.");
    }
    
    for (Morceau const & morceau : discographie)
    {
        fichier << morceau << std::endl;
    }
}

void charger(Discographie & discographie, std::string const & nom_fichier)
{
    std::ifstream fichier {nom_fichier};
    if (!fichier)
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier en lecture.");
    }
    
    std::string ligne {};
    while (std::getline(fichier,ligne))
    {
        Morceau morceau {};
        
        std::istringstream flux { ligne };
        flux >> morceau;
        
        discographie.push_back(morceau);
    }
}

void tri_morceau(Discographie& discographie)
{
    std::sort(std::begin(discographie), std::end(discographie), [](Morceau const & lhs, Morceau const & rhs) 
    {
        return lhs.nom < rhs.nom;    
    });
}

void tri_album(Discographie& discographie)
{
    std::sort(std::begin(discographie), std::end(discographie), [](Morceau const & lhs, Morceau const & rhs) 
    {
        if (lhs.album.nom < rhs.album.nom)
            return true;    
        
        return lhs.album.nom == rhs.album.nom && lhs.nom < rhs.nom;
    });   
}

void tri_artiste(Discographie& discographie)
{
    std::sort(std::begin(discographie), std::end(discographie), [](Morceau const & lhs, Morceau const & rhs) 
    {
        if (lhs.artiste.nom < rhs.artiste.nom)
            return true;    
        
        if (lhs.artiste.nom == rhs.artiste.nom)
        {
            if (lhs.album.nom < rhs.album.nom)
                return true; 
                
            return lhs.album.nom == rhs.album.nom && lhs.nom < rhs.nom;
        }
        
        return false;
    });  
}

void afficher_morceau(Discographie const & discographie)
{
    for (Morceau const & morceau : discographie)
    {
        std::cout << "-->" << morceau << std::endl;
    }
}

void afficher_album(Discographie const & discographie)
{
    Album album_precedent {};
    
    for (Morceau const & morceau : discographie)
    {
        if (morceau.album.nom != album_precedent.nom)
        {
            std::cout << "-->" << morceau.album << " | " << morceau.artiste << std::endl;
        }
        std::cout << "\t-->" << morceau.nom << std::endl;
        
        album_precedent = morceau.album;
    }
}

void afficher_artiste(Discographie const & discographie)
{
    Artiste artiste_precedent;
    Album album_precedent;
    
    for (Morceau const & morceau : discographie)
    {
        if (morceau.artiste.nom != artiste_precedent.nom)
        {
            std::cout << "-->" << morceau.artiste << std::endl;
        }
        
        if (morceau.album.nom != album_precedent.nom)
        {
            std::cout << "\t-->" << morceau.album << std::endl;
        }
        
        std::cout << "\t\t-->" << morceau.nom << std::endl;
        
        artiste_precedent = morceau.artiste;
        album_precedent = morceau.album;
    }
}

void affichage(Discographie & discographie, Affichage type_affichage)
{
    if (type_affichage == Affichage::Album)
    {
        tri_album(discographie);
        afficher_album(discographie);
    }
    else if (type_affichage == Affichage::Artiste)
    {
        tri_artiste(discographie);
        afficher_artiste(discographie);
    }
    else if (type_affichage == Affichage::Morceau)
    {
        tri_morceau(discographie);
        afficher_morceau(discographie);
    }
    else
    {
            throw std::runtime_error("Commande d'affichage inconnue.");
    }
}