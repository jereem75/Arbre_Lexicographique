#include "dessine.h"
#ifndef ABR_H
#define ABR_H



/* Alloue l'espace necessaire pour la creation d'un noeud*/
Noeud * alloue_noeud(char *mot);

/* Reherche si un element est deja présent dans l'arbre */
Noeud *recherche(Arbre a, char *mot);

/* parcourt l'arbre et l'affiche de maniere infixe */
void parcours_infixe(Arbre A);


/* Ajoute l'element à `ensemble */
Noeud *ajout(Arbre *a,char * mot);


/* extrait le max de l'enesemble */
Noeud * extrait_max(Arbre *A);

/* supprime la racine d'un arbre */
Noeud *supp_racine(Arbre *A);

/* Supprime l'element de l'arbre */
Noeud * suppression(Arbre * A, char *mot);

/*Prend en parametre un noeud* et le libere*/
void detruit_noeud(Noeud *noeud);

/*Prend en parametre un arbre et libere la memoire allouée pour l'arbre*/
void libere(Arbre * A);

/*lit le contenu du fichier nom mot à mot et les insère successivement dans l’arbre*/
int cree_arbre(char * nom, Arbre * A);


#endif
