#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dessine.h"



/*
Fonction qui prend en parametre un fichier .dot et qui écrit le début 
permettant de dessiner un arbre.
*/
void ecrireDebut(FILE *out);


/*
Fonction qui prend en parametre un fichier .dot et qui écrit la fin
permettant de dessiner un arbre.
*/
void ecrireFin(FILE *out);


/*
Fonction qui prend en parametre un fichier .dot et un arbre. Elle 
écrit les lignes permettant de construire l'arbre.
*/
void ecrireArbre(FILE *out, Arbre a);



void ecrireDebut(FILE *out){
    fprintf(out, "digraph arbre {\n");
    fprintf(out, "    node [shape = record , height = .1]\n");
    fprintf(out, "    edge [tailclip = false , arrowtail = dot , dir = both];\n");
}

void ecrireFin(FILE *out){
    fprintf(out, "}\n");
}


void ecrireArbre(FILE *out, Arbre a){
    if (a == NULL){
        return ;
    }
    fprintf(out, "    n%p [label = \"<gauche> | <valeur> %s | <droit>\"];\n", a, a->mot);
    if (a->fg != NULL){
        fprintf(out, "    n%p : gauche : c -> n%p : valeur;\n", a, a->fg);
        ecrireArbre(out, a->fg);
    }
    if (a->fd != NULL){
        fprintf(out, "    n%p : droit : c -> n%p : valeur;\n", a, a->fd);
        ecrireArbre(out, a->fd);
    }
}


void creeDOT(FILE *out, Arbre a){
    ecrireDebut(out);
    ecrireArbre(out, a);
    ecrireFin(out);
}

void dessine(char *pdf, Arbre a){
    int taille = strlen(pdf) + 4;
    char dot[taille];
    strcpy(dot, pdf);
    strcat(dot, ".dot");
    FILE *out = fopen(dot, "w");
    creeDOT(out, a);
    fclose(out);
    int len = strlen(dot) + strlen(pdf) + 19;
    char cmd[len];
    strcpy(cmd, "dot -Tpdf " );
    strcat(cmd, dot);
    strcat(cmd, " -o ");
    strcat(cmd, pdf);
    strcat(cmd, ".pdf");
    system(cmd);
}
