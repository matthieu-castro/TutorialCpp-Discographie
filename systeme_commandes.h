#ifndef SYSTEME_COMMANDES_H_INCLUDED
#define SYSTEME_COMMANDES_H_INCLUDED

#include "donnees_disco.h"

#include <string>
#include <tuple>

//Système de commandes
enum class Commande { Afficher, Ajouter, Enregistrer, Charger, Quitter };

std::string recuperer_commande();
std::tuple<Commande, std::string> analyser_commande(std::string const & commande_texte);
bool executer_commande(Discographie & discographie, Commande commande, std::string const & instructions);

#endif