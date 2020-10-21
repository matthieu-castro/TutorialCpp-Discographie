#ifndef DISCOGRAPHIE_H_INCLUDED
#define DISCOGRAPHIE_H_INCLUDED

#include "donnees_disco.h"
#include <string>

//Enregister et charger fichiers
void enregister(Discographie const & discographie, std::string const & nom_fichier);
void charger(Discographie & discographie, std::string const & nom_fichier);

//Tri et Affichage
void tri_morceau(Discographie& discographie);
void tri_album(Discographie& discographie);
void tri_artiste(Discographie& discographie);

void afficher_morceau(Discographie const & discographie);
void afficher_album(Discographie const & discographie);
void afficher_artiste(Discographie const & discographie);

enum class Affichage { Artiste, Album, Morceau };

void affichage(Discographie & discographie, Affichage type_affichage);


#endif