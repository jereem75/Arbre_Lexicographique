#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOC 512
#include "ABR.h"
#include "dessine.h"




Noeud * alloue_noeud(char * mot){
    Noeud * n = (Noeud *) malloc(sizeof(Noeud));
    if (n){
        n->mot =(char*)malloc(strlen(mot)+1);
        strcpy(n->mot,mot);
        }
        n->fg = n->fd = NULL;
    return n;
}




void parcours_infixe(Arbre A){
    if( A == NULL){
        return;
    }
    parcours_infixe(A->fg);
    printf("%s\n", A->mot);
    parcours_infixe(A->fd);
}




Noeud *recherche(Arbre a, char *mot){
    if (a == NULL){
        return NULL;
    }
    if (strcmp(a->mot, mot) == 0){
        return a;
    }
    if (strcmp(a->mot, mot) > 0){
        return recherche(a->fg, mot);
    }
    return recherche(a->fd, mot);
}



Noeud *ajout(Arbre *a,char * mot){
    if (*a == NULL){
        *a = alloue_noeud(mot);
        return *a;
    }
    //Noeud *rech = recherche(*a, mot);
    if (strcmp((*a)->mot , mot) == 0){
        return *a;
    }
    else if( strcmp((*a)->mot , mot) > 0){
        return ajout(&(*a)->fg, mot);
    }
    return ajout(&(*a)->fd, mot);
}



Noeud * extrait_max(Arbre *A){
    /* Renvoie l'adresse du noeud contenant l'etiquette maximale */
    if (*A == NULL){
        return NULL;
    }
    if ((*A)->fd == NULL) {
        Noeud *sup = *A;
        *A = (*A)->fg;
        return sup;
    }
    if ((*A)->fd->fd == NULL) {
        Noeud *sup = (*A)->fd;
        (*A)->fd = sup->fg;
        return sup;
    }
    return extrait_max(&((*A)->fd));
}




Noeud *supp_racine(Arbre *A) {
    Noeud *sup = *A;
    if (sup->fd == NULL) {
        *A = sup->fg;
    }
    else if (sup->fg == NULL) {
        *A = sup->fd;
    }
    else {
        Noeud *max = extrait_max(&(*A)->fg);
        max->fg = sup->fg;
        max->fd = sup->fd;
        *A = max;
    }
    return sup;
}



Noeud *suppression(Arbre *A, char *mot) {
    if (*A == NULL) {
        return NULL;
    }
    if (strcmp((*A)->mot, mot) == 0) {
        return supp_racine(A);
    }
    //si le noeud se trouve à droite
    if ((*A)->fd != NULL && strcmp((*A)->fd->mot, mot) == 0) {
        Arbre change = (*A)->fd;
        Noeud *sup = supp_racine(&change);
        (*A)->fd = change;
        return sup;
    }
    //si le noeud se trouve à gauche
    if ((*A)->fg != NULL && strcmp((*A)->fg->mot, mot) == 0) {
        Arbre change = (*A)->fg;
        Noeud *sup = supp_racine(&change);
        (*A)->fg = change;
        return sup;
    }
    if (strcmp((*A)->mot, mot) > 0){
        return suppression(&((*A)->fg), mot);
    }
    return suppression(&((*A)->fd), mot);
}



void detruit_noeud(Noeud *noeud) {
    free(noeud->mot);
    free(noeud);
}


void libere(Arbre * A){
    if (*A != NULL) {
        libere(&(*A)->fg);
        libere(&(*A)->fd);
        detruit_noeud(*A);
        *A = NULL;
    }
}





int cree_arbre(char * nom, Arbre * A){
    char phrase[BLOC];
    char *mot;
    FILE *fich;
    fich = fopen(nom,"r");
    if (fich == NULL){
        return 0;
    }
    while(fgets(phrase, BLOC, fich) != NULL){
        mot = strtok(phrase," \n,;:.?!\"()-’'");
        while(mot != NULL){
            ajout(A,mot);
            mot = strtok(NULL, " .'’,\n");
        }
    }
    fclose(fich);
    return 1;

}
