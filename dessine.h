#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef DESSINE
#define DESSINE


/* Type alias */
typedef struct noeud {
    char * mot;
    struct noeud *fg;
    struct noeud *fd;
} Noeud, *Arbre;



/*
Fonction qui prend en parametre un fichier .dot et un Arbre.
La fonction écrit le code permettant de dessiner l'arbre.
*/
void creeDOT(FILE *out, Arbre a);


/*
Fonction qui prend en parametre 2 chaines de caracteres et un arbre.
dot est le nom du fichier en format .dot ou sera écrit le code permetant
de dessiner l'arbre. Le dessin ser disponible dans le fichier pdf.
*/
void dessine(char *pdf, Arbre a);


#endif
