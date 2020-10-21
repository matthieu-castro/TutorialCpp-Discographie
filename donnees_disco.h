#ifndef DONNEES_DISCO_H_INCLUDED
#define DONNEES_DISCO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

struct Artiste 
{
    std::string nom;
};

struct Album 
{
    std::string nom;
};

struct Morceau
{
    std::string nom;
    Album album;
    Artiste artiste;
};

using Discographie = std::vector<Morceau>;

//Surcharge des opérateurs de stream
std::ostream & operator<<(std::ostream & sortie, Artiste const & artiste);
std::ostream & operator<<(std::ostream & sortie, Album const & album);
std::ostream & operator<<(std::ostream & sortie, Morceau const & morceau);

// Conversion d'un flux d'entrée (std::cin, chaîne, fichier) en type Morceau.
std::istream & operator>>(std::istream & entree, Morceau & morceau);

#endif